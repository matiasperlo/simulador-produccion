#include "../headers/mainwindow.h"
#include "../ui/ui_mainwindow.h"
#include <iostream>
#include <QRegExpValidator>

// Constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , vtnParams(new Params)
    , vtnEjercicio(new Ejercicio)
    , validatorIrA(new QRegExpValidator)

{
    ui->setupUi(this);
    this->configurarTabla();

    connect(ui->actionGenerar_Simulacion,      SIGNAL(triggered()), this, SLOT(slotGenerarSimulacion()));
    connect(ui->actionConfigurar_Parametros,   SIGNAL(triggered()), this, SLOT(slotConfigurarParametros()));
    connect(ui->actionLimpiarContenido,        SIGNAL(triggered()), this, SLOT(slotLimpiarContenido()));
    connect(ui->actionSobre_El_Ejercicio,      SIGNAL(triggered()), this, SLOT(slotSobreElEjercicio()));

    QRegExp expresion("[1-9][0-9]*");
    validatorIrA->setRegExp(expresion);

    connect(ui->btnIr, SIGNAL(clicked()), this, SLOT(slotIrA));
    ui->txtIrA->setValidator(validatorIrA);

    this->deshabilitarIrA();

}

void MainWindow::configurarTabla()
{
    // clima de los dias
    ui->tablaHeader->setSpan(0, 1, 1, 20);

    // total de dias por clima
    ui->tablaHeader->setSpan(0, 21, 1, 3);

    // tardanza del fertilizante
    ui->tablaHeader->setSpan(0, 24, 1, 2);

    // produccion anual
    ui->tablaHeader->setSpan(0, 26, 1, 2);
}

void MainWindow::habilitarIrA()
{
    ui->txtIrA->setEnabled(true);
    ui->btnIr->setEnabled(true);
}

void MainWindow::deshabilitarIrA()
{
    ui->txtIrA->setEnabled(false);
    ui->btnIr->setEnabled(false);
}

// Btn Generar la Simulacion
void MainWindow::slotGenerarSimulacion()
{
    this->slotLimpiarContenido();
    std::cout << "Hello Simulacion!\n";

    this->habilitarIrA();
}


// Btn Configurar los parametros
void MainWindow::slotConfigurarParametros()
{
    this->vtnParams->show();
}


// Btn Limpiar los resultados
void MainWindow::slotLimpiarContenido()
{
    ui->tablaResultados->setRowCount(0);
    this->deshabilitarIrA();
}


// Btn ver la consigna del ejercicio
void MainWindow::slotSobreElEjercicio()
{
    this->vtnEjercicio->show();
}

void MainWindow::slotIrA()
{
    if (ui->txtIrA->text().isEmpty()){
        return ;
    }

    int fila = ui->txtIrA->text().toInt();
    if ( fila > ui->tablaResultados->rowCount()){
        return ;
    }

    ui->tablaResultados->scrollToItem(ui->tablaResultados->item(fila - 1, 0));
}

// Destructor del MainWindow
MainWindow::~MainWindow()
{
    delete ui;
    delete vtnEjercicio;
    delete vtnParams;
    delete validatorIrA;

}

void MainWindow::setParametros(Parametros *params)
{
    this->parametros = params;
}

