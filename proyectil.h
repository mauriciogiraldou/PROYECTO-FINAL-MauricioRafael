#ifndef PROYECTIL_H
#define PROYECTIL_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QElapsedTimer>
class Proyectil : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Proyectil(qreal angle, QGraphicsItem *parent = nullptr);
private slots:
    void move();
private:
    QTimer *moveTimer;
    qreal angle;
    qreal initialSpeed;
    qreal currentSpeed;
    qreal deceleration;
    QElapsedTimer timer;
};

#endif // PROYECTIL_H
