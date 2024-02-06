#ifndef MODELO_H
#define MODELO_H

#include <QString>

class Modelo
{
public:
    Modelo();
    Modelo(const QString &nombre, const QString &apellido, float nota1, float nota2);

    const QString &nombre() const;
    void setNombre(const QString &newNombre);
    const QString &apellido() const;
    void setApellido(const QString &newApellido);
    int nota1() const;
    void setNota1(int newNota1);
    int nota2() const;
    void setNota2(int newNota2);

    QString to_string();
private:
    QString m_nombre;
    QString m_apellido;
    int  m_nota1;
    int m_nota2;
};

#endif // MODELO_H
