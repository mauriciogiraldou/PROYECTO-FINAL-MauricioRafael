#include "proyectilenemigocanon.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>

ProyectilEnemigoCanon::ProyectilEnemigoCanon(QGraphicsItem *parent)
    : QObject(), QGraphicsPixmapItem(parent) {
    setScale(0.40);
    QPixmap pixmap(":/imagenes/bodoque_piedra2.png");
    setPixmap(pixmap);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move2()));
    timer->start(50);
}

void ProyectilEnemigoCanon::move2() {
    setPos(x(), y() + 9); // Mover a lo largo de la Y positiva
    // Si el proyectil sale de la pantalla, eliminarlo
    if (pos().y() > 600) { // Ajustar según el tamaño de la pantalla
        qDebug()<<"me sali";
        scene()->removeItem(this);
        delete this;
    }
}
