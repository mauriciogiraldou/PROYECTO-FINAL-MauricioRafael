#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include "puntaje.h"

class GameController : public QObject {
    Q_OBJECT
public:
    GameController(QGraphicsScene *scene, Puntaje *puntaje, QObject *parent = nullptr);
    void start();

public slots:
    void spawnSmallEnemy();
    void spawnLargeEnemy();
    void checkPuntaje();

private:
    QGraphicsScene *scene;
    Puntaje *puntaje;
    bool gameOver;
    bool jefeFinalSpawned;
    QTimer *smallEnemyTimer;
    QTimer *largeEnemyTimer;
    QTimer *puntajeCheckTimer;  // Timer para verificar el puntaje regularmente
};

#endif // GAMECONTROLLER_H
