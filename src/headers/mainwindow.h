#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "params.h"
#include "ejercicio.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setParametros(Parametros *params);


public slots:
    void slotGenerarSimulacion();
    void slotConfigurarParametros();
    void slotLimpiarContenido();
    void slotSobreElEjercicio();
    void slotIrA();

private:
    Ui::MainWindow *ui;
    Params *vtnParams;
    Parametros *parametros;
    Ejercicio *vtnEjercicio;
    QRegExpValidator *validatorIrA;

    void configurarTabla();
    void habilitarIrA();
    void deshabilitarIrA();
};
#endif // MAINWINDOW_H
