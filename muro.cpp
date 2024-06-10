#include "muro.h"
#include <QDebug>
Muro::Muro(qreal x, qreal y, const QString &rutaImagen) {
    QPixmap imagen(rutaImagen);
    if (!imagen.isNull()) {
        this->setPixmap(imagen);
        this->setPos(x, y);
    }
    else {
        qDebug() << "Error: No se pudo cargar la imagen desde la ruta" << rutaImagen;
    }

}
