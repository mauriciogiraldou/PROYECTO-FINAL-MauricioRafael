#include "gamecontroller.h"
#include "barquitoenemigo.h"
#include "barcoenemigo.h"
#include "jefefinal.h"
#include "bola.h"
#include "nivel2.h"
#include <QDebug>

GameController::GameController(QGraphicsScene *scene, Puntaje *puntaje, QObject *parent)
    : QObject(parent), scene(scene), puntaje(puntaje), gameOver(false), jefeFinalSpawned(false) {
    smallEnemyTimer = new QTimer(this);
    largeEnemyTimer = new QTimer(this);
    puntajeCheckTimer = new QTimer(this);
    bolaTimer = new QTimer(this);

    connect(smallEnemyTimer, &QTimer::timeout, this, &GameController::spawnSmallEnemy);
    connect(largeEnemyTimer, &QTimer::timeout, this, &GameController::spawnLargeEnemy);
    connect(puntajeCheckTimer, &QTimer::timeout, this, &GameController::checkPuntaje);
    connect(bolaTimer, &QTimer::timeout, this, &GameController::spawnBola);
}

void GameController::start() {
    smallEnemyTimer->start(2000);
    largeEnemyTimer->start(5000);
    puntajeCheckTimer->start(1000);
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
    if (puntaje->hasReached(200) && puntaje->getPuntaje() < 400) {
        Barcoenemigo *largeEnemy = new Barcoenemigo();
        scene->addItem(largeEnemy);
        Barquitoenemigo *smallEnemy = new Barquitoenemigo();
        scene->addItem(smallEnemy);
        qDebug() << "Puntaje de 200 alcanzado, aparecen nuevos enemigos grandes y pequeños.";
    } else if (puntaje->hasReached(95) && puntaje->getPuntaje() < 200) {
        Barcoenemigo *largeEnemy = new Barcoenemigo();
        scene->addItem(largeEnemy);
        qDebug() << "Puntaje de 95 alcanzado, aparecen solo enemigos grandes.";
    }
}

void GameController::checkPuntaje() {
    //qDebug() << "Verificando puntaje. Puntaje actual: " << puntaje->getPuntaje();

    if (puntaje->hasReached(200) && puntaje->getPuntaje() < 400) {
        if (!smallEnemyTimer->isActive()) {
            smallEnemyTimer->start(2000);
            qDebug() << "Puntaje de 200 alcanzado, reanuda la aparición de enemigos pequeños al ritmo inicial.";
        }
    }

    if (puntaje->hasReached(400) && !jefeFinalSpawned) {
        smallEnemyTimer->stop();
        largeEnemyTimer->stop();

        JefeFinal *boss = new JefeFinal();
        connect(boss, &JefeFinal::jefeDerrotado, this, &GameController::onJefeFinalDerrotado);
        scene->addItem(boss);

        bolaTimer->start(4000);

        jefeFinalSpawned = true;
        qDebug() << "Puntaje de 400 alcanzado, aparece el jefe final.";
    }
}

void GameController::spawnBola() {
    Bola *bola = new Bola();
    scene->addItem(bola);
}

void GameController::onJefeFinalDerrotado() {
    bolaTimer->stop();

    Nivel2 *nivel2 = new Nivel2();
    emit changeScene(nivel2);
    nivel2->startLevel();

    qDebug() << "Jefe final derrotado, cambiando a Nivel 2.";
}
void GameController::clearScene() {
    QList<QGraphicsItem *> items = scene->items();
    for (QGraphicsItem *item : items) {
        scene->removeItem(item);
        delete item;
    }

    smallEnemyTimer->stop();
    largeEnemyTimer->stop();
    puntajeCheckTimer->stop();
    bolaTimer->stop();

    gameOver = false;
    jefeFinalSpawned = false;
}
