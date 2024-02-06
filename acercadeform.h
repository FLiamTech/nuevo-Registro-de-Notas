#ifndef ACERCADEFORM_H
#define ACERCADEFORM_H

#include <QWidget>
#include <QUrl>
#include <QDesktopServices>
#include <QDialog>

#include <QString>

namespace Ui {
class AcercaDeForm;
}

class AcercaDeForm : public QDialog
{
    Q_OBJECT

public:
    explicit AcercaDeForm(QWidget *parent = nullptr);
    ~AcercaDeForm();

private slots:
    void on_pushButton_released();

    void on_pushButton_2_released();

private:
    Ui::AcercaDeForm *ui;
};

#endif // ACERCADEFORM_H
