#ifndef SIMULADOR_H
#define SIMULADOR_H

#include <iostream>
#include <random>
#include "parametros.h"

// structs
struct dia {
    public:

        // dia
        int id;

        // 0-> soleado, 1->lluvioso, 2->nublado
        int clima;

        // el rnd generado por el generador [0, 1]
        float rnd_clima;
};

struct vectorEstado
{
public:

    int anio                            = 0;
    dia dias[10];
    int tardanza                        = 0;
    int cant_dias_soleado               = 0;
    int cant_dias_lluviosos             = 0;
    int cant_dias_nublado               = 0;
    float rnd_tardanza                  = 0.f;
    double produccion_total_anual       = 0.0;
    double produccion_total_anual_ac    = 0.0;

};

class Simulador
{
public:
    Simulador(Parametros *params);

    static void ejecutarPrueba(){
        std::mt19937 rnd_gen1(1);
        std::mt19937 rnd_gen2(1);
        std::uniform_real_distribution<double> dist_uniforme(0, 1);

        std::cout << "uniforme: rnd_gen1" << std::endl;
        for (int i=0; i<10; i++){
            std::cout << rnd_gen1() << std::endl;
        }

        std::cout << "uniforme: rnd_gen2" << std::endl;
        for (int i=0; i<10; i++){
            std::cout << rnd_gen2() << std::endl;
        }
    }

    vectorEstado ejecutarSimulacion();
    void reset(Parametros *params = nullptr);

private:
    Parametros *params;

    std::mt19937 rnd_climas;
    std::mt19937 rnd_tardanzas;

    int anio_actual;
    double produccion_total_acumulado;

    double calcularProduccionTotalAnual(
            float prob_soleado,
            float prob_lluvioso,
            float prob_nublado,
            int   dias_tardanza
            );

    int get_indice_prob(float probs[], float rnd);
};

#endif // SIMULADOR_H
