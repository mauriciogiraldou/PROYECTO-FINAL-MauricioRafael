#include "powerupvida.h"
#include "soldado_otomano.h"
#include <QGraphicsScene>

PowerUpVida::PowerUpVida(QGraphicsItem *parent) : PowerUp(parent) {
    QPixmap pixmap(":/imagenes/power_health.png"); // Asegúrate de tener esta imagen
    setPixmap(pixmap);
    setScale(0.25);
}

void PowerUpVida::applyEffect() {
    soldado_otomano *soldado = dynamic_cast<soldado_otomano *>(scene()->focusItem());
    if (soldado) {
        soldado->aumentarVida();
    }
}
