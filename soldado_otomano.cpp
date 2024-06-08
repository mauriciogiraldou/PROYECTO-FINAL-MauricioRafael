#include "soldado_otomano.h"
#include "muro_verdadero.h"
#include <QGraphicsScene>

soldado_otomano::soldado_otomano(): vidas(3),velocidad(10),currentAngle(0),canShoot(true) {
    QPixmap personaje_principal(":/imagenes/caballo_o_abajo.png");
    setPixmap(personaje_principal);
    setScale(0.78);
     connect(&shootTimer, &QTimer::timeout, this, &soldado_otomano::enableShooting);
}

void soldado_otomano::keyPressEvent(QKeyEvent *event) {
    qreal x_anterior = x();
    qreal y_anterior = y();

    if (event->key() == Qt::Key_A) {
        setPixmap(QPixmap(":/imagenes/caballo_o_izquierda.png"));
        currentAngle = 180; // Izquierda
        if (x() > -10)
            setPos(x() - velocidad, y());
    } else if (event->key() == Qt::Key_D) {
        setPixmap(QPixmap(":/imagenes/caballo_o_derecha.png"));
        currentAngle = 0; // Derecha
        if (x() < 1200)
            setPos(x() + velocidad, y());
    } else if (event->key() == Qt::Key_W) {
        setPixmap(QPixmap(":/imagenes/caballo_o_arriba.png"));
        currentAngle = 270; // Arriba
        if (y() > -45)
            setPos(x(), y() - velocidad);
    } else if (event->key() == Qt::Key_S) {
        setPixmap(QPixmap(":/imagenes/caballo_o_abajo.png"));
        currentAngle = 90; // Abajo
        if (y() < 570)
            setPos(x(), y() + velocidad);
    } else if (event->key() == Qt::Key_Space && canShoot) {
        // Crear y disparar el proyectil
        Proyectil *proyectil = new Proyectil(currentAngle);
        proyectil->setPos(x() + 50, y() + 75);
        scene()->addItem(proyectil);
        // Deshabilitar el disparo y empezar el temporizador
        canShoot = false;
        shootTimer.start(560);  // Establecer el tiempo de espera en 560 milisegundos
    }

    // Verificar colisiones con los muros verdaderos
    QList<QGraphicsItem *> collidingItems = QGraphicsPixmapItem::collidingItems();
    foreach (QGraphicsItem *item, collidingItems) {
        if (dynamic_cast<Muro_verdadero *>(item)) {
            // Si hay colisión, restaurar la posición anterior
            setPos(x_anterior, y_anterior);
            break;
        }
    }
}
void soldado_otomano::enableShooting() {
    canShoot = true;
    shootTimer.stop();
}
