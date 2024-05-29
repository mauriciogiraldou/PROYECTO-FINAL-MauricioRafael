#include "gamecontroller.h"

GameController::GameController(QGraphicsScene *scene, Puntaje *puntaje, QObject *parent)
    : QObject(parent), scene(scene), puntaje(puntaje), gameOver(false) {
    spawnTimer = new QTimer(this);
    connect(spawnTimer, &QTimer::timeout, this, &GameController::spawnEnemy);
}

void GameController::start() {
    spawnTimer->start(2000); // Ajusta el intervalo de tiempo según sea necesario
}

void GameController::spawnEnemy() {
    if (puntaje->hasReached(50)) {
        spawnTimer->stop();
        qDebug() << "Puntaje de 50 alcanzado, se detiene la aparición de enemigos.";
        return;
    }

    Barquitoenemigo *enemy = new Barquitoenemigo();
    scene->addItem(enemy);
}
