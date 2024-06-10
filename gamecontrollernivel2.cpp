#include "gamecontrollernivel2.h"
#include "soldado_bizantino.h"
#include "soldado_otomano.h"
#include "polvora.h"
GameControllerNivel2::GameControllerNivel2(QGraphicsScene *scene,soldado_otomano *jugador,Canon *canon,Puerta *puerta, QObject *parent)
    : QObject(parent), scene(scene),jugador(jugador),canon(canon),puerta(puerta) {
    polvoraDisplay = new PolvoraDisplay();
    scene->addItem(polvoraDisplay);
    polvoraDisplay->setPos(150, 3);
    puertaDisplay = new PuertaDisplay();
    puertaDisplay->setZValue(4);
    scene->addItem(puertaDisplay);
    puertaDisplay->setPos(670, 650);
    vidaDisplay=new VidaDisplay();
    scene->addItem(vidaDisplay);
    vidaDisplay->setPos(10,3);
    connect(jugador,&soldado_otomano::vidaCambiada,vidaDisplay,&VidaDisplay::actualizarVida);
    connect(puerta, &Puerta::vidaCambiada, puertaDisplay, &PuertaDisplay::actualizarVida);
    spawnTimer = new QTimer(this);
    connect(spawnTimer, &QTimer::timeout, this, &GameControllerNivel2::spawnEnemigo);
    spawnTimer->start(5000);
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
    enemigo->setPos(rand() % 1200,  600);
    scene->addItem(enemigo);
    connect(enemigo, &soldado_bizantino::soldadoMuerto, this, &GameControllerNivel2::recolectarPolvora);
}
void GameControllerNivel2::recolectarPolvora() {
    if (rand() % 2 == 0) {
        Polvora *polvora = new Polvora();
        polvora->setPos(rand() % 1200, rand() % 600);
        connect(polvora, &Polvora::polvoraRecolectada, [this]() {
            polvoraDisplay->aumentarPolvora(1);
        });
        scene->addItem(polvora);
        polvora->setZValue(1);
    }
}

