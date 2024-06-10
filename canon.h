#ifndef CANON_H
#define CANON_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
class Canon : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Canon(QGraphicsItem *parent = nullptr);
    void shoot();

};

#endif // CANON_H
