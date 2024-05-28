#ifndef BARQUITO_H
#define BARQUITO_H
#include <QKeyEvent>
#include <QDebug>
#include "disp.h"
#include <QGraphicsScene>
#include <QObject>
class Barquito:public QObject,public QGraphicsPixmapItem
{
Q_OBJECT
public:
    Barquito(QGraphicsItem *parent =nullptr);
    void keyPressEvent(QKeyEvent *event);
    void reducirVidas();
private:
    int velocidad=10;
    int vidas=3;

};

#endif // BARQUITO_H
