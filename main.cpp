#include "registro.h"
#include <modelo.h>
#include <registro.h>

#include <QApplication>
#include <QDebug>
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator traduccion;
    QStringList idiomas;
    idiomas << "Spanish" <<"Italian";

    QString idiomaSeleccionado = QInputDialog::getItem(NULL,
                                                       "language",
                                                       "Select an Lenguage",
                                                       idiomas);
    if(idiomaSeleccionado=="Italian"){
        traduccion.load(":/it_it.qm");
    }

    if(idiomaSeleccionado != "Spanish"){
        a.installTranslator(&traduccion);
    }

    Registro w;
    w.show();
    return a.exec();
}
