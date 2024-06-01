#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamecontroller.h"
#include "nivel2.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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

    GameController *controller = new GameController(scene, puntajeDisplay);
    connect(controller, &GameController::changeScene, this, &MainWindow::onChangeScene);
    controller->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onChangeScene(QGraphicsScene *newScene) {
    ui->graphicsView->setScene(newScene);
    newScene->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());
}
