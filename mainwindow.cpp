#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamecontroller.h"
#include "nivel2.h"
#include "registro.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Mostrar el formulario de registro
    Registro registroDialog;
    connect(&registroDialog, &Registro::usuarioAutenticado, this, &MainWindow::iniciarJuego);
    if (registroDialog.exec() == QDialog::Rejected) {
        // Si el registro o la autenticación fallan, cerramos la aplicación
        close();
        return;
    }

    iniciarJuego();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::iniciarJuego() {
    scene = new Escena(this);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());
    ui->graphicsView->setMouseTracking(true);

    Barquito *barco = new Barquito;
    barco->setFlag(QGraphicsPixmapItem::ItemIsFocusable);

    barco->setFocus();
    barco->setPos(-10, 200);
    scene->addItem(barco);

    Barquitoenemigo *barquitoenemigo = new Barquitoenemigo;
    scene->addItem(barquitoenemigo);

    Puntaje *puntajeDisplay = new Puntaje();
    scene->addItem(puntajeDisplay);
    barco->setPuntaje(puntajeDisplay);

    Vidas *vidasDisplay = new Vidas(3);
    puntajeDisplay->setPos(640, 3);
    scene->addItem(vidasDisplay);
    barco->setVidas(vidasDisplay);
    vidasDisplay->setPos(10, 3);

    controller = new GameController(scene, puntajeDisplay);
    connect(controller, &GameController::changeScene, this, &MainWindow::onChangeScene);
    controller->start();
}

void MainWindow::reiniciarJuego() {
    if (controller) {
        controller->clearScene();
        delete controller;
    }
    iniciarJuego();
}

void MainWindow::onChangeScene(QGraphicsScene *newScene) {
    controller->clearScene();
    ui->graphicsView->setScene(newScene);
    newScene->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());
}
