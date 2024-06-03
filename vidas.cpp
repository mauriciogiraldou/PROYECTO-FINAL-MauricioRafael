    #include "vidas.h"

    Vidas::Vidas(int vid, QGraphicsItem *parent): QGraphicsTextItem(parent) {
        vida = vid;
        int id = QFontDatabase::addApplicationFont(":/CoinCount2.ttf");
        QFontDatabase::applicationFontFamilies(id);

        setPlainText(QString("Vidas: ") + QString::number(vida));
        setDefaultTextColor(Qt::white);
        setFont(QFont("CoinCount2", 25));
    }

    void Vidas::decrementar() {
        vida--;
        setPlainText(QString("Vidas: ") + QString::number(vida));

    }

    int Vidas::getPuntaje() {
        return vida;
    }
