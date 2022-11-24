#include <QFileDialog>

#include "mainwindow.h"

#include "occview.h"
#include "ui_mainwindow.h"

#include <QDockWidget>

// #include <TopoDS.hxx>
// #include <TopExp.hxx>
// #include <TopExp_Explorer.hxx>

// #include <BRepLib.hxx>
// #include <BRepPrimAPI_MakeBox.hxx>
// #include <BRepPrimAPI_MakeSphere.hxx>

// #include <AIS_Shape.hxx>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_OCCView = new OCCView(this);

    setCentralWidget(m_OCCView);

    //makeBox();
    //makeSphere();

    m_OCCView->fitAll();
}

MainWindow::~MainWindow()
{
     delete ui;
}

// void MainWindow::makeBox() {
//     TopoDS_Shape aTopoBox = BRepPrimAPI_MakeBox(0.3,0.4,0.5).Shape();
//     Handle(AIS_Shape) anAisBox = new AIS_Shape(aTopoBox);

//     anAisBox->SetColor(Quantity_NOC_AZURE);

//     m_OCCView->getContext()->Display(anAisBox,Standard_True);
// }

// void MainWindow::makeSphere() {
//     gp_Ax2 anAxis;
//     anAxis.SetLocation(gp_Pnt(0.0, 20.0, 0.0));

//     TopoDS_Shape aTopoSphere = BRepPrimAPI_MakeSphere(anAxis, 3.0).Shape();
//     Handle(AIS_Shape) anAisSphere = new AIS_Shape(aTopoSphere);

//     anAisSphere->SetColor(Quantity_NOC_BLUE1);

//     m_OCCView->getContext()->Display(anAisSphere, Standard_True);
// }


void MainWindow::on_actionOpen_triggered()
{
    QFileDialog* fileDialog = new QFileDialog(this);

    fileDialog->setWindowTitle(QStringLiteral("Open BDF file"));
    fileDialog->setNameFilter(tr("File(*.bdf* *.fem* *.dat* *.nas*)"));
    fileDialog->setFileMode(QFileDialog::ExistingFiles);

    fileDialog->setViewMode(QFileDialog::Detail);

    QStringList  filenames;

    if (fileDialog->exec()) {
        filenames = fileDialog->selectedFiles();
    }

    //qDebug() << filenames;

    QString fullpath = filenames.at(0);

    QFileInfo fileInfo = QFileInfo(fullpath);
    QString fileName = fileInfo.fileName();
    QString filePath = fileInfo.absolutePath();

    m_OCCView->load(filePath.toStdString(),fileName.toStdString());
}


void MainWindow::on_actionExit_triggered()
{

}

