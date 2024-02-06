#include "acercadeform.h"
#include "ui_acercadeform.h"

AcercaDeForm::AcercaDeForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AcercaDeForm)
{
    ui->setupUi(this);
}

AcercaDeForm::~AcercaDeForm()
{
    delete ui;
}

void AcercaDeForm::on_pushButton_released()
{
    QString URL = "https://github.com/FLiamTech/Registro-de-Notas";

    QDesktopServices::openUrl(QUrl(URL));
}


void AcercaDeForm::on_pushButton_2_released()
{

}

