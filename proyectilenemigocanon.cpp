#include "proyectilenemigocanon.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include "puerta.h"

ProyectilEnemigoCanon::ProyectilEnemigoCanon(QGraphicsItem *parent)
    : QObject(), QGraphicsPixmapItem(parent) {
    setScale(0.40);
    QPixmap pixmap(":/imagenes/bodoque_piedra2.png");
    setPixmap(pixmap);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move2()));
    timer->start(50);
}

void ProyectilEnemigoCanon::move2() {
    setPos(x(), y() + 9); // Mover a lo largo de la Y positiva
    // Si el proyectil sale de la pantalla, eliminarlo
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0; i < colliding_items.size(); ++i) {
        if (typeid(*(colliding_items[i])) == typeid(Puerta)) {
            // Disminuir la vida de la puerta y manejar colisión
            Puerta *puerta = dynamic_cast<Puerta *>(colliding_items[i]);
            puerta->recibirDisparo();

            // Eliminar el proyectil
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
    if (pos().y() > 600) { // Ajustar según el tamaño de la pantalla
        qDebug()<<"me sali";
        scene()->removeItem(this);
        delete this;
    }
}
