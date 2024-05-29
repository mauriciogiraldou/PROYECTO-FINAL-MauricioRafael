#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include "puntaje.h"
#include "barquitoenemigo.h"

class GameController : public QObject {
    Q_OBJECT
public:
    GameController(QGraphicsScene *scene, Puntaje *puntaje, QObject *parent = nullptr);
    void start();

public slots:
    void spawnEnemy();

private:
    QGraphicsScene *scene;
    Puntaje *puntaje;
    QTimer *spawnTimer;
    bool gameOver;
};

#endif // GAMECONTROLLER_H
