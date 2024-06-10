#ifndef POWERUP_H
#define POWERUP_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
class PowerUp : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    PowerUp(QGraphicsItem *parent = nullptr);
    virtual void applyEffect() = 0;
private slots:
    void checkCollision();
private:
    QTimer *collisionTimer;
};

#endif // POWERUP_H
