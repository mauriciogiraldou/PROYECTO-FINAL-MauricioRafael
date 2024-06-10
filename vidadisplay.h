#ifndef VIDADISPLAY_H
#define VIDADISPLAY_H
#include <QGraphicsTextItem>
class VidaDisplay:public QGraphicsTextItem
{
public:
    VidaDisplay(QGraphicsItem *parent= nullptr);
    void actualizarVida(int vida);
};

#endif // VIDADISPLAY_H
