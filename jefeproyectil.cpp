#include "jefeproyectil.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
JefeProyectil::JefeProyectil(QGraphicsItem *parent)
    : ProyectilEnemigo(parent) {
    setScale(0.65);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}


