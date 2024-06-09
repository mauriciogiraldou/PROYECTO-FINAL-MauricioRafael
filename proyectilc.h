#ifndef PROYECTIL_H
#define PROYECTIL_H

#include <QObject>
#include <QGraphicsPixmapItem>

class ProyectilC : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    ProyectilC(int direction, QGraphicsItem *parent = nullptr);
public slots:
    void move();
private:
    int direction;
};

#endif // PROYECTIL_H
