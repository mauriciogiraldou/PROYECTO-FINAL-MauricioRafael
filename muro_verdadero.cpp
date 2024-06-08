#include "muro_verdadero.h"
#include <QBrush>
Muro_verdadero::Muro_verdadero(qreal x, qreal y, qreal ancho, qreal alto){
    setRect(x, y, ancho, alto);
    setBrush(QColor(122, 95, 122));
}
