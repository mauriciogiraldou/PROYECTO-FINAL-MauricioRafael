#include "disp.h"
#include "barquitoenemigo.h"
#include "barcoenemigo.h"
#include "jefefinal.h"
#include <cmath>
Disp::Disp(Puntaje *puntaje,QGraphicsItem *parent): puntajeDisplay(puntaje),QGraphicsPixmapItem(parent) {
    QPixmap pixmap(":/imagenes/bodoque.png");
    setPixmap(pixmap);
    setScale(0.40);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(80);
    velocidad = 65;
    angulo = 25;
    radianes = qDegreesToRadians(angulo);
    vx0 = velocidad * qCos(radianes);
    vy0 = velocidad * qSin(radianes);
    g = 9.8;
    t = 0.5;
    tiempoTotal = 0;
}
void Disp::move() {
    tiempoTotal += t;
    double nueva_x = x() + vx0 * t;
    double nueva_y = y() - (vy0 * tiempoTotal - 0.5 * g * tiempoTotal * tiempoTotal);
    setPos(nueva_x, nueva_y);
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(Barquitoenemigo)) {
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            puntajeDisplay->incrementar(10);
            return;
        } else if (typeid(*(colliding_items[i])) == typeid(Barcoenemigo)) {
            Barcoenemigo *enemy = dynamic_cast<Barcoenemigo *>(colliding_items[i]);
            if (enemy) {
                enemy->recibirDisparo();
                puntajeDisplay->incrementar(2);
            }
            scene()->removeItem(this);
            delete this;
            return;
        } else if (typeid(*(colliding_items[i])) == typeid(JefeFinal)) {
            JefeFinal *boss = dynamic_cast<JefeFinal *>(colliding_items[i]);
            if (boss) {
                boss->recibirDisparo();
                puntajeDisplay->incrementar(2);
            }
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
    if (pos().y() > 800 || pos().x() < 0 || pos().x() > 1400) {
        scene()->removeItem(this);
        delete this;
    }
}
