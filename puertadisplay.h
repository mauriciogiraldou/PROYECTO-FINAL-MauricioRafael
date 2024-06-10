#ifndef PUERTADISPLAY_H
#define PUERTADISPLAY_H
#include <QGraphicsTextItem>
class PuertaDisplay : public QGraphicsTextItem {
public:
    PuertaDisplay(QGraphicsItem *parent = nullptr);
    void actualizarVida(int vida);
};

#endif // PUERTADISPLAY_H
