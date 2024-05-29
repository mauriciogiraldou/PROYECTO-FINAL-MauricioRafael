#include "barcoenemigo.h"

Barcoenemigo::Barcoenemigo(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    QPixmap pixmap(":/imagenes/barco enemigo.png");
    setPixmap(pixmap);
    setScale(0.40);
    setPos(0,0);
    int random_number = rand() % 560;
    setPos(1120, random_number);
}
