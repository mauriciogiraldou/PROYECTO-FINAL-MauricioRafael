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

    // Configurar el temporizador para crear nuevos enemigos
    spawnTimer = new QTimer(this);
    connect(spawnTimer, &QTimer::timeout, this, [this]() {
        Barquitoenemigo *enemigoChico = new Barquitoenemigo();
        scene->addItem(enemigoChico);
    });
    spawnTimer->start(2000);
}

MainWindow::~MainWindow()
{
    delete ui;
}
