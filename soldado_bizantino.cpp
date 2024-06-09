#include "soldado_bizantino.h"
#include "soldado_otomano.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QList>
#include <QPixmap>
#include "powerupvida.h"
#include "powerupvelocidad.h"
#include "powerupdano.h"

soldado_bizantino::soldado_bizantino(QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent), velocidad(4),vida(4),player(nullptr) {
    setPixmap(QPixmap(":/imagenes/soldado_bizantino_abajo.png"));
    setScale(0.68);

    movementTimer = new QTimer(this);
    connect(movementTimer, &QTimer::timeout, this, &soldado_bizantino::followPlayer);
    movementTimer->start(50); // Update every 50ms
    srand(static_cast<unsigned>(time(nullptr)));
}

void soldado_bizantino::followPlayer() {
    if (!player) {
        // Try to find the player in the scene
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
        return; // No player found, cannot follow
    }

    // Calculate the direction towards the player
    qreal deltaX = player->x() - x();
    qreal deltaY = player->y() - y();
    qreal distance = sqrt(deltaX * deltaX + deltaY * deltaY);

    if (distance < 1) {
        return; // Already close enough to the player
    }

    // Move towards the player
    qreal moveX = velocidad * deltaX / distance;
    qreal moveY = velocidad * deltaY / distance;
    setPos(x() + moveX, y() + moveY);

    // Update the image based on the direction
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
    qDebug() << "Vida del soldado bizantino: " << vida;
    if (vida <= 0) {
        dropPowerUp();
        scene()->removeItem(this);
        delete this;
    }
}
void soldado_bizantino::dropPowerUp() {
    int random = rand() % 100;
    if (random < 20) { // 20% de probabilidad de generar un power-up
        PowerUp *powerup;
        int tipo =rand()%3; // 0, 1, o 2
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
