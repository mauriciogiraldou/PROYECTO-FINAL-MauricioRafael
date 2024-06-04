#include "soldado_otomano.h"
#include "disp.h"
#include "puntaje.h"

soldado_otomano::soldado_otomano(): vidas(3),velocidad(10) {
    QPixmap personaje_principal(":/imagenes/caballo_o_abajo.png");
    setPixmap(personaje_principal);
    setScale(0.78);
}

void soldado_otomano::keyPressEvent(QKeyEvent *event){

    if (event->key() == Qt::Key_A){
        setPixmap(QPixmap(":/imagenes/caballo_o_izquierda.png"));

        moveBy(-velocidad, 0);
    }
    else if (event->key() == Qt::Key_D){
        setPixmap(QPixmap(":/imagenes/caballo_o_derecha.png"));
        moveBy(velocidad, 0);
    }
    else if (event->key() == Qt::Key_W){
        setPixmap(QPixmap(":/imagenes/caballo_o_arriba.png"));
        moveBy(0, -velocidad);
    }
    else if (event->key() == Qt::Key_S){
        setPixmap(QPixmap(":/imagenes/caballo_o_abajo.png"));
        moveBy(0, velocidad);
    }
    else if(event->key()==Qt::Key_Space){
        Disp *bullet=new Disp(puntajeDisplay);
        bullet->setPos(x()+130,y()+130);
        scene()->addItem(bullet);

    }
}

