//#include "mainwindow.h"

#include <QApplication>
#include "occview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OCCView v;
    v.show();
    return a.exec();
}
