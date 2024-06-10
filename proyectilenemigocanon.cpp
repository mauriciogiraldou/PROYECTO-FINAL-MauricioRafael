#include "proyectilenemigocanon.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
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
    setPos(x(), y() + 9);
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0; i < colliding_items.size(); ++i) {
        if (typeid(*(colliding_items[i])) == typeid(Puerta)) {
            Puerta *puerta = dynamic_cast<Puerta *>(colliding_items[i]);
            puerta->recibirDisparo();
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
    if (pos().y() > 600) {
        scene()->removeItem(this);
        delete this;
    }
}
