#ifndef PARAMETROS_H
#define PARAMETROS_H


class Parametros
{
public:
    Parametros();
    void setValoresPorDefecto();

    // Años que se calculan.
    int cant_anios;

    // Coeficientes para los tipos de dias.
    int coef_soleado;
    int coef_lluvia;
    int coef_nublado;

    // Coeficientes para la tardanza.
    int coef_tardanza;

    // Seeds para los generadores de números.
    int seed_climas;
    int seed_tardanzas;

    // Probabilidad exhaustiva de los tipos de días.
    float prob_despues_de_dia_soleado[3];
    float prob_despues_de_dia_lluvia [3];
    float prob_despues_de_dia_nublado[3];

    // Media de días de tardanza del fertilizante.
    float media_dias_tardanza_fertilizante = 0;



};

#endif // PARAMETROS_H
