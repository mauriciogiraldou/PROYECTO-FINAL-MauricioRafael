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
    if (puntaje->hasReached(95) && puntaje->getPuntaje() < 200) {
        smallEnemyTimer->stop();
        qDebug() << "Puntaje de 95 alcanzado, se detiene la aparición de enemigos pequeños.";
        return;
    }

    Barquitoenemigo *enemy = new Barquitoenemigo();
    scene->addItem(enemy);
}

void GameController::spawnLargeEnemy() {
    if (puntaje->hasReached(200)) {
        // Agregar tanto grandes como pequeños enemigos
        Barcoenemigo *largeEnemy = new Barcoenemigo();
        scene->addItem(largeEnemy);
        Barquitoenemigo *smallEnemy = new Barquitoenemigo();
        scene->addItem(smallEnemy);
        qDebug() << "Puntaje de 200 alcanzado, aparecen nuevos enemigos grandes y pequeños.";
    } else if (puntaje->hasReached(95)) {
        // Agregar solo grandes enemigos
        Barcoenemigo *largeEnemy = new Barcoenemigo();
        scene->addItem(largeEnemy);
        qDebug() << "Puntaje de 95 alcanzado, aparecen solo enemigos grandes.";
    }
}

void GameController::checkPuntaje() {
    if (puntaje->hasReached(200)) {
        if (!smallEnemyTimer->isActive()) {
            smallEnemyTimer->start(2000); // Reinicia el temporizador de pequeños enemigos con el mismo intervalo inicial
            qDebug() << "Puntaje de 200 alcanzado, reanuda la aparición de enemigos pequeños al ritmo inicial.";
        }
    }
}
