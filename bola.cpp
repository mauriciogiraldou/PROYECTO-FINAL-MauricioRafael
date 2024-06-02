#include "bola.h"
#include "barquito.h"
#include <QGraphicsScene>
#include <QDebug>

Bola::Bola(QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent), tiempo(0), velocidadY(0), gravedad(9.8) {
    QPixmap pixmap(":/imagenes/bodoque2.png");
    setPixmap(pixmap);
    setScale(0.70);
    int random_number=rand()%1000;
    setPos(random_number, 0); // Aparecer en una posición aleatoria en la parte superior
    qDebug()<<"se crear la bola";
    moveTimer = new QTimer(this);
    connect(moveTimer, &QTimer::timeout, this, &Bola::move);
    moveTimer->start(50); // Mover cada 50ms
}

void Bola::move() {
    tiempo += 0.025; // Incrementar el tiempo en 0.05 segundos (50ms)
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

