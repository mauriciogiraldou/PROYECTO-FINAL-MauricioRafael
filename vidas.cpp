#include "vidas.h"
Vidas::Vidas(int vid, QGraphicsItem *parent): QGraphicsTextItem(parent) {
    vida = vid;
    setPlainText(QString("Vidas: ") + QString::number(vida));
    setDefaultTextColor(Qt::white);
    setFont(QFont("Blackadder ITC", 30));
}
void Vidas::decrementar() {
    vida--;
    setPlainText(QString("Vidas: ") + QString::number(vida));
}
int Vidas::getPuntaje() {
    return vida;
}
int Vidas::getVidas(){
    return vida;
}
