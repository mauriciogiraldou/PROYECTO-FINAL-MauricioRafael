#include "escena.h"

Escena::Escena(QObject *parent):QGraphicsScene(parent){

}
/*void Escena::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    QPointF point = event -> scenePos();
    qDebug() << "Mouse click position:" << point;
    double angle=45;
    double speed=50;
    projectile *projecile=new projectile(point.x(),point.y(),angle,speed);
    addItem(projecile);
}

void Escena::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    QPointF point = event -> scenePos();
    qDebug() << "Mouse position:" << point;
    event->accept();
}

*/
