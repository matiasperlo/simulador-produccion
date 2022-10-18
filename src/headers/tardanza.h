#ifndef TARDANZA_H
#define TARDANZA_H


class Tardanza
{
    float generator_rnd = 2.0;
    float rnd_tardanza = 0.5;
    float dias_media;
    float dias_tardanza;
public:
    Tardanza(float generador, float dias_media);

    float getTardanza();
    float getRndTardanza();
};

#endif // TARDANZA_H
