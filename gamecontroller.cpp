#include "gamecontroller.h"
#include "barquitoenemigo.h"
#include "barcoenemigo.h"
#include <QDebug>

GameController::GameController(QGraphicsScene *scene, Puntaje *puntaje, QObject *parent)
    : QObject(parent), scene(scene), puntaje(puntaje), gameOver(false) {
    smallEnemyTimer = new QTimer(this);
    largeEnemyTimer = new QTimer(this);

    connect(smallEnemyTimer, &QTimer::timeout, this, &GameController::spawnSmallEnemy);
    connect(largeEnemyTimer, &QTimer::timeout, this, &GameController::spawnLargeEnemy);
}

void GameController::start() {
    smallEnemyTimer->start(2000); // Ajusta el intervalo de tiempo según sea necesario para pequeños enemigos
    largeEnemyTimer->start(5000); // Ajusta el intervalo de tiempo según sea necesario para grandes enemigos
}

void GameController::spawnSmallEnemy() {
    if (puntaje->hasReached(95) && !puntaje->hasReached(200)) {
        smallEnemyTimer->stop();
        qDebug() << "Puntaje de 95 alcanzado, se detiene la aparición de enemigos pequeños.";
        return;
    }

    Barquitoenemigo *enemy = new Barquitoenemigo();
    scene->addItem(enemy);
}

void GameController::spawnLargeEnemy() {
    if (puntaje->hasReached(5) && puntaje->hasReached(95) && puntaje->hasReached(200)) {
        Barcoenemigo *enemy2 = new Barcoenemigo();
        scene->addItem(enemy2);
        qDebug() << "Puntaje de 200 alcanzado, aparecen nuevos enemigos grandes y pequeños.";
        return;
    } else if (puntaje->hasReached(5) && puntaje->hasReached(95)) {
        Barcoenemigo *enemy2 = new Barcoenemigo();
        scene->addItem(enemy2);
        qDebug() << "Puntaje de 95 alcanzado, aparecen solo enemigos grandes.";
        return;
    }
}

void GameController::checkPuntaje() {
    if (puntaje->hasReached(200)) {
        if (!smallEnemyTimer->isActive()) {
            smallEnemyTimer->start(2000); // Reinicia el temporizador de pequeños enemigos
            qDebug() << "Puntaje de 200 alcanzado, reanuda la aparición de enemigos pequeños.";
        }
    }
}
