#ifndef DISP_H
#define DISP_H
#include <QGraphicsEllipseItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include <QBrush>
#include <QGraphicsScene>
#include <QList>
#include "puntaje.h"
class Disp : public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Disp(Puntaje *puntaje,QGraphicsItem *parent=nullptr);
public slots:
    void move();
private:
    double velocidad;
    double angulo;
    double radianes;
    double vx0;
    double vy0;
    double g;
    double t;
    double tiempoTotal;
    QTimer *timer;
    Puntaje *puntajeDisplay;
};

#endif // DISP_H
