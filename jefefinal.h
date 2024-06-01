#ifndef JEFEFINAL_H
#define JEFEFINAL_H

#include <QGraphicsPixmapItem>
#include <QObject>

class JefeFinal : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    JefeFinal(QGraphicsItem *parent = nullptr);
    void recibirDisparo();
    int getVida() const;

signals:
    void jefeDerrotado();

private slots:
    void move();
    void shoot();

private:
    int direccion;
    int vida;
};

#endif // JEFEFINAL_H
