#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <QGraphicsEllipseItem>
#include <Qtimer>
#include <QGraphicsScene>
#include <QObject>
#include <QtMath>

class projectile:public QObject,public QGraphicsEllipseItem
{
public:
    projectile(double startX,double startY,double angle,double speed,QGraphicsItem *parent=nullptr);
public slots:
    void updatePosition();
private:
    double time;
    double startX;
    double startY;
    double angle;
    double speed;
    double gravity;
    QTimer *timer;
};

#endif // PROJECTILE_H
