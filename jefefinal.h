#ifndef JEFEFINAL_H
#define JEFEFINAL_H

#include <QGraphicsPixmapItem>
#include <QObject>

class JefeFinal : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    JefeFinal(QGraphicsItem *parent = nullptr);
    void recibirDisparo(); // Función para reducir la vida cuando el jefe recibe un disparo
    int getVida() const;
    int getMaxVida() const;
public slots:
    void move();
    void shoot();

private:
    int vida;
    int maxVida;
    int direccion; // 1 for down, -1 for up
};

#endif // JEFEFINAL_H
