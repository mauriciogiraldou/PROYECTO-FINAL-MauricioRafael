QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    barcoenemigo.cpp \
    barquito.cpp \
    barquitoenemigo.cpp \
    bola.cpp \
    canon.cpp \
    disp.cpp \
    escena.cpp \
    gamecontroller.cpp \
    gamecontrollernivel2.cpp \
    jefefinal.cpp \
    jefeproyectil.cpp \
    main.cpp \
    mainwindow.cpp \
    muro.cpp \
    muro_verdadero.cpp \
    nivel2.cpp \
    polvora.cpp \
    polvoradisplay.cpp \
    powerup.cpp \
    powerupdano.cpp \
    powerupvelocidad.cpp \
    powerupvida.cpp \
    proyectil.cpp \
    proyectilenemigo.cpp \
    proyectilenemigocanon.cpp \
    puerta.cpp \
    puertadisplay.cpp \
    puntaje.cpp \
    registro.cpp \
    soldado_bizantino.cpp \
    soldado_otomano.cpp \
    vidadisplay.cpp \
    vidas.cpp

HEADERS += \
    barcoenemigo.h \
    barquito.h \
    barquitoenemigo.h \
    bola.h \
    canon.h \
    disp.h \
    escena.h \
    gamecontroller.h \
    gamecontrollernivel2.h \
    jefefinal.h \
    jefeproyectil.h \
    mainwindow.h \
    muro.h \
    muro_verdadero.h \
    nivel2.h \
    polvora.h \
    polvoradisplay.h \
    powerup.h \
    powerupdano.h \
    powerupvelocidad.h \
    powerupvida.h \
    proyectil.h \
    proyectilenemigo.h \
    proyectilenemigocanon.h \
    puerta.h \
    puertadisplay.h \
    puntaje.h \
    registro.h \
    soldado_bizantino.h \
    soldado_otomano.h \
    vidadisplay.h \
    vidas.h

FORMS += \
    mainwindow.ui \
    registro.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imagenes.qrc
