#ifndef SOLDADO_OTOMANO_H
#define SOLDADO_OTOMANO_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "puntaje.h"
#include <QTimer>
class soldado_otomano: public QObject, public QGraphicsPixmapItem
{
Q_OBJECT
public:
    soldado_otomano();
    void keyPressEvent(QKeyEvent *event) override;
    void reducirVida();
    int getdano();
    void aumentarVida();
    void aumentarVelocidad();
    void aumentarDano();
private slots:
    void enableShooting();
private:
    int vidas;
    int velocidad;
    int velocidaddano;
    qreal currentAngle;
    Puntaje* puntajeDisplay = nullptr;
    bool canShoot;  // Variable para controlar si puede disparar
    QTimer shootTimer;
signals:
    void vidaCambiada(int nuevaVida);
};

#endif // SOLDADO_OTOMANO_H
