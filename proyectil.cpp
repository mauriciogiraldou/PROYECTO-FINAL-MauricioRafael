#include "proyectil.h"
#include <QGraphicsScene>
#include <QPixmap>
#include <QtMath>
#include "soldado_bizantino.h"
Proyectil::Proyectil(qreal angle, QGraphicsItem *parent)
    : QObject(), QGraphicsPixmapItem(parent), angle(angle), initialSpeed(15), deceleration(2.5) {
    QPixmap pixmap(":/imagenes/arrowcita.png");
    setPixmap(pixmap);
    setScale(0.35);
    setRotation(angle);
    currentSpeed = initialSpeed;
    timer.start();
    moveTimer = new QTimer(this);
    connect(moveTimer, &QTimer::timeout, this, &Proyectil::move);
    moveTimer->start(50);
}
void Proyectil::move() {
    qreal elapsedTime = timer.elapsed() / 1000.0;
    currentSpeed = initialSpeed - deceleration * elapsedTime;
    if (currentSpeed < 0) {
        currentSpeed = 0;
    }
    qreal angleRad = qDegreesToRadians(angle);
    qreal dx = currentSpeed * qCos(angleRad);
    qreal dy = currentSpeed * qSin(angleRad);
    setPos(x() + dx, y() + dy);
    QList<QGraphicsItem *> collidingItems = scene()->collidingItems(this);
    foreach (QGraphicsItem *item, collidingItems) {
        soldado_bizantino *enemigo = dynamic_cast<soldado_bizantino *>(item);
        if (enemigo) {
            enemigo->reducirVida(1);
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
    if (currentSpeed == 0 || x() < 0 || x() > 1400 || y() < 0 || y() >800) {
        scene()->removeItem(this);
        delete this;
    }
}
