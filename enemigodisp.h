#ifndef ENEMIGODISP_H
#define ENEMIGODISP_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QtMath>

class EnemigoDisp : public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    EnemigoDisp(QGraphicsItem *parent = nullptr);

public slots:
    void move();

private:
    QTimer *timer;
    double velocidad;
    double angulo;
    double radianes;
    double vx0;
    double vy0;
    double g;
    double t;
    double tiempoTotal;
};

#endif // ENEMIGODISP_H
