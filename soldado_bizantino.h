#ifndef SOLDADO_BIZANTINO_H
#define SOLDADO_BIZANTINO_H

#include <QObject>

class soldado_bizantino : public QObject
{
    Q_OBJECT
public:
    explicit soldado_bizantino(QObject *parent = nullptr);

signals:
};

#endif // SOLDADO_BIZANTINO_H
