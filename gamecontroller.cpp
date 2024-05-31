#include "gamecontroller.h"
#include "barquitoenemigo.h"
#include "barcoenemigo.h"
#include "jefefinal.h"
#include "bola.h"
#include <QDebug>

GameController::GameController(QGraphicsScene *scene, Puntaje *puntaje, QObject *parent)
    : QObject(parent), scene(scene), puntaje(puntaje), gameOver(false), jefeFinalSpawned(false) {
    smallEnemyTimer = new QTimer(this);
    largeEnemyTimer = new QTimer(this);
    puntajeCheckTimer = new QTimer(this); // Timer para verificar el puntaje
    bolaTimer = new QTimer(this);

    connect(smallEnemyTimer, &QTimer::timeout, this, &GameController::spawnSmallEnemy);
    connect(largeEnemyTimer, &QTimer::timeout, this, &GameController::spawnLargeEnemy);
    connect(puntajeCheckTimer, &QTimer::timeout, this, &GameController::checkPuntaje); // Conectar el timer para verificar el puntaje
    connect(bolaTimer, &QTimer::timeout, this, &GameController::spawnBola);
}

void GameController::start() {
    smallEnemyTimer->start(2000); // Ajusta el intervalo de tiempo según sea necesario para pequeños enemigos
    largeEnemyTimer->start(5000); // Ajusta el intervalo de tiempo según sea necesario para grandes enemigos
    puntajeCheckTimer->start(1000); // Verifica el puntaje cada segundo
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
        // Agregar tanto grandes como pequeños enemigos
        Barcoenemigo *largeEnemy = new Barcoenemigo();
        scene->addItem(largeEnemy);
        Barquitoenemigo *smallEnemy = new Barquitoenemigo();
        scene->addItem(smallEnemy);
        qDebug() << "Puntaje de 200 alcanzado, aparecen nuevos enemigos grandes y pequeños.";
    } else if (puntaje->hasReached(95) && puntaje->getPuntaje() < 200) {
        // Agregar solo grandes enemigos
        Barcoenemigo *largeEnemy = new Barcoenemigo();
        scene->addItem(largeEnemy);
        qDebug() << "Puntaje de 95 alcanzado, aparecen solo enemigos grandes.";
    }
}

void GameController::checkPuntaje() {
    qDebug() << "Verificando puntaje. Puntaje actual: " << puntaje->getPuntaje();

    if (puntaje->hasReached(200) && puntaje->getPuntaje() < 400) {
        if (!smallEnemyTimer->isActive()) {
            smallEnemyTimer->start(2000); // Reinicia el temporizador de pequeños enemigos con el mismo intervalo inicial
            qDebug() << "Puntaje de 200 alcanzado, reanuda la aparición de enemigos pequeños al ritmo inicial.";
        }
    }

    if (puntaje->hasReached(400) && !jefeFinalSpawned) {
        // Detener la aparición de otros enemigos
        smallEnemyTimer->stop();
        largeEnemyTimer->stop();

        // Generar el jefe final
        JefeFinal *boss = new JefeFinal();
        scene->addItem(boss);

        // Iniciar la caída de bolas
        bolaTimer->start(4000); // Ajusta el intervalo de tiempo según sea necesario para las bolas

        jefeFinalSpawned = true;
        qDebug() << "Puntaje de 400 alcanzado, aparece el jefe final.";
    }
}

void GameController::spawnBola() {
    Bola *bola = new Bola();
    scene->addItem(bola);
}
