#ifndef GAMECONTROLLERNIVEL2_H
#define GAMECONTROLLERNIVEL2_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include "soldado_bizantino.h"

class GameControllerNivel2 : public QObject {
    Q_OBJECT
public:
    explicit GameControllerNivel2(QGraphicsScene *scene, QObject *parent = nullptr);
    ~GameControllerNivel2();

private slots:
    void spawnEnemigo();
private:
    QGraphicsScene *scene;
    QTimer *spawnTimer;
};

#endif // GAMECONTROLLERNIVEL2_H
