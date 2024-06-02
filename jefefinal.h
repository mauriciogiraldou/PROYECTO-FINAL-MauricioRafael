#ifndef JEFEFINAL_H
#define JEFEFINAL_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

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
    void checkCollisions();
    QTimer *collisionTimer;
};

#endif // JEFEFINAL_H
