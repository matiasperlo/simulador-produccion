#include "../../headers/produccion.h"

Produccion::Produccion(float tindependiente,
                       float csoleado,
                       float clluvia,
                       float cnublado,
                       float ctardanza)
{
    independiente = tindependiente;
    coef_soleado = csoleado;
    coef_lluvia = clluvia;
    coef_nublado = cnublado;
    coef_tardanza = ctardanza;
}

float Produccion::calcular(){
    return 0.0;
}
