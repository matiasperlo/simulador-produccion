#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "params.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:
    void slotGenerarSimulacion();
    void slotConfigurarParametros();
    void slotLimpiarContenido();
    void slotSobreElEjercicio();

private:
    Ui::MainWindow *ui;
    Params *vtnParams;

    void configurarTabla();
};
#endif // MAINWINDOW_H
