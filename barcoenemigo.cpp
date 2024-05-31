#include "barcoenemigo.h"
#include "proyectilenemigo.h"

Barcoenemigo::Barcoenemigo(QGraphicsItem *parent)
    : QObject(), QGraphicsPixmapItem(parent),vida(25) {
    QPixmap pixmap(":/imagenes/barco enemigo.png");
    setPixmap(pixmap);
    setScale(0.40);
    int random_number = rand() % 560;
    setPos(1080, random_number);

    QTimer *shootTimer = new QTimer(this);
    connect(shootTimer, &QTimer::timeout, this, &Barcoenemigo::shoot);
    shootTimer->start(3150); // Ajustar el intervalo de disparo según sea necesario
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
