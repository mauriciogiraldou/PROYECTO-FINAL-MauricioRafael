#ifndef PROYECTILENEMIGO_H
#define PROYECTILENEMIGO_H
#include <QGraphicsEllipseItem>
#include <QObject>
#include <QTimer>
class ProyectilEnemigo:public QObject,public QGraphicsEllipseItem
{
Q_OBJECT
public:
    ProyectilEnemigo(QGraphicsItem *parent=nullptr);
public slots:
    void move();
};

#endif // PROYECTILENEMIGO_H
