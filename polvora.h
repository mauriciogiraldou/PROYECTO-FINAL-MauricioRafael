#ifndef POLVORA_H
#define POLVORA_H
#include "powerup.h"
#include <QGraphicsPixmapItem>
#include <QObject>
class Polvora : public PowerUp {
    Q_OBJECT
public:
    Polvora(QGraphicsItem *parent = nullptr);
    void applyEffect() override;
    void checkCollision();
signals:
    void polvoraRecolectada();
};

#endif // POLVORA_H
