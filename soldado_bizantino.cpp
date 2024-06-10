#include "soldado_bizantino.h"
#include "soldado_otomano.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QList>
#include <QPixmap>
#include "powerupvida.h"
#include "powerupvelocidad.h"
#include "powerupdano.h"
#include <stdlib.h>
soldado_bizantino::soldado_bizantino(QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent), velocidad(4),vida(4),player(nullptr) {
    setPixmap(QPixmap(":/imagenes/soldado_bizantino_abajo.png"));
    setScale(0.68);

    movementTimer = new QTimer(this);
    connect(movementTimer, &QTimer::timeout, this, &soldado_bizantino::followPlayer);
    movementTimer->start(50);
    srand(static_cast<unsigned>(time(nullptr)));
}

void soldado_bizantino::followPlayer() {
    if (!player) {
        QList<QGraphicsItem *> items = scene()->items();
        foreach (QGraphicsItem *item, items) {
            soldado_otomano *potentialPlayer = dynamic_cast<soldado_otomano *>(item);
            if (potentialPlayer) {
                player = potentialPlayer;
                break;
            }
        }
    }

    if (!player) {
        return;
    }

    qreal deltaX = player->x() - x();
    qreal deltaY = player->y() - y();
    qreal distance = sqrt(deltaX * deltaX + deltaY * deltaY);
    if (distance < 1) {
        return;
    }
    qreal moveX = velocidad * deltaX / distance;
    qreal moveY = velocidad * deltaY / distance;
    setPos(x() + moveX, y() + moveY);
    updateImage();
    QList<QGraphicsItem *> collidingItems = scene()->collidingItems(this);
    foreach(QGraphicsItem *item, collidingItems) {
        soldado_otomano *soldado = dynamic_cast<soldado_otomano *>(item);
        if (soldado) {
            soldado->reducirVida();
            scene()->removeItem(this);
            delete this;
            break;
        }
    }
}

void soldado_bizantino::updateImage() {
    qreal deltaX = player->x() - x();
    qreal deltaY = player->y() - y();

    if (abs(deltaX) > abs(deltaY)) {
        if (deltaX > 0) {
            setPixmap(QPixmap(":/imagenes/soldado_bizantino_derecha.png"));
        } else {
            setPixmap(QPixmap(":/imagenes/soldado_bizantino_izquierda.png"));
        }
    } else {
        if (deltaY > 0) {
            setPixmap(QPixmap(":/imagenes/soldado_bizantino_abajo.png"));
        } else {
            setPixmap(QPixmap(":/imagenes/soldado_bizantino_arriba.png"));
        }
    }
}
void soldado_bizantino::reducirVida(int cantidad) {
    vida -= cantidad;
    if (vida <= 0) {
        dropPowerUp();
        emit soldadoMuerto(this);
        scene()->removeItem(this);
        delete this;
    }
}
void soldado_bizantino::dropPowerUp() {
    int random = rand() % 100;
    if (random < 40) {
        PowerUp *powerup;
        int tipo = rand() %3 ;
        if (tipo == 0) {
            powerup = new PowerUpVida();
        } else if (tipo == 1) {
            powerup = new PowerUpVelocidad();
        } else if (tipo==2){
            powerup = new PowerUpDano();
        }
        powerup->setPos(pos());
        scene()->addItem(powerup);
    }
}
