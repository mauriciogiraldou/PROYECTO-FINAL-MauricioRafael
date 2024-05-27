#include "barquitoenemigo.h"

Barquitoenemigo::Barquitoenemigo(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    QPixmap pixmap(":/imagenes/barquito enemigo.png");
    setPixmap(pixmap);
    setScale(0.40);
    int random_number = rand() % 600;
    setPos(1220, random_number);

    // Temporizador para mover el enemigo
    moveTimer = new QTimer(this);
    connect(moveTimer, &QTimer::timeout, this, &Barquitoenemigo::move);
    moveTimer->start(50);
}

void Barquitoenemigo::move()
{
    setPos(x() - velocidad, y());
    if (pos().x() < 0) {
        scene()->removeItem(this);
        delete this;
        qDebug() << "Se elimina el barquito enemigo";
    }
}
