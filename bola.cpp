#include "bola.h"
#include "barquito.h"
#include <QGraphicsScene>
#include <QDebug>
Bola::Bola(QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent), tiempo(0), velocidadY(0), gravedad(9.8) {
    QPixmap pixmap(":/imagenes/bodoque2.png");
    setPixmap(pixmap);
    setScale(0.50);
    int random_number=rand()%1000;
    setPos(random_number, -80);
    moveTimer = new QTimer(this);
    connect(moveTimer, &QTimer::timeout, this, &Bola::move);
    moveTimer->start(50);
}
void Bola::move() {
    tiempo += 0.038;
    double nuevaY = pos().y() + (velocidadY * tiempo + 0.5 * gravedad * tiempo * tiempo);
    setPos(x(), nuevaY);
    checkCollisions();
    if (pos().y() > 800) {
        scene()->removeItem(this);
        delete this;
    }
}
void Bola::checkCollisions()
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

