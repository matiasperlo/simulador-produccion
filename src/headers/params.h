#ifndef PARAMS_H
#define PARAMS_H

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

public slots:
    void slotValidarCampos();
    void slotRestablecerCampos();

private:
    Ui::Params *ui;
};

#endif // PARAMS_H
