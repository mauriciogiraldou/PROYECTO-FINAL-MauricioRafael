#include "disp.h"
#include <QDebug>
Disp::Disp() {
    setRect(0, 0, 15, 15);
    setBrush(Qt::gray);
    QTimer *timer = new QTimer(this); // Asociar el temporizador a la instancia actual
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(80);
    velocidad = 65; // Velocidad inicial (magnitud)
    angulo = 25; // Ángulo de lanzamiento (en grados)
    radianes = qDegreesToRadians(angulo);

    // Componentes de la velocidad inicial
    vx0 = velocidad * qCos(radianes); // Componente horizontal
    vy0 = velocidad * qSin(radianes); // Componente vertical inicial

    // Aceleración debida a la gravedad
    g = 9.8; // m/s^2

    // Inicializar el tiempo
    t = 0.5; // Intervalo de tiempo (ajusta según la velocidad del juego)
    tiempoTotal = 0; // Tiempo total transcurrido
}

void Disp::move() {
    // Incrementar el tiempo total
    tiempoTotal += t;

    // Calcular la nueva posición
    double nueva_x = x() + vx0 * t;
    double nueva_y = y() - (vy0 * tiempoTotal - 0.5 * g * tiempoTotal * tiempoTotal);

    // Actualizar la posición del proyectil
    setPos(nueva_x, nueva_y);

    // Detener el movimiento cuando el proyectil toque el suelo (y <= 0)
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Barquitoenemigo)){
            // remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // delete them both
            delete colliding_items[i];
            delete this;
            return;
        }
    }
    if(pos().y()>800){
        scene()->removeItem(this);
        delete this;
        qDebug()<<"se elimina la balurda";
    }
    else if(pos().x()<0){
    scene()->removeItem(this);
    delete this;
    qDebug()<<"se elimina la balurda";
    }
    else if(pos().x()>1400){
        scene()->removeItem(this);
        delete this;
        qDebug()<<"se elimina la balurda";
    }
}
