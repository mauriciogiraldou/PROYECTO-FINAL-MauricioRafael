#ifndef VIDAS_H
#define VIDAS_H

#include <QGraphicsTextItem>
#include <QFontDatabase>
#include <QFont>

class Vidas : public QGraphicsTextItem {
public:
    Vidas(int vid, QGraphicsItem *parent = nullptr);

    void decrementar();
    int getPuntaje();

private:
    int vida;
};

#endif // VIDAS_H
