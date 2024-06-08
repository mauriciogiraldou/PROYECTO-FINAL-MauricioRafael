#include "barquitoenemigo.h"
#include "barquito.h"  // Incluir aquí, no en el encabezado

Barquitoenemigo::Barquitoenemigo(QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent), velocidad(6), aceleracion(0.6), tiempoTotal(0)
{
    QPixmap pixmap(":/imagenes/barquito enemigo.png");
    setPixmap(pixmap);
    setScale(0.40);
    int random_number = rand() % 600;
    setPos(1400, random_number);
    // Temporizador para mover el enemigo
    moveTimer = new QTimer(this);
    connect(moveTimer, &QTimer::timeout, this, &Barquitoenemigo::move);
    moveTimer->start(50);
}

void Barquitoenemigo::move()
{
    tiempoTotal += moveTimer->interval() / 1000.0; // Convertir milisegundos a segundos

    // Calcular la nueva posición usando la fórmula del movimiento rectilíneo uniformemente acelerado
    double nueva_x = x() - (velocidad * tiempoTotal + 0.5 * aceleracion * tiempoTotal * tiempoTotal);

    // Actualizar la posición del enemigo
    setPos(nueva_x, y());

    // Chequear colisiones con el barquito
    checkCollisions();

    if (pos().x() < -20) {
        scene()->removeItem(this);
        delete this;
        //qDebug() << "Se elimina el barquito enemigo";
    }
}

void Barquitoenemigo::checkCollisions()
{
    QList<QGraphicsItem *> collidingItems = scene()->collidingItems(this);
    for (QGraphicsItem *item : collidingItems) {
        Barquito *barquito = dynamic_cast<Barquito *>(item);
        if (barquito) {
            barquito->reducirVidas();
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
}
