#ifndef PUERTA_H
#define PUERTA_H
#include <QGraphicsPixmapItem>
#include <QObject>
class Puerta : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Puerta(QGraphicsItem *parent = nullptr);
    void recibirDisparo();
    int getVida() const;
signals:
    void vidaCambiada(int nuevaVida);
private:
    int vida;
};

#endif // PUERTA_H
