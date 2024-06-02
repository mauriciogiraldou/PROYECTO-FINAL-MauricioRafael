#ifndef BARCOENEMIGO_H
#define BARCOENEMIGO_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QObject>

class Barcoenemigo:public QObject,public QGraphicsPixmapItem
{
public:
    Barcoenemigo(QGraphicsItem *parent=nullptr);
    void recibirDisparo();
public slots:
    void shoot();
    void checkCollisions();
private:
    int vida;
    QTimer *collisionTimer;
};

#endif // BARCOENEMIGO_H
