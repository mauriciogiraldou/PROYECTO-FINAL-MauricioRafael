#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QGraphicsItem>
#include <QRectF>
#include <QScreen>
#include <QGuiApplication>
#include <QApplication>
#include <QDebug>
#include <QGraphicsScene>

#include "sprite.h" //Libreria propia, no de Qt.

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QGraphicsScene *scene;

    sprite *Jinete_1;

    int x, y, ancho, alto;
};
#endif // WIDGET_H
