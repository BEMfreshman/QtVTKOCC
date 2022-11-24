#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class OCCView;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();

    void on_actionExit_triggered();

private:
    // void makeBox();
    // void makeSphere();

private:
    Ui::MainWindow* ui;;

    OCCView* m_OCCView;
};
#endif // MAINWINDOW_H
