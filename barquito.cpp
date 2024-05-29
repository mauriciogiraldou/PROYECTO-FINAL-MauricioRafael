#include "barquito.h"
Barquito::Barquito(QGraphicsItem *parent):QGraphicsPixmapItem(parent)
{
    QPixmap pixmap(":/imagenes/barco protagonista.png");
    setPixmap(pixmap);
    setScale(0.40);
    setPos(0,0);
}
void Barquito::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_A){
        //Definimos limites para el movimiento del barco
        if(x()>-10)
        setPos(x()-velocidad,y());

    }
    else if(event->key()==Qt::Key_D){
        if(x()<1080)
        setPos(x()+10,y());
    }
    else if(event->key()==Qt::Key_W){
        if(y()>-10)
        setPos(x(),y()-velocidad);

    }
    else if(event->key()==Qt::Key_S){
        if(y()<570)
        setPos(x(),y()+velocidad);

    }
    else if(event->key()==Qt::Key_Space){
        Disp *bullet=new Disp(puntajeDisplay);
        bullet->setPos(x()+130,y()+130);
        scene()->addItem(bullet);

    }
}
void Barquito::reducirVidas() {
    vidas--;
    qDebug() << "Vidas restantes: " << vidas;
    if (vidasDisplay) {
        vidasDisplay->decrementar();
    }
    if (vidas <= 0) {
        qDebug() << "Game Over!";
        scene()->removeItem(this);
        delete this;
    }
}
void Barquito::incrementarPuntaje(int puntos) {
    if (puntajeDisplay) {
        puntajeDisplay->incrementar(puntos);
    }
}
