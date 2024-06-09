#ifndef POWERUPDANO_H
#define POWERUPDANO_H

#include "powerup.h"

class PowerUpDano : public PowerUp {
    Q_OBJECT
public:
    PowerUpDano(QGraphicsItem *parent = nullptr);
    void applyEffect() override;
};

#endif // POWERUPDANO_H
