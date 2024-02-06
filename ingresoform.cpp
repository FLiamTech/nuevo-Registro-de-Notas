#include "ingresoform.h"
#include "ui_ingresoform.h"

IngresoForm::IngresoForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IngresoForm)
{
    ui->setupUi(this);
}

IngresoForm::~IngresoForm()
{
    delete ui;
}

void IngresoForm::on_buttonBox_accepted()
{
    QString nombre = ui->editNombre->text();
    QString apellido = ui->editApellido->text();
    int nota1 = ui->spnNota1->value();
    int nota2 = ui->spnNota2->value();

    if(nombre.isEmpty())
    {
        QMessageBox::warning(this, tr("Ingreso Estudiante"), tr("El campo del nombre no puede quedar vacio"));
        return;
    }
    if(apellido.isEmpty())
    {
        QMessageBox::warning(this, tr("Ingreso Estudiante"), tr("El campo del apellido no puede quedar vacio"));
        return;
    }
    Modelo *m = new Modelo();
    m->setNombre(nombre);
    m->setApellido(apellido);
    m->setNota1(nota1);
    m->setNota2(nota2);

    emit datosIngresados(m);

    this->close();
}


void IngresoForm::on_buttonBox_rejected()
{
    this->close();
}

