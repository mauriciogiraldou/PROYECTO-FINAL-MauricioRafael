#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamecontroller.h"
#include "registro.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Registro registroDialog;
    connect(&registroDialog, &Registro::usuarioAutenticado, this, &MainWindow::iniciarJuego);
    if (registroDialog.exec() == QDialog::Rejected) {
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
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    Barquito *barco = new Barquito;
    barco->setFlag(QGraphicsPixmapItem::ItemIsFocusable);

    barco->setFocus();
    barco->setPos(-10, 200);
    scene->addItem(barco);



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



void MainWindow::onChangeScene(QGraphicsScene *newScene) {
    controller->clearScene();
    delete barco;
    ui->graphicsView->setScene(newScene);
    ui->graphicsView->setFixedSize(1366, 768);
    newScene->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());
    QPixmap fondo(":/imagenes/fondo_mundo_2.png");
    QGraphicsPixmapItem *imagen_fondo = new QGraphicsPixmapItem(fondo);
    imagen_fondo->setPos(0, 0);
    newScene->addItem(imagen_fondo);
    soldado_otomano *solda=new soldado_otomano;
    solda->setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    solda->setFocus();
    solda->setPos(-10, 200);
    newScene->addItem(solda);

}
