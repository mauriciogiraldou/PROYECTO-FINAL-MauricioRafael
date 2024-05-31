#include "jefefinal.h"
#include "jefeproyectil.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>

JefeFinal::JefeFinal(QGraphicsItem *parent):QGraphicsPixmapItem(parent),direccion(1),vida(600)
{
    QPixmap pixmap(":/imagenes/Barco jefe.png");
    setPixmap(pixmap);
    setScale(0.68);
    setPos(798,40);
    QTimer *moveTimer = new QTimer(this);
    connect(moveTimer, &QTimer::timeout, this, &JefeFinal::move);
    moveTimer->start(50); // Move every 50ms
    QTimer *shootTimer = new QTimer(this);
    connect(shootTimer, &QTimer::timeout, this, &JefeFinal::shoot);
    shootTimer->start(3000); // Shoots every second
}

void JefeFinal::move()
{
    double step = 2.5; // Move 3 pixels per tick
    // Move down
    if (direccion == 1) {
        setPos(x(), y() + step);
        if (y() + pixmap().height() >= 950) { // Change to your scene height
            direccion = -1; // Change direction to up
       }
    }
    // Move up
    else if (direccion == -1) {
        setPos(x(), y() - step);
        if (y() <= 0) { // Top boundary
            direccion = 1; // Change direction to down
        }
    }
}
void JefeFinal::shoot()
{
    JefeProyectil *bullet = new JefeProyectil();
    bullet->setPos(x() +15, y() + 240);
    scene()->addItem(bullet);
    qDebug()<<"que pasa chavale";
}
void JefeFinal::recibirDisparo() {
    vida -= 1; // Reducir la vida en 10 (ajusta según sea necesario)
    qDebug()<<"No me disparen";
    if (vida <= 0) {
        // Si la vida es menor o igual a 0, eliminar el jefe final
        scene()->removeItem(this);
        delete this;
        qDebug() << "Jefe final destruido";
    }
}
int JefeFinal::getVida() const {
    return vida;
}
