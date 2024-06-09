#include "powerup.h"
#include "soldado_otomano.h"
#include <QGraphicsScene>
#include <QList>

PowerUp::PowerUp(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent) {
    collisionTimer = new QTimer(this);
    connect(collisionTimer, &QTimer::timeout, this, &PowerUp::checkCollision);
    collisionTimer->start(50); // Verifica colisión cada 50 ms
}

void PowerUp::checkCollision() {
    QList<QGraphicsItem *> collidingItems = scene()->collidingItems(this);
    foreach (QGraphicsItem *item, collidingItems) {
        soldado_otomano *soldado = dynamic_cast<soldado_otomano *>(item);
        if (soldado) {
            applyEffect(); // Aplica el efecto del power-up
            scene()->removeItem(this);
            delete this;
            break;
        }
    }
}
