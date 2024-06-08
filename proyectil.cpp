#include "proyectil.h"
#include <QGraphicsScene>
#include <QPixmap>
#include <QtMath>
#include <QDebug>

Proyectil::Proyectil(qreal angle, QGraphicsItem *parent)
    : QObject(), QGraphicsPixmapItem(parent), angle(angle), initialSpeed(15), deceleration(2.5) {
    QPixmap pixmap(":/imagenes/arrowcita.png");
    setPixmap(pixmap);
    setScale(0.35);
    setRotation(angle);

    // Configurar la velocidad inicial
    currentSpeed = initialSpeed;

    // Iniciar el temporizador
    timer.start();

    // Temporizador para mover el proyectil
    moveTimer = new QTimer(this);
    connect(moveTimer, &QTimer::timeout, this, &Proyectil::move);
    moveTimer->start(50); // Actualiza la posición del proyectil cada 50 ms
}

void Proyectil::move() {
    // Calcular el tiempo transcurrido en segundos
    qreal elapsedTime = timer.elapsed() / 1000.0;

    // Calcular la velocidad actual
    currentSpeed = initialSpeed - deceleration * elapsedTime;
    if (currentSpeed < 0) {
        currentSpeed = 0;
    }

    // Convertir el ángulo a radianes
    qreal angleRad = qDegreesToRadians(angle);

    // Calcular el desplazamiento en x e y
    qreal dx = currentSpeed * qCos(angleRad);
    qreal dy = currentSpeed * qSin(angleRad);

    // Mover el proyectil
    setPos(x() + dx, y() + dy);

    // Eliminar el proyectil si la velocidad llega a cero o si sale de la escena
    if (currentSpeed == 0 || x() < 0 || x() > 1400 || y() < 0 || y() >800) {
        scene()->removeItem(this);
        delete this;
    }
}
