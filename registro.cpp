#include "registro.h"
#include "ui_registro.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDir>
#include <QDebug>

Registro::Registro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registro)
{
    ui->setupUi(this);
    cargarUsuarios();
}

Registro::~Registro()
{
    guardarUsuarios();
    delete ui;
}

void Registro::registrarUsuario(const QString &nombreUsuario, const QString &contrasena) {
    if (usuarios.contains(nombreUsuario)) {
        QMessageBox::warning(this, "Registro fallido", "El nombre de usuario ya existe.");
        return;
    }
    usuarios[nombreUsuario] = contrasena;
    QMessageBox::information(this, "Registro exitoso", "Usuario registrado con éxito.");
    guardarUsuarios();
}

bool Registro::autenticarUsuario(const QString &nombreUsuario, const QString &contrasena) {
    return usuarios.contains(nombreUsuario) && usuarios[nombreUsuario] == contrasena;
}

void Registro::on_registrarButton_clicked() {
    QString nombreUsuario = ui->nombreUsuarioEdit->text();
    QString contrasena = ui->contrasenaEdit->text();
    registrarUsuario(nombreUsuario, contrasena);
}

void Registro::on_iniciarSesionButton_clicked() {
    QString nombreUsuario = ui->nombreUsuarioEdit->text();
    QString contrasena = ui->contrasenaEdit->text();
    if (autenticarUsuario(nombreUsuario, contrasena)) {
        emit usuarioAutenticado();
        accept();
    } else {
        QMessageBox::warning(this, "Autenticación fallida", "Nombre de usuario o contraseña incorrectos.");
    }
}

void Registro::cargarUsuarios() {
    QString filePath = QCoreApplication::applicationDirPath() + "/../usuarios.txt";
    qDebug() << "Cargando usuarios desde: " << filePath;
    QFile file(filePath);

    if (!file.exists()) {
        qDebug() << "El archivo no existe.";
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "No se pudo abrir el archivo de usuarios.";
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(",");
        if (parts.size() == 2) {
            usuarios[parts[0]] = parts[1];
        }
    }

    file.close();
}

void Registro::guardarUsuarios() {
    QString filePath = QCoreApplication::applicationDirPath() + "/../usuarios.txt";
    qDebug() << "Guardando usuarios en: " << filePath;
    QFile file(filePath);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "No se pudo abrir el archivo de usuarios.";
        return;
    }

    QTextStream out(&file);
    for (auto it = usuarios.begin(); it != usuarios.end(); ++it) {
        out << it.key() << "," << it.value() << "\n";
    }

    file.close();
}
