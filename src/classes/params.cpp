#include "../headers/params.h"
#include "../ui/ui_params.h"

Params::Params(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Params)
{
    ui->setupUi(this);
}

Params::~Params()
{
    delete ui;
}
