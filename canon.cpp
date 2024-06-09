#include "canon.h"
#include <QPixmap>
#include <QGraphicsScene>
#include "proyectilc.h"

Canon::Canon(int initialHealth, QGraphicsItem *parent)
    : QObject(), QGraphicsPixmapItem(parent), vida(initialHealth) {
    QPixmap pixmap(":/imagenes/orban_canon.png");  // Asegúrate de tener esta imagen
    setPixmap(pixmap);
}

void Canon::recibirDano(int cantidad) {
    vida -= cantidad;
    if (vida <= 0) {
        // Lógica para cuando el cañón sea destruido
        scene()->removeItem(this);
        delete this;
    }
}

int Canon::getVida() const {
    return vida;
}
void Canon::disparar() {
    ProyectilC *proyectil = new ProyectilC(270); // 270 grados para disparar hacia abajo
    proyectil->setPos(x(), y());
    scene()->addItem(proyectil);

    QTimer *timer = new QTimer(proyectil);
    connect(timer, &QTimer::timeout, proyectil, &ProyectilC::move);
    timer->start(50); // Ajusta el intervalo según sea necesario

    emit proyectilDisparado();
}
