#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include "escena.h"
#include "barquito.h"
#include "barquitoenemigo.h"
#include <QTimer>
#include "gamecontroller.h"
#include "jefefinal.h"
#include "gamecontrollernivel2.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Escena *scene;
    Barquito *barco;
    Barquitoenemigo *barquitoenemigo;
    QTimer *spawnTimer;
    JefeFinal *jefefinal;
    void iniciarJuego();
    GameController *controller;
    GameControllerNivel2 *controllerNivel2;
private slots:
    void onChangeScene(QGraphicsScene *newScene);

};
#endif // MAINWINDOW_H
