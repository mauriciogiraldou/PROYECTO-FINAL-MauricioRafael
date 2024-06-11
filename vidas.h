#ifndef VIDAS_H
#define VIDAS_H
#include <QGraphicsTextItem>
#include <QFont>
class Vidas : public QGraphicsTextItem {
public:
    Vidas(int vid, QGraphicsItem *parent = nullptr);

    void decrementar();
    int getPuntaje();
    int getVidas();
private:
    int vida;
};

#endif // VIDAS_H
