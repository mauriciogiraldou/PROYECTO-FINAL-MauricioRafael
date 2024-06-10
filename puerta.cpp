#include "puerta.h"
#include <QPixmap>
#include <QGraphicsScene>
#include <QMessageBox>
#include <QApplication>
Puerta::Puerta(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent), vida(100) {
    QPixmap pixmap(":/imagenes/abrojo.png");
    setPixmap(pixmap);
}
void Puerta::recibirDisparo() {
    vida -= 10;
    emit vidaCambiada(vida);
    if (vida <= 0) {
        scene()->removeItem(this);
        delete this;
        QMessageBox::information(nullptr, "You Win", "Has sobrepasado la defensa enemiga y destruido la puerta.");
        QCoreApplication::quit();
    }
}

int Puerta::getVida() const {
    return vida;
}
