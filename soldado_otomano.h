#ifndef SOLDADO_OTOMANO_H
#define SOLDADO_OTOMANO_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "puntaje.h"
#include "vidas.h"

class soldado_otomano: public QObject, public QGraphicsPixmapItem
{
public:
    soldado_otomano();
    void keyPressEvent(QKeyEvent *event) override;

private:
    int vidas;
    int velocidad;
    Puntaje* puntajeDisplay = nullptr;
    Vidas* vidasDisplay=nullptr;

};

#endif // SOLDADO_OTOMANO_H
