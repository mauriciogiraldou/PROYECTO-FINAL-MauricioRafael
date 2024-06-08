#ifndef SOLDADO_OTOMANO_H
#define SOLDADO_OTOMANO_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "puntaje.h"
#include "vidas.h"
#include "proyectil.h"
#include <QTimer>

class soldado_otomano: public QObject, public QGraphicsPixmapItem
{
Q_OBJECT
public:
    soldado_otomano();
    void keyPressEvent(QKeyEvent *event) override;
private slots:
    void enableShooting();
private:
    int vidas;
    int velocidad;
    qreal currentAngle;
    Puntaje* puntajeDisplay = nullptr;
    Vidas* vidasDisplay=nullptr;
    bool canShoot;  // Variable para controlar si puede disparar
    QTimer shootTimer;
};

#endif // SOLDADO_OTOMANO_H
