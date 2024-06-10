#include "vidadisplay.h"
#include <QFont>
VidaDisplay::VidaDisplay(QGraphicsItem *parent):QGraphicsTextItem(parent) {
    setPlainText(QString("Vidas: 3"));
    setDefaultTextColor(Qt::green);
    setFont(QFont("Blackadder ITC", 30));
}
void VidaDisplay::actualizarVida(int vida) {
    setPlainText(QString("Vidas: ") + QString::number(vida));
}
