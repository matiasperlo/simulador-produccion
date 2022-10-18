#include "../../headers/tardanza.h"

Tardanza::Tardanza(float generador, float dias_media)
{
    generator_rnd = generador;
    this->dias_media = dias_media;

}

float Tardanza::getTardanza(){
    return this->dias_tardanza;
}

float Tardanza::getRndTardanza(){
    return this->rnd_tardanza;
}
