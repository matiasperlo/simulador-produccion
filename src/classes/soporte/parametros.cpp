#include "../../headers/parametros.h"

Parametros::Parametros()
{
    this->setValoresPorDefecto();
}

void Parametros::setValoresPorDefecto()
{
    cant_anios = 40;

    coef_soleado = 250;
    coef_lluvia = 390;
    coef_nublado = -150;

    coef_tardanza = -600;

    seed_climas = 7;
    seed_tardanzas = 17;

    prob_despues_de_dia_soleado[0] = 0.8f;
    prob_despues_de_dia_soleado[1] = 0.1f;
    prob_despues_de_dia_soleado[2] = 0.1f;

    prob_despues_de_dia_lluvia[0] = 0.4f;
    prob_despues_de_dia_lluvia[1] = 0.2f;
    prob_despues_de_dia_lluvia[2] = 0.4f;

    prob_despues_de_dia_nublado[0] = 0.6f;
    prob_despues_de_dia_nublado[1] = 0.1f;
    prob_despues_de_dia_nublado[2] = 0.3f;

    media_dias_tardanza_fertilizante = 3;

}
