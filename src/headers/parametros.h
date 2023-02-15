#ifndef PARAMETROS_H
#define PARAMETROS_H


class Parametros
{
    float cant_anios = 0;
    float coef_soleado =   0;
    float coef_lluvia =    0;
    float coef_nublado =   0;
    float coef_tardanza =  0;

    int seed_climas =    0;
    int seed_tardanzas = 0;

    // TODO : ver como poronga se manejan las listas.
    //float prob_despues_de_dia_soleado =  [0, 0, 0];
    //float prob_despues_de_dia_lluvia =   [0, 0, 0];
    //float prob_despues_de_dia_nublado =  [0, 0, 0];

    float media_dias_tardanza_fertilizante = 0;

public:
    Parametros();

    Parametros getDefault();
};

#endif // PARAMETROS_H
