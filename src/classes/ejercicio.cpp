#include "../headers/ejercicio.h"
#include "../ui/ui_ejercicio.h"

Ejercicio::Ejercicio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ejercicio)
{
    ui->setupUi(this);
}

Ejercicio::~Ejercicio()
{
    delete ui;
}
