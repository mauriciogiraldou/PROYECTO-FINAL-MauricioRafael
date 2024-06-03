#include "jefefinal.h"
#include "jefeproyectil.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include "barquito.h"

JefeFinal::JefeFinal(QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent), direccion(1), vida(400) {
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
    collisionTimer = new QTimer(this);
    connect(collisionTimer, &QTimer::timeout, this, &JefeFinal::checkCollisions);
    collisionTimer->start(100);  // Comprobar colisiones cada 100 ms
}

void JefeFinal::move() {
    double step = 4.5;
    if (direccion == 1) {
        setPos(x(), y() + step);
        if (y() + pixmap().height() >= 1100) {
            direccion = -1;
        }
    } else if (direccion == -1) {
        setPos(x(), y() - step);
        if (y() <= -280) {
            direccion = 1;
        }
    }
}

void JefeFinal::shoot() {
    JefeProyectil *bullet = new JefeProyectil();
    bullet->setPos(x() + 15, y() + 240);
    scene()->addItem(bullet);
    //qDebug() << "Jefe disparando";
}

void JefeFinal::checkCollisions() {
    QList<QGraphicsItem *> collidingItems = scene()->collidingItems(this);
    for (QGraphicsItem *item : collidingItems) {
        Barquito *barquito = dynamic_cast<Barquito *>(item);
        if (barquito) {
            barquito->reducirVidas();
            // No eliminar al jefe final tras la colisión
            return;
        }
    }
}
void JefeFinal::recibirDisparo() {
    vida -= 1;
    //qDebug() << "Jefe recibiendo disparo";
    if (vida <= 0) {
        emit jefeDerrotado();
        scene()->removeItem(this);
        delete this;
        //qDebug() << "Jefe final destruido";
    }
}

int JefeFinal::getVida() const {
    return vida;
}
