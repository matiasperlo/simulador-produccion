#include "../headers/mainwindow.h"
#include "../ui/ui_mainwindow.h"
#include <iostream>

// Constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , vtnParams(new Params)

{
    ui->setupUi(this);
    this->configurarTabla();

    QObject::connect(ui->actionGenerar_Simulacion,      SIGNAL(triggered()), this, SLOT(slotGenerarSimulacion()));
    QObject::connect(ui->actionConfigurar_Parametros,   SIGNAL(triggered()), this, SLOT(slotConfigurarParametros()));
    QObject::connect(ui->actionLimpiarContenido,        SIGNAL(triggered()), this, SLOT(slotLimpiarContenido()));
    QObject::connect(ui->actionSobre_El_Ejercicio,      SIGNAL(triggered()), this, SLOT(slotSobreElEjercicio()));
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

// Btn Generar la Simulacion
void MainWindow::slotGenerarSimulacion()
{
    std::cout << "Hello Simulacion!\n";
}


// Btn Configurar los parametros
void MainWindow::slotConfigurarParametros()
{
    this->vtnParams->show();
}


// Btn Limpiar los resultados
void MainWindow::slotLimpiarContenido()
{
    std::cout << "Hello Limpieza!\n";
}


// Btn ver la consigna del ejercicio
void MainWindow::slotSobreElEjercicio()
{
    std::cout << "Hello Ejercicio!\n";
}

// Destructor del MainWindow
MainWindow::~MainWindow()
{
    delete ui;
    delete vtnParams;
}

