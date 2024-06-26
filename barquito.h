#ifndef BARQUITO_H
#define BARQUITO_H
#include <QKeyEvent>
#include <QDebug>
#include <QGraphicsScene>
#include <QObject>
#include "puntaje.h"
#include "vidas.h"
class Barquito:public QObject,public QGraphicsPixmapItem
{
Q_OBJECT
public:
    Barquito(QGraphicsItem *parent =nullptr);
    void keyPressEvent(QKeyEvent *event);
    void reducirVidas();
    void incrementarPuntaje(int puntos);
    void setPuntaje(Puntaje* p) { puntajeDisplay = p; }
    void setVidas(Vidas* v) { vidasDisplay = v; }
    void reducirVelocidad();
private:
    int velocidad=12;
    int vidas;
    Puntaje* puntajeDisplay = nullptr;
    Vidas* vidasDisplay=nullptr;
};

#endif // BARQUITO_H
