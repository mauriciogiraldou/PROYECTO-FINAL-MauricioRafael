#include "gamecontrollernivel2.h"
#include "soldado_bizantino.h"
#include "soldado_otomano.h"

GameControllerNivel2::GameControllerNivel2(QGraphicsScene *scene, QObject *parent)
    : QObject(parent), scene(scene) {
    spawnTimer = new QTimer(this);
    connect(spawnTimer, &QTimer::timeout, this, &GameControllerNivel2::spawnEnemigo);
    spawnTimer->start(5000); // Spawn enemigo cada 2 segundos

}

GameControllerNivel2::~GameControllerNivel2() {
    delete spawnTimer;
}

void GameControllerNivel2::spawnEnemigo() {
    soldado_bizantino *enemigo = new soldado_bizantino();
    // Posición inicial del enemigo
    enemigo->setPos(rand() % 1200,  600); // Ajusta las coordenadas según sea necesario
    scene->addItem(enemigo);

}
