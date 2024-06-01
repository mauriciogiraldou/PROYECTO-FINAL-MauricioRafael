#include "jefefinal.h"
#include "jefeproyectil.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>

JefeFinal::JefeFinal(QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent), direccion(1), vida(600) {
    QPixmap pixmap(":/imagenes/Barco jefe.png");
    setPixmap(pixmap);
    setScale(0.68);
    setPos(798, 40);

    QTimer *moveTimer = new QTimer(this);
    connect(moveTimer, &QTimer::timeout, this, &JefeFinal::move);
    moveTimer->start(50);

    QTimer *shootTimer = new QTimer(this);
    connect(shootTimer, &QTimer::timeout, this, &JefeFinal::shoot);
    shootTimer->start(3000);
}

void JefeFinal::move() {
    double step = 2.5;
    if (direccion == 1) {
        setPos(x(), y() + step);
        if (y() + pixmap().height() >= 950) {
            direccion = -1;
        }
    } else if (direccion == -1) {
        setPos(x(), y() - step);
        if (y() <= 0) {
            direccion = 1;
        }
    }
}

void JefeFinal::shoot() {
    JefeProyectil *bullet = new JefeProyectil();
    bullet->setPos(x() + 15, y() + 240);
    scene()->addItem(bullet);
    qDebug() << "Jefe disparando";
}

void JefeFinal::recibirDisparo() {
    vida -= 1;
    qDebug() << "Jefe recibiendo disparo";
    if (vida <= 0) {
        emit jefeDerrotado();
        scene()->removeItem(this);
        delete this;
        qDebug() << "Jefe final destruido";
    }
}

int JefeFinal::getVida() const {
    return vida;
}
