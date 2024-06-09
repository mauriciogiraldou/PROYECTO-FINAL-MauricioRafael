#include "proyectilc.h"
#include <QGraphicsScene>

ProyectilC::ProyectilC(int direction, QGraphicsItem *parent)
    : QObject(), QGraphicsPixmapItem(parent), direction(direction) {
    QPixmap pixmap(":/imagenes/bodoque2.png"); // Asegúrate de tener esta imagen
    setPixmap(pixmap);
    setScale(0.50);
}

void ProyectilC::move() {
    int stepSize = 10; // Ajusta el tamaño del paso según sea necesario
    int dx = stepSize * cos(qDegreesToRadians((double)direction));
    int dy = stepSize * sin(qDegreesToRadians((double)direction));
    setPos(x() + dx, y() + dy);

    // Eliminar el proyectil si sale de la escena
    if (y() > 500) { // Asumiendo que 500 es el límite en y
        scene()->removeItem(this);
        delete this;
    }
}
