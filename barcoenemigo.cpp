#include "barcoenemigo.h"
#include "proyectilenemigo.h"
#include "barquito.h"

Barcoenemigo::Barcoenemigo(QGraphicsItem *parent)
    : QObject(), QGraphicsPixmapItem(parent),vida(10) {
    QPixmap pixmap(":/imagenes/barco enemigo.png");
    setPixmap(pixmap);
    setScale(0.40);
    int random_number = rand() % 560;
    setPos(1080, random_number);

    QTimer *shootTimer = new QTimer(this);
    connect(shootTimer, &QTimer::timeout, this, &Barcoenemigo::shoot);
    shootTimer->start(2900); // Ajustar el intervalo de disparo según sea necesario
    collisionTimer = new QTimer(this);
    connect(collisionTimer, &QTimer::timeout, this, &Barcoenemigo::checkCollisions);
    collisionTimer->start(100); // Comprobar colisiones cada 100 ms
}

void Barcoenemigo::recibirDisparo() {
    vida--;
    if (vida <= 0) {
        scene()->removeItem(this);
        delete this;
    }
}


void Barcoenemigo::shoot() {
    ProyectilEnemigo *proyectil = new ProyectilEnemigo();
    proyectil->setPos(x()-35, y() + 130);
    scene()->addItem(proyectil);
}
void Barcoenemigo::checkCollisions() {
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
