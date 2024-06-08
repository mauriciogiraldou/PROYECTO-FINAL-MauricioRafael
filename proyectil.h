#ifndef PROYECTIL_H
#define PROYECTIL_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QElapsedTimer>

class Proyectil : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Proyectil(qreal angle, QGraphicsItem *parent = nullptr);
private slots:
    void move();
private:
    QTimer *moveTimer;
    qreal angle; // Ángulo en grados
    qreal initialSpeed; // Velocidad inicial
    qreal currentSpeed; // Velocidad actual
    qreal deceleration; // Desaceleración
    QElapsedTimer timer; // Temporizador para medir el tiempo transcurrido
};

#endif // PROYECTIL_H
