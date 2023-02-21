#include "../headers/params.h"
#include "../ui/ui_params.h"
#include <iostream>
#include <QRegExpValidator>

Params::Params(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Params),
    parametros(new Parametros),
    validator_coef(new QRegExpValidator),
    validator_ent_positivo(new QRegExpValidator),
    validator_proporcion(new QRegExpValidator)
{

    ui->setupUi(this);

    this->conectarSignals();
    this->cargarParametros();
    this->configurarValidadores();

}

void Params::conectarSignals()
{
    connect(ui->btnCargar,      SIGNAL(clicked()), this, SLOT(slotValidarCampos()));
    connect(ui->btnRestablecer, SIGNAL(clicked()), this, SLOT(slotRestablecerCampos()));
}

void Params::cargarParametros()
{
    // Cantidad de Años
    ui->txtCantAnios->setText(tr("%1").arg(parametros->cant_anios));

    // Coeficientes de los dias
    ui->txtCoefSoleado->setText(tr("%1").arg(parametros->coef_soleado));
    ui->txtCoefLluvia->setText(tr("%1").arg(parametros->coef_lluvia));
    ui->txtCoefNublado->setText(tr("%1").arg(parametros->coef_nublado));

    // Coeficiente de la tardanza
    ui->txtCoefTardanza->setText(tr("%1").arg(parametros->coef_tardanza));

    // Seeds para los generadores
    ui->txtSeedClima->setText(tr("%1").arg(parametros->seed_climas));
    ui->txtSeedTardanza->setText(tr("%1").arg(parametros->seed_tardanzas));

    // Probabilidades por cada dia
    ui->Prob_DS_DS->setText(tr("%1").arg(parametros->probs[0][0]));
    ui->Prob_DS_DL->setText(tr("%1").arg(parametros->probs[0][1]));
    ui->Prob_DS_DN->setText(tr("%1").arg(parametros->probs[0][2]));

    ui->Prob_DL_DS->setText(tr("%1").arg(parametros->probs[1][0]));
    ui->Prob_DL_DL->setText(tr("%1").arg(parametros->probs[1][1]));
    ui->Prob_DL_DN->setText(tr("%1").arg(parametros->probs[1][2]));

    ui->Prob_DN_DS->setText(tr("%1").arg(parametros->probs[2][0]));
    ui->Prob_DN_DL->setText(tr("%1").arg(parametros->probs[2][1]));
    ui->Prob_DN_DN->setText(tr("%1").arg(parametros->probs[2][2]));

    // Media de tardanza
    ui->txtMediaTardanza->setText(tr("%1").arg(parametros->media_dias_tardanza_fertilizante));
}

void Params::configurarValidadores()
{
    // Expresiones regulares
    validator_coef          ->setRegExp(QRegExp("[0-9]|[1-9][0-9]*|-[1-9][0-9]*"));
    validator_ent_positivo  ->setRegExp(QRegExp("[1-9][0-9]*"));
    validator_proporcion    ->setRegExp(QRegExp("^[01]|^0\.[0-9]{1,2}$"));

    // Seteo masivo
    ui->txtCantAnios->setValidator(validator_ent_positivo);
    ui->txtCantAnios->setMaxLength(9);

    ui->txtCoefSoleado  ->setValidator(validator_coef);
    ui->txtCoefLluvia   ->setValidator(validator_coef);
    ui->txtCoefNublado  ->setValidator(validator_coef);
    ui->txtCoefTardanza ->setValidator(validator_coef);

    ui->txtSeedClima    ->setValidator(validator_ent_positivo);
    ui->txtSeedClima    ->setMaxLength(2);

    ui->txtSeedTardanza ->setValidator(validator_ent_positivo);
    ui->txtSeedTardanza ->setMaxLength(2);

    ui->Prob_DS_DS      ->setValidator(validator_proporcion);
    ui->Prob_DS_DL      ->setValidator(validator_proporcion);
    ui->Prob_DS_DN      ->setValidator(validator_proporcion);

    ui->Prob_DL_DS      ->setValidator(validator_proporcion);
    ui->Prob_DL_DL      ->setValidator(validator_proporcion);
    ui->Prob_DL_DN      ->setValidator(validator_proporcion);

    ui->Prob_DN_DS      ->setValidator(validator_proporcion);
    ui->Prob_DN_DL      ->setValidator(validator_proporcion);
    ui->Prob_DN_DN      ->setValidator(validator_proporcion);

    ui->txtMediaTardanza->setValidator(validator_ent_positivo);
    ui->txtMediaTardanza->setMaxLength(3);



}

