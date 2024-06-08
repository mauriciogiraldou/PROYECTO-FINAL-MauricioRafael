#include "barquito.h"
#include <QDebug>
#include <QCoreApplication>
#include <QMessageBox>
Barquito::Barquito(QGraphicsItem *parent):QGraphicsPixmapItem(parent),vidas(3)
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
        setPos(x()+velocidad,y());
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

    //qDebug()<<"te quite una vida" <<vidas;
    if (vidasDisplay) {
        vidasDisplay->decrementar();
    }
    if (vidasDisplay->getVidas() == 0) {
        scene()->removeItem(this);
        delete this;
        if (this->scene() == nullptr) {
            // Objeto eliminado, muestra el mensaje y cierra la aplicación
            //QMessageBox::information(nullptr, "Game Over", "Has sido atrapado por un enemigo. Juego terminado.");
            //QCoreApplication::quit();
        }

    }
}
void Barquito::incrementarPuntaje(int puntos) {
    if (puntajeDisplay) {
        puntajeDisplay->incrementar(puntos);
    }
}
