#include "controlador.h"

Controlador::Controlador()
{

}

QString Controlador::estado(Modelo *modelo)
{
    QString estado;
    if(notaFinal(modelo) >= 70)
    {
        estado = "Aprobado";
       return estado;
    }
    else if(notaFinal(modelo) >= 25)
    {
        estado = "Remedial";
        return estado;
    }
    else
    {
        estado = "Reprobado";
        return estado;
    }
}

float Controlador::notaMin(Modelo *modelo)
{
    float notaMin = (70 - 0.6 * notaFinal(modelo)) / 0.4;
    return notaMin;
}

int Controlador::notaFinal(Modelo *modelo)
{
    int nota1 = modelo->nota1();
    int nota2 = modelo->nota2();

    nota1 = nota1 > 50 ? 50 : nota1;
    nota2 = nota2 > 50 ? 50 : nota2;

    int notaFinal = nota1 + nota2;

    notaFinal = notaFinal > 100 ? 100 : notaFinal;

    return notaFinal;
}