bool Params::validar()
{
    QLineEdit *lista_campos[] = {
        ui->txtCantAnios,
        ui->txtCoefSoleado,
        ui->txtCoefLluvia,
        ui->txtCoefNublado,
        ui->txtCoefTardanza,
        ui->txtSeedClima,
        ui->txtSeedTardanza,
        ui->Prob_DS_DS,
        ui->Prob_DS_DL,
        ui->Prob_DS_DN,
        ui->Prob_DL_DS,
        ui->Prob_DL_DL,
        ui->Prob_DL_DN,
        ui->Prob_DN_DS,
        ui->Prob_DN_DL,
        ui->Prob_DN_DN
    };

    for(int i=0; i < 16; i++){
        if(!lista_campos[i]->hasAcceptableInput()){
            return false;
        }
    }

    float total_prob_DS =
            ui->Prob_DS_DS->text().toFloat() +
            ui->Prob_DS_DL->text().toFloat() +
            ui->Prob_DS_DN->text().toFloat();

    float total_prob_DL =
            ui->Prob_DL_DS->text().toFloat() +
            ui->Prob_DL_DL->text().toFloat() +
            ui->Prob_DL_DN->text().toFloat();

    float total_prob_DN =
            ui->Prob_DN_DS->text().toFloat() +
            ui->Prob_DN_DL->text().toFloat() +
            ui->Prob_DN_DN->text().toFloat();

    if (total_prob_DS != 1.0f ||
        total_prob_DL != 1.0f ||
        total_prob_DN != 1.0f){

        return false;
    }

    return true;
}

void Params::guardarParametros()
{
    parametros->cant_anios      = ui->txtCantAnios->text().toInt();

    parametros->coef_soleado    = ui->txtCoefSoleado->text().toInt();
    parametros->coef_lluvia     = ui->txtCoefLluvia->text().toInt();
    parametros->coef_nublado    = ui->txtCoefNublado->text().toInt();
    parametros->coef_tardanza   = ui->txtCoefTardanza->text().toInt();

    parametros->seed_climas     = ui->txtSeedClima->text().toInt();
    parametros->seed_tardanzas  = ui->txtSeedTardanza->text().toInt();

    parametros->probs[0][0] = ui->Prob_DS_DS->text().toFloat();
    parametros->probs[0][1] = ui->Prob_DS_DL->text().toFloat();
    parametros->probs[0][2] = ui->Prob_DS_DN->text().toFloat();

    parametros->probs[1][0] = ui->Prob_DL_DS->text().toFloat();
    parametros->probs[1][1] = ui->Prob_DL_DL->text().toFloat();
    parametros->probs[1][2] = ui->Prob_DL_DN->text().toFloat();

    parametros->probs[2][0] = ui->Prob_DN_DS->text().toFloat();
    parametros->probs[2][1] = ui->Prob_DN_DL->text().toFloat();
    parametros->probs[2][2] = ui->Prob_DN_DN->text().toFloat();

    parametros->media_dias_tardanza_fertilizante = ui->txtMediaTardanza->text().toInt();
}

void Params::slotValidarCampos()
{
    bool entradas_validas = this->validar();
    if(entradas_validas){
        this->guardarParametros();
        ui->msgEstado->setText("Parametros Guardados");
    }
    else {
        ui->msgEstado->setText("Entradas Invalidas.");
    }

}

void Params::slotRestablecerCampos()
{
    this->restablecer();
}

Params::~Params()
{
    delete ui;
    delete parametros;
    delete validator_coef;
    delete validator_ent_positivo;
    delete validator_proporcion;
}

void Params::restablecer()
{
    parametros->setValoresPorDefecto();
    this->cargarParametros();
    ui->msgEstado->setText("Parametros Reestablecidos");
}
