#ifndef SOLDADO_OTOMANO_H
#define SOLDADO_OTOMANO_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class soldado_otomano: public QObject, public QGraphicsPixmapItem
{
public:
    soldado_otomano();
    void keyPressEvent(QKeyEvent *event) override;

private:
    int vidas;
    int velocidad;
};

#endif // SOLDADO_OTOMANO_H
