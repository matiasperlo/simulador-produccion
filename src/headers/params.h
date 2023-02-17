#ifndef PARAMS_H
#define PARAMS_H

#include "parametros.h"
#include <QRegExpValidator>
#include <QIntValidator>
#include <QWidget>

namespace Ui {
class Params;
}

class Params : public QWidget
{
    Q_OBJECT

public:
    explicit Params(QWidget *parent = nullptr);
    ~Params();

    void restablecer();


public slots:
    void slotValidarCampos();
    void slotRestablecerCampos();

private:
    Ui::Params *ui;

    Parametros *parametros;
    QRegExpValidator *validator_coef;
    QRegExpValidator *validator_ent_positivo;
    QRegExpValidator *validator_proporcion;

    void conectarSignals();
    void cargarParametros();
    void configurarValidadores();
    bool validar();
    void guardarParametros();
};

#endif // PARAMS_H
