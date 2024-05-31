QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    barco.cpp \
    barcoenemigo.cpp \
    barquito.cpp \
    barquitoenemigo.cpp \
    disp.cpp \
    escena.cpp \
    gamecontroller.cpp \
    main.cpp \
    mainwindow.cpp \
    projectile.cpp \
    proyectilenemigo.cpp \
    puntaje.cpp \
    vidas.cpp

HEADERS += \
    barco.h \
    barcoenemigo.h \
    barquito.h \
    barquitoenemigo.h \
    disp.h \
    escena.h \
    gamecontroller.h \
    mainwindow.h \
    projectile.h \
    proyectilenemigo.h \
    puntaje.h \
    vidas.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imagenes.qrc
