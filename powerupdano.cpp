#include "powerupdano.h"
#include "soldado_otomano.h"
#include <QGraphicsScene>

PowerUpDano::PowerUpDano(QGraphicsItem *parent) : PowerUp(parent) {
    QPixmap pixmap(":/imagenes/power_blast.png"); // Asegúrate de tener esta imagen
    setPixmap(pixmap);
    setScale(0.25);
}

void PowerUpDano::applyEffect() {
    soldado_otomano *soldado = dynamic_cast<soldado_otomano *>(scene()->focusItem());
    if (soldado) {
        soldado->aumentarDano(); // Asegúrate de tener este método en soldado_otomano
    }
}
