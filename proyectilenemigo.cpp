#include "proyectilenemigo.h"
#include <QGraphicsScene>
#include <QList>
#include <typeinfo>
#include "barquito.h"
ProyectilEnemigo::ProyectilEnemigo(QGraphicsItem *parent)
    : QObject(), QGraphicsPixmapItem(parent) {
    setScale(0.40);
    QPixmap pixmap(":/imagenes/bodoque_piedra2.png");
    setPixmap(pixmap);
    QTimer *timer = new QTimer(this);
    timer->start(50);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

}

void ProyectilEnemigo::move() {
    setPos(x() - 9, y());
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0; i < colliding_items.size(); ++i) {
        if (typeid(*(colliding_items[i])) == typeid(Barquito)) {
            static_cast<Barquito*>(colliding_items[i])->reducirVidas();
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
    if (pos().x() < -10) {
        scene()->removeItem(this);
        delete this;
    }
}
