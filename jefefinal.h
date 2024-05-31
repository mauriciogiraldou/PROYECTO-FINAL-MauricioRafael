#ifndef JEFEFINAL_H
#define JEFEFINAL_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
class JefeFinal:public QObject,public QGraphicsPixmapItem
{
Q_OBJECT
public:
    JefeFinal(QGraphicsItem *parent=nullptr);
public slots:
    void shoot();
    void move();
private:
    int direccion; //1 abajo -1 arriba
};

#endif // JEFEFINAL_H
