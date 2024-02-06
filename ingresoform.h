#ifndef INGRESOFORM_H
#define INGRESOFORM_H

#include <QWidget>
#include <QMessageBox>
#include <QDialog>

#include <modelo.h>



namespace Ui {
class IngresoForm;
}

class IngresoForm : public QDialog
{
    Q_OBJECT

public:
    explicit IngresoForm(QWidget *parent = nullptr);
    ~IngresoForm();
signals:
    void datosIngresados(Modelo *modelo);
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::IngresoForm *ui;
};

#endif // INGRESOFORM_H
