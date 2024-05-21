#ifndef SPRITE_H
#define SPRITE_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class sprite : public QObject, public QGraphicsItem
{
public:
    explicit sprite(QObject *parent = nullptr);

    QTimer *temporizador;
    QPixmap *mapaBits;

    int fila, columna;

    int alto, ancho;

    QRectF boundingRect() const; //clase heredada de QGraphicsItem.
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //para graficar fotogramas.

signals:

public slots:
    void fotogramaActual();
};

#endif // SPRITE_H
