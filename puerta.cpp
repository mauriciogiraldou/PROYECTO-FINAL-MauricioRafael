#include "puerta.h"
#include <QPixmap>
#include <QGraphicsScene>
#include <QDebug>
#include <QMessageBox>
#include <QApplication>

Puerta::Puerta(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent), vida(100) {
    QPixmap pixmap(":/imagenes/abrojo.png"); // Cambia esta ruta según tu archivo de imagen
    setPixmap(pixmap);
}

void Puerta::recibirDisparo() {
    vida -= 10; // Reduce la vida por cada disparo recibido
    qDebug()<<"poruqe me quitais"<<vida;
    emit vidaCambiada(vida);
    if (vida <= 0) {
        // Si la vida es menor o igual a 0, elimina la puerta de la escena
        scene()->removeItem(this);
        delete this;
        QMessageBox::information(nullptr, "You Win", "Has sobrepasado la defensa enemiga y destruido la puerta.");
        QCoreApplication::quit();
    }
}

int Puerta::getVida() const {
    return vida;
}
