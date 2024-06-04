#include "proyectilenemigo.h"
#include <QGraphicsScene>
#include <QList>
#include <typeinfo>
#include "barquito.h" // Para manejar colisiones con el barco del jugador

ProyectilEnemigo::ProyectilEnemigo(QGraphicsItem *parent)
    : QObject(), QGraphicsPixmapItem(parent) {
    //setRect(0, 0, 45, 45);
    //setBrush(Qt::gray);
    setScale(0.40);
    QPixmap pixmap(":/imagenes/bodoque_piedra2.png");
    setPixmap(pixmap);
    QTimer *timer = new QTimer(this);
    timer->start(50);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

}

void ProyectilEnemigo::move() {
    setPos(x() - 9, y()); // Mover a lo largo de la X positiva

    // Verificar colisiones con el barco del jugador
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0; i < colliding_items.size(); ++i) {
        if (typeid(*(colliding_items[i])) == typeid(Barquito)) {
            // Disminuir vidas del jugador y manejar colisión
            static_cast<Barquito*>(colliding_items[i])->reducirVidas();

            // Eliminar el proyectil
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    // Si el proyectil sale de la pantalla, eliminarlo
    if (pos().x() < -10) { // Ajustar según el tamaño de la pantalla
        scene()->removeItem(this);
        delete this;
    }
}
