#include "sprite.h"

sprite::sprite(QObject *parent)
    : QObject{parent}
{
    temporizador = new QTimer();

    fila = 0;
    columna = 0;
    mapaBits = new QPixmap(":/Imagenes/sprites jinete protagonista.png"); //direccion de la imagen de pixeles.
    // Dimension de cada uno de los fotogramas es (400 x 400) pixeles.
    ancho = 400;
    alto = 400;

    temporizador->start(100);//milisegundos.

    connect(temporizador, &QTimer::timeout, this, &sprite::fotogramaActual);
}

void sprite::fotogramaActual()
{
    columna += 400;
    if (columna >= 1200){
        columna = 0; //para que se devuelva al principio.
    }

    this->update(-ancho/2,-alto/2, ancho, alto);
}

QRectF sprite::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2, ancho, alto);
}

void sprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
   // painter->drawPixmap(-ancho/2,-alto/2,ancho,*mapaBits,columna,0,ancho,alto);//Funcion sobrecargada 11 veces
    painter->drawPixmap(-ancho/2,-alto/2,*mapaBits,columna, 800, ancho,alto);
}

