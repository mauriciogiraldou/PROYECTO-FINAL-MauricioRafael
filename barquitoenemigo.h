#ifndef BARQUITOENEMIGO_H
#define BARQUITOENEMIGO_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>

class Barquitoenemigo : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Barquitoenemigo(QGraphicsItem *parent = nullptr);
public slots:
    void move();
private:
    QTimer *moveTimer;
    const int velocidad = 5;
};

#endif // BARQUITOENEMIGO_H
