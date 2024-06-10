#include "puertadisplay.h"
#include <QFont>
PuertaDisplay::PuertaDisplay(QGraphicsItem *parent) : QGraphicsTextItem(parent) {
    setPlainText(QString("100")); // Inicializamos con 100
    setDefaultTextColor(Qt::green);
    setFont(QFont("time", 26));
}
void PuertaDisplay::actualizarVida(int vida) {
    setPlainText( QString::number(vida));
}
