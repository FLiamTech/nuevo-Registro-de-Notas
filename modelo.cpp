#include "modelo.h"

Modelo::Modelo()
{

}

const QString &Modelo::nombre() const
{
    return m_nombre;
}

void Modelo::setNombre(const QString &newNombre)
{
    m_nombre = newNombre;
}

const QString &Modelo::apellido() const
{
    return m_apellido;
}

void Modelo::setApellido(const QString &newApellido)
{
    m_apellido = newApellido;
}

int Modelo::nota1() const
{
    return m_nota1;
}

void Modelo::setNota1(int newNota1)
{
    m_nota1 = newNota1;
}

int Modelo::nota2() const
{
    return m_nota2;
}

void Modelo::setNota2(int newNota2)
{
    m_nota2 = newNota2;
}

QString Modelo::to_string()
{
    QString str;
    str = nombre() + apellido() + QString::number(m_nota1) + QString::number(m_nota2);
    return str;
}

Modelo::Modelo(const QString &nombre, const QString &apellido, float nota1, float nota2) : m_nombre(nombre),
    m_apellido(apellido),
    m_nota1(nota1),
    m_nota2(nota2)
{}
