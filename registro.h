#ifndef REGISTRO_H
#define REGISTRO_H
#include "ui_registro.h"
#include <QDialog>
#include <QMap>
namespace Ui {
class registro;
}

class Registro : public QDialog
{
    Q_OBJECT

public:
    explicit Registro(QWidget *parent = nullptr);
    ~Registro();
signals:
    void usuarioAutenticado();
private slots:
    void on_registrarButton_clicked();
    void on_iniciarSesionButton_clicked();
private:
    Ui::registro *ui;
    QMap<QString, QString> usuarios; // Mapa para almacenar las credenciales de los usuarios

    void registrarUsuario(const QString &nombreUsuario, const QString &contrasena);
    bool autenticarUsuario(const QString &nombreUsuario, const QString &contrasena);

    void cargarUsuarios();
    void guardarUsuarios();
};

#endif // REGISTRO_H
