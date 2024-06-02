#include "nivel2.h"
#include <QGraphicsView>
Nivel2::Nivel2(QObject *parent)
    : QGraphicsScene(parent) {
    setBackgroundBrush(Qt::darkYellow); // Cambia el fondo a un color diferente para diferenciar el nivel
}

void Nivel2::startLevel() {
    // Mostrar mensaje de felicitaciones

}
