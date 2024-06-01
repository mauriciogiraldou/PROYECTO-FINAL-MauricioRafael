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
signals:
    void changeScene(QGraphicsScene *newScene);

private slots:
    void spawnSmallEnemy();
    void spawnLargeEnemy();
    void checkPuntaje();
    void spawnBola(); // Añadir esta función para manejar la caída de bolas
    void onJefeFinalDerrotado();
private:
    void clearScene();
    QGraphicsScene *scene;
    Puntaje *puntaje;
    QTimer *smallEnemyTimer;
    QTimer *largeEnemyTimer;
    QTimer *puntajeCheckTimer;
    QTimer *bolaTimer; // Añadir un temporizador para las bolas
    bool jefeFinalSpawned;
    bool gameOver;
};

#endif // GAMECONTROLLER_H
