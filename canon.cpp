#include "canon.h"
#include <QPixmap>
#include <QGraphicsScene>
#include "proyectilenemigocanon.h"
#include <QDebug>

Canon::Canon(QGraphicsItem *parent)
    : QObject(), QGraphicsPixmapItem(parent) {
    QPixmap pixmap(":/imagenes/orban_canon.png");  // Asegúrate de tener esta imagen
    setPixmap(pixmap);
    QTimer *shootTimer = new QTimer(this);
    connect(shootTimer, &QTimer::timeout, this, &Canon::shoot);
    shootTimer->start(15000);
}
void Canon::shoot() {
    ProyectilEnemigoCanon *proyectil = new ProyectilEnemigoCanon();
    // Posicionar el proyectil en la posición actual del cañón
    proyectil->setPos(x()+25, y()+130 );
    scene()->addItem(proyectil);
    //qDebug()<<"Dipare chavalin pero no lo vites ";
}
