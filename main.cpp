#include <vtkAutoInit.h>
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    VTK_MODULE_INIT(vtkRenderingOpenGL2);
    VTK_MODULE_INIT(vtkInteractionStyle);

    QApplication a(argc, argv);
//    OCCView* v = new OCCView();
//
//    QVBoxLayout* layout = new QVBoxLayout();
//    layout->addWidget(v);

    MainWindow w;
    w.setWindowTitle("BDFViewer");
    w.show();
    return a.exec();
}
