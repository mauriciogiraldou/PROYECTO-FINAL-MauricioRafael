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
    void clearScene();
signals:
    void changeScene(QGraphicsScene *newScene);

private slots:
    void spawnSmallEnemy();
    void spawnLargeEnemy();
    void checkPuntaje();
    void spawnBola();
    void onJefeFinalDerrotado();
private:
    QGraphicsScene *scene;
    Puntaje *puntaje;
    QTimer *smallEnemyTimer;
    QTimer *largeEnemyTimer;
    QTimer *puntajeCheckTimer;
    QTimer *bolaTimer;
    bool jefeFinalSpawned;
    bool gameOver;
};

#endif // GAMECONTROLLER_H
