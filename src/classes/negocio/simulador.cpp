#include "../../headers/simulador.h"
#include <iostream>
#include <random>
#include <cmath>


Simulador::Simulador(Parametros *params):
    params(params)
{
    this->reset();
}

/*
    Funcion que realiza una iteracion de la simulacion.
    Devuelve todos los datos necesarios para conocer
    el estado actual de la ejecucion de la simulacion.
*/
vectorEstado Simulador::ejecutarSimulacion()
{
    // distribucion uniforme [0, 1] float
    std::uniform_real_distribution<float> dist_uniforme(0, 1);

    // variables
    vectorEstado ve;
    int contador_climas[3] = {0, 0, 0};

    // incremento de año
    anio_actual++;
    ve.anio = anio_actual;

    // calculo primer dia
    ve.dias[0].id        = 1;
    ve.dias[0].rnd_clima = dist_uniforme(this->rnd_climas);
    ve.dias[0].clima     = get_indice_prob(this->params->probs_primer_dia, ve.dias[0].rnd_clima);
    contador_climas[ve.dias[0].clima]++;

    // calculo del resto de dias
    for (int i = 1; i < 10; i++){
        ve.dias[i].id           = i+1;
        ve.dias[i].rnd_clima    = dist_uniforme(this->rnd_climas);
        ve.dias[i].clima        = get_indice_prob(
                                    this->params->probs[ve.dias[i-1].clima],
                                    ve.dias[i].rnd_clima);
        contador_climas[ve.dias[i].clima]++;
    }

    // registro de cant de dias
    ve.cant_dias_soleado    = contador_climas[0];
    ve.cant_dias_lluviosos  = contador_climas[1];
    ve.cant_dias_nublado    = contador_climas[2];


    // calculo de la tardanza
    ve.rnd_tardanza = dist_uniforme(rnd_tardanzas);
    ve.tardanza     = static_cast<int>(
                - this->params->media_dias_tardanza_fertilizante *
                log(1 - ve.rnd_tardanza));

    // calculo de la produccion total anual
    ve.produccion_total_anual =
            calcularProduccionTotalAnual(
                static_cast<float>(contador_climas[0]) / 10.f,
                static_cast<float>(contador_climas[1]) / 10.f,
                static_cast<float>(contador_climas[2]) / 10.f,
                ve.tardanza
            );

    produccion_total_acumulado += ve.produccion_total_anual;
    ve.produccion_total_anual_ac = produccion_total_acumulado;

    return ve;
}


/*
    En esta funcion se encapsulan todas las variables que deben
    mantener una persistencia para lograr las iteraciones de la
    simulacion y para comenzar iteraciones nuevas.
*/
void Simulador::reset(Parametros *nvparams)
{
    if(nvparams){
        this->params = nvparams;
    }

    this->rnd_climas    = std::mt19937(params->seed_climas);
    this->rnd_tardanzas = std::mt19937(params->seed_tardanzas);

    this->anio_actual = 0;
    this->produccion_total_acumulado = 0;
}

int Simulador::get_indice_prob(float probs[], float rnd){
    float prob_ac = 0.f;

    float num1 = probs[0];
    float num2 = probs[1];
    float num3 = probs[2];

    for (int i=0; i<3; i++){
        prob_ac += probs[i];
        if (rnd < prob_ac){
            return i;
        }
    }
    return 2;
}


/*
    La funcion encapsula el calculo completo para la produccion
    anual que se obtiene en cada iteracion.
*/
double Simulador::calcularProduccionTotalAnual(
        float prob_soleado,
        float prob_lluvioso,
        float prob_nublado,
        int   dias_tardanza
        )
{
    Parametros *prm = this->params;
    return  3350.f +
            prm->coef_soleado   * prob_soleado  +
            prm->coef_lluvia    * prob_lluvioso +
            prm->coef_nublado   * prob_nublado  +
            prm->coef_tardanza  * dias_tardanza
            ;
}
