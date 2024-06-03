#include "nivel2.h"
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
Nivel2::Nivel2(QObject *parent)
    : QGraphicsScene(parent) {
    // Cambia el fondo a un color diferente para diferenciar el nivel

}

void Nivel2::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    QPointF point = event -> scenePos();
    qDebug() << "Mouse position:" << point;
    event->accept();
}


