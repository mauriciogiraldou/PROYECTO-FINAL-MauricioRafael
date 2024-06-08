#include "muro.h"
Muro::Muro(qreal x, qreal y, const QString &rutaImagen) {
    QPixmap imagen(rutaImagen);
    if (!imagen.isNull()) {
        this->setPixmap(imagen);
        this->setPos(x, y);
    }
    else {
        // Si hay error entonces...
        qDebug() << "Error: No se pudo cargar la imagen desde la ruta" << rutaImagen;
    }

}
