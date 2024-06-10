#ifndef POLVORADISPLAY_H
#define POLVORADISPLAY_H
#include <QGraphicsTextItem>
#include <QObject>
class PolvoraDisplay : public QGraphicsTextItem {

public:
    PolvoraDisplay(QGraphicsItem *parent = nullptr);
    void aumentarPolvora(int cantidad);
    int getPolvora() const;
private:
    int polvora;
};

#endif // POLVORADISPLAY_H
