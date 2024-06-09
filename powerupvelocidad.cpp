#include "powerupvelocidad.h"
#include "soldado_otomano.h"
#include <QGraphicsScene>

PowerUpVelocidad::PowerUpVelocidad(QGraphicsItem *parent) : PowerUp(parent) {
    QPixmap pixmap(":/imagenes/power_speed.png"); // Asegúrate de tener esta imagen
    setPixmap(pixmap);
    setScale(0.25);
}

void PowerUpVelocidad::applyEffect() {
    soldado_otomano *soldado = dynamic_cast<soldado_otomano *>(scene()->focusItem());
    if (soldado) {
        soldado->aumentarVelocidad(); // Asegúrate de tener este método en soldado_otomano
    }
}
