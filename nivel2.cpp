#include "nivel2.h"
#include <QGraphicsView>
Nivel2::Nivel2(QObject *parent)
    : QGraphicsScene(parent), congratulationsText(nullptr) {
    setBackgroundBrush(Qt::blue); // Cambia el fondo a un color diferente para diferenciar el nivel
}

void Nivel2::startLevel() {
    // Mostrar mensaje de felicitaciones
    congratulationsText = new QGraphicsTextItem("¡Felicitaciones! Ha llegado a tierra.");
    congratulationsText->setFont(QFont("Arial", 24));
    congratulationsText->setDefaultTextColor(Qt::white);
    addItem(congratulationsText);

    // Posicionar el texto en el centro de la escena
    qreal xPos = width() / 2 - congratulationsText->boundingRect().width() / 2;
    qreal yPos = height() / 2 - congratulationsText->boundingRect().height() / 2;
    congratulationsText->setPos(xPos, yPos);
}
