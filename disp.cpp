#include "disp.h"
#include <QDebug>
#include "barquitoenemigo.h"
#include "barcoenemigo.h"
#include "jefefinal.h"

Disp::Disp(Puntaje *puntaje): puntajeDisplay(puntaje) {
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

    // Verificar colisiones
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(Barquitoenemigo)) {
            // Remover ambos elementos de la escena
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // Eliminar ambos elementos
            delete colliding_items[i];
            delete this;

            // Incrementar puntaje si es un Barquitoenemigo
            puntajeDisplay->incrementar(50);
            return;
        } else if (typeid(*(colliding_items[i])) == typeid(Barcoenemigo)) {
            // Disminuir la vida del Barcoenemigo
            Barcoenemigo *enemy = dynamic_cast<Barcoenemigo *>(colliding_items[i]);
            if (enemy) {
                enemy->recibirDisparo();
                puntajeDisplay->incrementar(10);
            }

            // Remover el proyectil
            scene()->removeItem(this);
            delete this;
            return;
        } else if (typeid(*(colliding_items[i])) == typeid(JefeFinal)) {
            // Disminuir la vida del JefeFinal
            JefeFinal *boss = dynamic_cast<JefeFinal *>(colliding_items[i]);
            if (boss) {
                boss->recibirDisparo();
                puntajeDisplay->incrementar(1);
            }

            // Remover el proyectil
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    // Eliminar el proyectil si sale de la pantalla
    if (pos().y() > 800 || pos().x() < 0 || pos().x() > 1400) {
        scene()->removeItem(this);
        delete this;
        qDebug() << "se elimina la balurda";
    }
}
