#include "polvoradisplay.h"
#include <QFont>

PolvoraDisplay::PolvoraDisplay(QGraphicsItem *parent)
    : QGraphicsTextItem(parent), polvora(0) {
    setPlainText(QString("Polvora: ") + QString::number(polvora));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 26));
}

void PolvoraDisplay::aumentarPolvora(int cantidad) {
    polvora += cantidad;
    setPlainText(QString("Pólvora: ") + QString::number(polvora));
}

int PolvoraDisplay::getPolvora() const {
    return polvora;
}
