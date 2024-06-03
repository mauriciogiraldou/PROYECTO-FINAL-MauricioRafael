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
    disp.cpp \
    escena.cpp \
    gamecontroller.cpp \
    gamecontrollernivel2.cpp \
    jefefinal.cpp \
    jefeproyectil.cpp \
    main.cpp \
    mainwindow.cpp \
    nivel2.cpp \
    proyectilenemigo.cpp \
    puntaje.cpp \
    registro.cpp \
    vidas.cpp

HEADERS += \
    barcoenemigo.h \
    barquito.h \
    barquitoenemigo.h \
    bola.h \
    disp.h \
    escena.h \
    gamecontroller.h \
    gamecontrollernivel2.h \
    jefefinal.h \
    jefeproyectil.h \
    mainwindow.h \
    nivel2.h \
    proyectilenemigo.h \
    puntaje.h \
    registro.h \
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
