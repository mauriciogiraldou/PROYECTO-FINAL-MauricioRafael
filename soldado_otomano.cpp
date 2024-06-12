#include "soldado_otomano.h"
#include "muro_verdadero.h"
#include <QGraphicsScene>
#include <QMessageBox>
#include <QApplication>
#include "proyectil.h"
soldado_otomano::soldado_otomano(): vidas(3),velocidad(10),velocidaddano(510),currentAngle(0),canShoot(true) {
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
        currentAngle = 180;
        if (x() > -10)
            setPos(x() - velocidad, y());
    } else if (event->key() == Qt::Key_D) {
        setPixmap(QPixmap(":/imagenes/caballo_o_derecha.png"));
        currentAngle = 0;
        if (x() < 1200)
            setPos(x() + velocidad, y());
    } else if (event->key() == Qt::Key_W) {
        setPixmap(QPixmap(":/imagenes/caballo_o_arriba.png"));
        currentAngle = 270;
        if (y() > -45)
            setPos(x(), y() - velocidad);
    } else if (event->key() == Qt::Key_S) {
        setPixmap(QPixmap(":/imagenes/caballo_o_abajo.png"));
        currentAngle = 90;
        if (y() < 570)
            setPos(x(), y() + velocidad);
    } else if (event->key() == Qt::Key_Space && canShoot) {
        Proyectil *proyectil = new Proyectil(currentAngle);
        proyectil->setPos(x() + 50, y() + 75);
        scene()->addItem(proyectil);
        canShoot = false;
        shootTimer.start(velocidaddano);
    }
    QList<QGraphicsItem *> collidingItems = QGraphicsPixmapItem::collidingItems();
    foreach (QGraphicsItem *item, collidingItems) {
        if (dynamic_cast<Muro_verdadero *>(item)) {
            setPos(x_anterior, y_anterior);
            break;
        }
    }
}
void soldado_otomano::enableShooting() {
    canShoot = true;
    shootTimer.stop();
}
void soldado_otomano::reducirVida()
{
    vidas--;
    emit vidaCambiada(vidas);
    if (vidas <= 0) {
        QMessageBox::information(nullptr, "Game Over", "Has sido atrapado por un enemigo. Juego terminado.");
        QCoreApplication::quit();
    }
}

int soldado_otomano::getdano()
{
    return velocidaddano;
}
void soldado_otomano::aumentarVida() {
    vidas++;
    emit vidaCambiada(vidas);
}

void soldado_otomano::aumentarVelocidad() {
    velocidad += 1;
}

void soldado_otomano::aumentarDano()
{
    velocidaddano-=35;
}
