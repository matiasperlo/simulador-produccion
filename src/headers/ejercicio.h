#ifndef EJERCICIO_H
#define EJERCICIO_H

#include <QWidget>

namespace Ui {
class Ejercicio;
}

class Ejercicio : public QWidget
{
    Q_OBJECT

public:
    explicit Ejercicio(QWidget *parent = nullptr);
    ~Ejercicio();

private:
    Ui::Ejercicio *ui;
};

#endif // EJERCICIO_H
