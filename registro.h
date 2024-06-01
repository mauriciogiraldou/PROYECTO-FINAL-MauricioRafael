#ifndef REGISTRO_H
#define REGISTRO_H

#include <QWidget>
#include <QMap>

namespace Ui {
class registro;
}

class registro : public QWidget
{
    Q_OBJECT

public:
    explicit registro(QWidget *parent = nullptr);
    ~registro();

signals:
    void usuarioAutenticado();

private slots:
    void on_registrarButton_clicked();
    void on_iniciarSesionButton_clicked();

private:
    Ui::registro *ui;
    QMap<QString, QString> usuarios;

    void registrarUsuario(const QString &nombreUsuario, const QString &contrasena);
    bool autenticarUsuario(const QString &nombreUsuario, const QString &contrasena);

    void cargarUsuarios();
    void guardarUsuarios();
};

#endif // REGISTRO_H
