#include "../../headers/parametros.h"

Parametros::Parametros()
{
    this->setValoresPorDefecto();
}

void Parametros::setValoresPorDefecto()
{
    cant_anios      = 40;

    coef_soleado    = 250;
    coef_lluvia     = 390;
    coef_nublado    = -150;

    coef_tardanza   = -600;

    seed_climas     = 7;
    seed_tardanzas  = 17;

    // Probabilidad en los dias soleados
    probs[0][0] = 0.8f;
    probs[0][1] = 0.1f;
    probs[0][2] = 0.1f;

    // Probabilidad en los dias lluviosos
    probs[1][0] = 0.4f;
    probs[1][1] = 0.2f;
    probs[1][2] = 0.4f;

    // Probabilidad en los dias nublados
    probs[2][0] = 0.6f;
    probs[2][1] = 0.1f;
    probs[2][2] = 0.3f;

    media_dias_tardanza_fertilizante = 3;

}
