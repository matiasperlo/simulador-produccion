#include "../headers/params.h"
#include "../ui/ui_params.h"

Params::Params(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Params)
{
    ui->setupUi(this);

    connect(ui->btnCargar, SIGNAL(clicked()), this, SLOT(slotValidarCampos()));
    connect(ui->btnRestablecer, SIGNAL(clicked()), this, SLOT(slotRestablecerCampos()));
}

Params::~Params()
{
    delete ui;
}

void Params::slotValidarCampos()
{
    ui->msgEstado->setText("Parametros Guardados");
}

void Params::slotRestablecerCampos()
{

}
