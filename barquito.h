#ifndef BARQUITO_H
#define BARQUITO_H
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QDebug>
#include <barco.h>
class Barquito:public QGraphicsPixmapItem,public Barco
{
public:
    Barquito(QGraphicsItem *parent =nullptr);
    void keyPressEvent(QKeyEvent *event);
private:
    int velocidad=10;

};

#endif // BARQUITO_H
