// nivel2.h
#ifndef NIVEL2_H
#define NIVEL2_H

#include <QGraphicsScene>
#include <QGraphicsTextItem>

class Nivel2 : public QGraphicsScene {
    Q_OBJECT
public:
    Nivel2(QObject *parent = nullptr);

    void startLevel();
private:
    QGraphicsTextItem *congratulationsText;
};

#endif // NIVEL2_H
