#include "puertadisplay.h"
#include <QFont>

PuertaDisplay::PuertaDisplay(QGraphicsItem *parent) : QGraphicsTextItem(parent) {
    setPlainText(QString("100")); // Inicializamos con 100
    setDefaultTextColor(Qt::Key_Green);
    setFont(QFont("times", 26));
}

void PuertaDisplay::actualizarVida(int vida) {
    setPlainText( QString::number(vida));
}
