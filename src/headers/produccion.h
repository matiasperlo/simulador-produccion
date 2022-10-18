#ifndef PRODUCCION_H
#define PRODUCCION_H


class Produccion
{
    float independiente;
    float coef_soleado;
    float coef_lluvia;
    float coef_nublado;
    float coef_tardanza;
public:
    Produccion(float tindependiente,
               float csoleado,
               float clluvia,
               float cnublado,
               float ctardanza);

   float calcular();
};

#endif // PRODUCCION_H
