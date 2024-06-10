#ifndef NIVEL2_H
#define NIVEL2_H
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
class Nivel2 : public QGraphicsScene {
    Q_OBJECT
public:
    Nivel2(QObject *parent = nullptr);
protected:
    //void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // NIVEL2_H
