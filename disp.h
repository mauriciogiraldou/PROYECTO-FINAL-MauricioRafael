#ifndef DISP_H
#define DISP_H
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include <cmath>
#include <QBrush>
#include <QGraphicsScene>
#include <QList>
#include <puntaje.h>
class Disp : public QObject,public QGraphicsEllipseItem{
    Q_OBJECT
public:
    Disp(Puntaje *puntaje);
public slots:
    void move();

private:
    double velocidad;    // Velocidad inicial (magnitud)
    double angulo;       // Ángulo de lanzamiento (en grados)
    double radianes;     // Ángulo en radianes
    double vx0;          // Componente horizontal de la velocidad inicial
    double vy0;          // Componente vertical de la velocidad inicial
    double g;            // Aceleración debida a la gravedad
    double t;            // Intervalo de tiempo
    double tiempoTotal;  // Tiempo total transcurrido
    QTimer *timer;
    Puntaje *puntajeDisplay;        // Temporizador para el movimiento
};

#endif // DISP_H
