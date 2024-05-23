#include "projectile.h"


projectile::projectile(double startX,double startY,double angle,double speed,QGraphicsItem *parent)
    :QObject(), QGraphicsEllipseItem(parent), startX(startX), startY(startY), angle(angle), speed(speed), time(0), gravity(9.81)
{
    setRect(0,0,10,10);
    timer=new QTimer(this);
    connect(timer,&QTimer::timeout,this,&projectile::updatePosition);
    timer->start(50);
}
void projectile::updatePosition(){
    time+=0.05;
    double radianangle= qDegreesToRadians(angle);
    double newX=startX+speed*cos(radianangle)*time;
    double newY=startY- (speed*sin(radianangle )*time-0.5*gravity*time*time);
    setPos(newX,newY);
    if(newY>scene()->height()||newX>scene()->width()){
        timer->stop();
    }
}
