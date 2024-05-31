#include "mainwindow.h"
#include "ui_mainwindow.h"
QList<Barquitoenemigo*> barquitosEnemigos;

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

    // Crear el primer enemigo
    Barquitoenemigo *barquitoenemigo = new Barquitoenemigo;
    scene->addItem(barquitoenemigo);
    Puntaje *puntajeDisplay = new Puntaje();
    scene->addItem(puntajeDisplay);
    barco->setPuntaje(puntajeDisplay);
    Vidas *vidasDisplay=new Vidas(3);
    puntajeDisplay->setPos(640,3);
    scene->addItem(vidasDisplay);
    barco->setVidas(vidasDisplay);
    vidasDisplay->setPos(10,3);
    JefeFinal *jefefinal=new JefeFinal;
    scene->addItem(jefefinal);
    // Configurar el temporizador para crear nuevos enemigos
   /* spawnTimer = new QTimer(this);
    connect(spawnTimer, &QTimer::timeout, this, [this]() {
        Barquitoenemigo *enemigoChico = new Barquitoenemigo();
        scene->addItem(enemigoChico);
    });
    spawnTimer->start(2000);
    */
    GameController *gameController = new GameController(scene, puntajeDisplay);
    gameController->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}
