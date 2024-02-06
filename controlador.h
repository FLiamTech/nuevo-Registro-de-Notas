#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <modelo.h>

class Controlador
{
public:
    Controlador();
    QString estado(Modelo *modelo);
    float notaMin(Modelo *modelo);

    int notaFinal(Modelo *modelo);
private:
    Modelo m_estudiante;
};

#endif // CONTROLADOR_H
