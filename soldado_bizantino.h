#ifndef SOLDADO_BIZANTINO_H
#define SOLDADO_BIZANTINO_H

#include <QObject>
#include <QTimer>
#include <QGraphicsPixmapItem>

class soldado_bizantino : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit soldado_bizantino(QGraphicsItem *parent = nullptr);
public slots:
    void followPlayer();

private:
    QTimer *movementTimer;
    QGraphicsItem *player; // Pointer to the player to follow
    int velocidad;

    void updateImage();
};

#endif // SOLDADO_BIZANTINO_H
