#ifndef POWERUPVELOCIDAD_H
#define POWERUPVELOCIDAD_H
#include "powerup.h"
class PowerUpVelocidad : public PowerUp {
    Q_OBJECT
public:
    PowerUpVelocidad(QGraphicsItem *parent = nullptr);
    void applyEffect() override;
};

#endif // POWERUPVELOCIDAD_H
