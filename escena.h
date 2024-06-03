#ifndef ESCENA_H
#define ESCENA_H
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
class Escena: public QGraphicsScene
{
Q_OBJECT
public:
    Escena(QObject *parent = nullptr);
protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // ESCENA_H
