#include "gamecontrollernivel2.h"
#include "soldado_bizantino.h"
#include "soldado_otomano.h"
#include "polvora.h"


GameControllerNivel2::GameControllerNivel2(QGraphicsScene *scene,soldado_otomano *jugador,Canon *canon, QObject *parent)
    : QObject(parent), scene(scene),jugador(jugador),canon(canon) {
    polvoraDisplay = new PolvoraDisplay();
    scene->addItem(polvoraDisplay);
    polvoraDisplay->setPos(500, 10);
    spawnTimer = new QTimer(this);
    connect(spawnTimer, &QTimer::timeout, this, &GameControllerNivel2::spawnEnemigo);
    spawnTimer->start(5000); // Spawn enemigo cada 2 segundos
    foreach (QGraphicsItem *item, scene->items()) {
        if (auto soldado = dynamic_cast<soldado_bizantino*>(item)) {
            connect(soldado, &soldado_bizantino::soldadoMuerto, this, &GameControllerNivel2::recolectarPolvora);
        }
    }

}

GameControllerNivel2::~GameControllerNivel2() {
    delete spawnTimer;
}

void GameControllerNivel2::spawnEnemigo() {
    soldado_bizantino *enemigo = new soldado_bizantino();
    // Posición inicial del enemigo
    enemigo->setPos(rand() % 1200,  600); // Ajusta las coordenadas según sea necesario
    scene->addItem(enemigo);
    connect(enemigo, &soldado_bizantino::soldadoMuerto, this, &GameControllerNivel2::recolectarPolvora);
}
void GameControllerNivel2::recolectarPolvora() {
    // Generar pólvora con cierta probabilidad
    if (rand() % 2 == 0) { // 50% de probabilidad
        Polvora *polvora = new Polvora();
        polvora->setPos(rand() % 1200, rand() % 600); // Posición aleatoria
        connect(polvora, &Polvora::polvoraRecolectada, [this]() {
            polvoraDisplay->aumentarPolvora(1);
        });
        scene->addItem(polvora);
        polvora->setZValue(1);
    }
}

