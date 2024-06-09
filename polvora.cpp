#include "polvora.h"
#include <QGraphicsScene>
#include <QList>

Polvora::Polvora(QGraphicsItem *parent) : PowerUp(parent) {
    QPixmap pixmap(":/imagenes/polvora.png"); // Asegúrate de tener esta imagen
    setPixmap(pixmap);
}

void Polvora::applyEffect() {
    // Emitir la señal para incrementar el contador de pólvora
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

void Polvora::advance(int step) {
    if (!step)
        return;
    checkCollision();
}
