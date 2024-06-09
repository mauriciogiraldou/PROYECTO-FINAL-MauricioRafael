#ifndef POWERUPVIDA_H
#define POWERUPVIDA_H

#include "powerup.h"

class PowerUpVida : public PowerUp {
    Q_OBJECT
public:
    PowerUpVida(QGraphicsItem *parent = nullptr);
    void applyEffect() override;
};

#endif // POWERUPVIDA_H
