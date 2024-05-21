#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //QRect Desktop = QApplication::desktop()->screenGeometry();
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect Desktop = screen->geometry();
    x = Desktop.x();
    y = Desktop.y();

    ancho = Desktop.width()-100;
    alto = Desktop.height()-100;

    scene = new QGraphicsScene(x, y, ancho, alto);

    ui->graphicsView->setScene(scene);

    Jinete_1 = new sprite();

    scene->addItem(Jinete_1); // agregando el sprite a la escena.

    Jinete_1->setPos(580, 400);
}

Widget::~Widget()
{
    delete ui;
}
