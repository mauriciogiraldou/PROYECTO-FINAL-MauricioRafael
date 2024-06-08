#ifndef MURO_H
#define MURO_H
#include <QGraphicsPixmapItem>
class Muro:public QGraphicsPixmapItem
{
public:
    Muro(qreal x, qreal y, const QString& rutaImagen);
};

#endif // MURO_H
