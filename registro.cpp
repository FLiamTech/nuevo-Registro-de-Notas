#include "registro.h"
#include "ui_registro.h"

Registro::Registro(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Registro)
{
    ui->setupUi(this);
    ui->tblCuadroNot->setColumnCount(7);
    QStringList titulo;
    titulo << tr("Nombre") << tr("Apellido") << tr("Nota 1") << tr("Nota 2") << tr("Nota Final") << tr("Estado") << tr("Nota Min");
    ui->tblCuadroNot->setHorizontalHeaderLabels(titulo);
    cargar();
}

Registro::~Registro()
{
    delete ui;
}

void Registro::actualizarTabla()
{
    ui->tblCuadroNot->clearContents();
    ui->tblCuadroNot->setRowCount(0);

    foreach (Modelo *modelo, modelosIngresados)
    {
        float notaFinal = controlador.notaFinal(modelo);
        float notaMin = controlador.notaMin(modelo);
        QString estado = controlador.estado(modelo);

        int fila = ui->tblCuadroNot->rowCount();
        ui->tblCuadroNot->insertRow(fila);

        ui->tblCuadroNot->setItem(fila, 0, new QTableWidgetItem(modelo->nombre()));
        ui->tblCuadroNot->setItem(fila, 1, new QTableWidgetItem(modelo->apellido()));
        ui->tblCuadroNot->setItem(fila, 2, new QTableWidgetItem(QString::number(modelo->nota1())));
        ui->tblCuadroNot->setItem(fila, 3, new QTableWidgetItem(QString::number(modelo->nota2())));
        ui->tblCuadroNot->setItem(fila, 4, new QTableWidgetItem(QString::number(notaFinal)));
        ui->tblCuadroNot->setItem(fila, 5, new QTableWidgetItem(estado));
        if(notaFinal < 70 && notaFinal > 25)
        {
            ui->tblCuadroNot->setItem(fila, 6, new QTableWidgetItem(QString::number(notaMin)));
        }
        else if(notaFinal < 25)
        {
            ui->tblCuadroNot->setItem(fila, 6, new QTableWidgetItem(tr("Imposibe")));
        }
        else
        {
            ui->tblCuadroNot->setItem(fila, 6, new QTableWidgetItem("0"));
        }

    }
}

void Registro::guardar()
{
    QString rutaArchivo = QFileDialog::getSaveFileName(this, tr("Guardar Datos"), QDir::homePath(), tr("Archivos CSV (*.csv)"));

    if(!rutaArchivo.isEmpty())
    {
        QFile archivo(rutaArchivo);

        if (archivo.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream salida(&archivo);

            // Escribir encabezados
            salida << tr("Nombre,Apellido,Nota1,Nota2,NotaFinal,Estado\n");

            // Escribir datos
            foreach (Modelo *modelo, modelosIngresados)
            {
                float notaFinal = controlador.notaFinal(modelo);
                QString estado = controlador.estado(modelo);

                salida << modelo->nombre() << ","
                       << modelo->apellido() << ","
                       << modelo->nota1() << ","
                       << modelo->nota2() << ","
                       << notaFinal << ","
                       << estado << "\n";
            }

            archivo.close();
        }
        else
        {
            QMessageBox::warning(this, tr("Guardar"), tr("No se pudo guardar los datos"));
        }
    }

}

void Registro::cargar()
{
    QFile archivo("datos.csv");

    if (archivo.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream entrada(&archivo);
        entrada.readLine();
        modelosIngresados.clear();

        while (!entrada.atEnd())
        {
            QString linea = entrada.readLine();
            QStringList campos = linea.split(',');

            if (campos.size() == 6)
            {
                QString nombre = campos[0];
                QString apellido = campos[1];
                int nota1 = campos[2].toInt();
                int nota2 = campos[3].toInt();

                Modelo *modelo = new Modelo(nombre, apellido, nota1, nota2);
                modelosIngresados.append(modelo);
            }
        }

        actualizarTabla();
        archivo.close();
    }
    else
    {
        QMessageBox::warning(this, tr("Guardar"), tr("No se pudo cargar los datos"));
    }
}

void Registro::manejarDatosIngresados(Modelo *modelo)
{
    modelosIngresados.append(modelo);
    actualizarTabla();
    // guardar();
}


void Registro::on_actionIngreso_Estudiante_triggered()
{
    IngresoForm *w = new IngresoForm(this);
    connect(w, &IngresoForm::datosIngresados, this, &Registro::manejarDatosIngresados);

    w->show();
}


void Registro::on_actionRepositorio_triggered()
{
    AcercaDeForm *w = new AcercaDeForm(this);

    w->show();
}


void Registro::on_pushButton_released()
{
    guardar();
}


void Registro::on_actionSalir_triggered()
{
    int opcion = QMessageBox::question(this, tr("Salir del programa"), tr("¿Estas seguro de que quieres salir del programa?"), QMessageBox::Yes | QMessageBox::No);
    if(opcion == QMessageBox::Yes)
    {
        qApp->quit();
    }
}

