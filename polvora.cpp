#include "polvora.h"
#include <QGraphicsScene>
#include <QList>
#include "soldado_otomano.h"
Polvora::Polvora(QGraphicsItem *parent) : PowerUp(parent) {
    QPixmap pixmap(":/imagenes/polvora.png");
    setPixmap(pixmap);
    setScale(0.5);
}
void Polvora::applyEffect() {
    //incrementar el contador de pólvora
    emit polvoraRecolectada();
}
void Polvora::checkCollision() {
    QList<QGraphicsItem *> collidingItems = scene()->collidingItems(this);
    foreach (QGraphicsItem *item, collidingItems) {
        soldado_otomano *soldado = dynamic_cast<soldado_otomano *>(item);
        if (soldado) {
            applyEffect();
            scene()->removeItem(this);
            delete this;
            break;
        }
    }
}
