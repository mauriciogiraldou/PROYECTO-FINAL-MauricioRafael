#ifndef CANON_H
#define CANON_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

class Canon : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Canon(int initialHealth, QGraphicsItem *parent = nullptr);
    void recibirDano(int cantidad);
    int getVida() const;
    void disparar();
signals:
    void proyectilDisparado();
private slots:
    void moveProyectil();
private:
    int vida;
};

#endif // CANON_H
