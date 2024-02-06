// https://github.com/FLiamTech/Registro-de-Notas


#ifndef REGISTRO_H
#define REGISTRO_H

#include <QMainWindow>
#include <QList>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
#include <QDir>

#include<controlador.h>
#include <ingresoform.h>
#include <modelo.h>
#include <acercadeform.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Registro; }
QT_END_NAMESPACE

class Registro : public QMainWindow
{
    Q_OBJECT

public:
    Registro(QWidget *parent = nullptr);
    ~Registro();

    void actualizarTabla();

    void guardar();
    void cargar();
public slots:
    void manejarDatosIngresados(Modelo *modelo);
private slots:
    void on_actionIngreso_Estudiante_triggered();

    void on_actionRepositorio_triggered();

    void on_pushButton_released();

    void on_actionSalir_triggered();

private:
    Ui::Registro *ui;

    QList<Modelo*> modelosIngresados;
    Controlador controlador;
};
#endif // REGISTRO_H
