#ifndef BOLA_H
#define BOLA_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
class Bola : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Bola(QGraphicsItem *parent = nullptr);
private slots:
    void move();
private:
    QTimer *moveTimer;
    double tiempo;   // Tiempo en segundos
    double velocidadY; // Velocidad inicial en y (m/s)
    double gravedad;  // Aceleración debido a la gravedad (m/s^2)
    void checkCollisions();
};

#endif // BOLA_H
