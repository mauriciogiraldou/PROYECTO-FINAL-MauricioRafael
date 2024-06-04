#include "jefeproyectil.h"
#include "barquito.h" // Para manejar colisiones con el barco del jugador
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include <typeinfo>

JefeProyectil::JefeProyectil(QGraphicsItem *parent)
    : ProyectilEnemigo(parent) {
    setScale(0.80);
    //setRect(0, 0, 70, 70); // Tamaño más grande
    //setBrush(Qt::darkGray); // Color diferente

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}


