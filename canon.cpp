#include "canon.h"
#include <QPixmap>
#include <QGraphicsScene>
#include "proyectilenemigocanon.h"
Canon::Canon(QGraphicsItem *parent)
    : QObject(), QGraphicsPixmapItem(parent) {
    QPixmap pixmap(":/imagenes/orban_canon.png");
    setPixmap(pixmap);
    QTimer *shootTimer = new QTimer(this);
    connect(shootTimer, &QTimer::timeout, this, &Canon::shoot);
    shootTimer->start(15000);
}
void Canon::shoot() {
    ProyectilEnemigoCanon *proyectil = new ProyectilEnemigoCanon();
    proyectil->setPos(x()+25, y()+130 );
    scene()->addItem(proyectil);
}
