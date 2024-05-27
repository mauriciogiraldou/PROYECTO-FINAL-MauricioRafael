#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene= new Escena(this);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,ui->graphicsView->width(),ui->graphicsView->height());
    ui->graphicsView->setMouseTracking(true);
    Barquito *barco=new Barquito;
    barco->setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    barco->setFocus();
    scene->addItem(barco);

}


MainWindow::~MainWindow()
{
    delete ui;
}
