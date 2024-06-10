#ifndef GAMECONTROLLERNIVEL2_H
#define GAMECONTROLLERNIVEL2_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include "soldado_bizantino.h"
#include "polvoradisplay.h"
#include "soldado_otomano.h"
#include "canon.h"
#include "puertadisplay.h"
#include "puerta.h"

class GameControllerNivel2 : public QObject {
    Q_OBJECT
public:
    explicit GameControllerNivel2(QGraphicsScene *scene,soldado_otomano *jugador,Canon *canon,Puerta *puerta, QObject *parent = nullptr);
    ~GameControllerNivel2();

private slots:
    void spawnEnemigo();
public slots:
    void recolectarPolvora();
private:
    QGraphicsScene *scene;
    QTimer *spawnTimer;
    PolvoraDisplay *polvoraDisplay;
    PuertaDisplay *puertaDisplay;
    soldado_otomano *jugador;
    Canon *canon;
    Puerta *puerta;
};

#endif // GAMECONTROLLERNIVEL2_H
