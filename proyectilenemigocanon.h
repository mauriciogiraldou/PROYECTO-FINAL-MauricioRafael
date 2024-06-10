#ifndef PROYECTILENEMIGOCANON_H
#define PROYECTILENEMIGOCANON_H
#include <QObject>
#include <QGraphicsPixmapItem>
class ProyectilEnemigoCanon : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit ProyectilEnemigoCanon(QGraphicsItem *parent = nullptr);

public slots:
    void move2(); // Método para el movimiento vertical
};

#endif // PROYECTILENEMIGOCANON_H
