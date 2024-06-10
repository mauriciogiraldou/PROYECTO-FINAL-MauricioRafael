#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamecontroller.h"
#include "registro.h"
#include <QMessageBox>
#include "puntaje.h"
#include "vidas.h"
#include "soldado_otomano.h"
#include "muro.h"
#include "muro_verdadero.h"
#include "canon.h"
#include "puerta.h"

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
    //ui->graphicsView->setMouseTracking(true);
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
    QPixmap fondo(":/imagenes/fondo2_mundo2.png");
    QGraphicsPixmapItem *imagen_fondo = new QGraphicsPixmapItem(fondo);
    imagen_fondo->setPos(0, 0);
    imagen_fondo->setZValue(-1);
    newScene->addItem(imagen_fondo);
    Muro_verdadero *campamentoverdadero = new Muro_verdadero(244, 146, 100, 7);
    campamentoverdadero->setZValue(0);
    newScene->addItem(campamentoverdadero);
    Muro_verdadero *orbanverdadero = new Muro_verdadero(690, 103, 20, 6);
    orbanverdadero->setZValue(0);
    newScene->addItem(orbanverdadero);
    Canon *canon=new Canon();
    canon->setPos(650,40);
    newScene->addItem(canon);
    Muro *campamento=new Muro(220, 70,":/imagenes/campamento.png");
    campamento->setZValue(3);
    newScene->addItem(campamento);
    soldado_otomano *solda=new soldado_otomano;
    solda->setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    solda->setFocus();
    solda->setPos(-10, 200);
    solda->setZValue(2);
    newScene->addItem(solda);
    Muro *piedra2=new Muro(0, 650,":/imagenes/piedra.png");
    Muro *piedra=new Muro(150, 630,":/imagenes/piedra.png");
    Muro *arbol1=new Muro(1000, 70,":/imagenes/arbol_aereo_pino.png");
    Muro *arbol2=new Muro(200, 400,":/imagenes/arbol_aereo.png");
    arbol1->setZValue(3);
    arbol2->setZValue(3);
    newScene->addItem(piedra);
    newScene->addItem(piedra2);
    newScene->addItem(arbol1);
    newScene->addItem(arbol2);
    Muro *marco=new Muro(0,0,":/imagenes/marco4.png");
    marco->setZValue(3);
    newScene->addItem(marco);
    Puerta *puerta=new Puerta();
    puerta->setPos(550,518);
    newScene->addItem(puerta);
    controllerNivel2 = new GameControllerNivel2(newScene,solda,canon,puerta, this);
}
