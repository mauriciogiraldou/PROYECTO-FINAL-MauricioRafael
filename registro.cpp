#include "registro.h"
#include "ui_registro.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDir>
#include <QDebug>

registro::registro(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::registro) {
    ui->setupUi(this);
    cargarUsuarios();
}

registro::~registro() {
    guardarUsuarios();
    delete ui;
}

void registro::registrarUsuario(const QString &nombreUsuario, const QString &contrasena) {
    if (usuarios.contains(nombreUsuario)) {
        QMessageBox::warning(this, "Registro fallido", "El nombre de usuario ya existe.");
        return;
    }
    usuarios[nombreUsuario] = contrasena;
    QMessageBox::information(this, "Registro exitoso", "Usuario registrado con éxito.");
    guardarUsuarios();
}

bool registro::autenticarUsuario(const QString &nombreUsuario, const QString &contrasena) {
    return usuarios.contains(nombreUsuario) && usuarios[nombreUsuario] == contrasena;
}

void registro::on_registrarButton_clicked() {
    QString nombreUsuario = ui->nombreUsuarioEdit->text();
    QString contrasena = ui->contrasenaEdit->text();
    registrarUsuario(nombreUsuario, contrasena);
}

void registro::on_iniciarSesionButton_clicked() {
    QString nombreUsuario = ui->nombreUsuarioEdit->text();
    QString contrasena = ui->contrasenaEdit->text();
    if (autenticarUsuario(nombreUsuario, contrasena)) {
        emit usuarioAutenticado();
    } else {
        QMessageBox::warning(this, "Autenticación fallida", "Nombre de usuario o contraseña incorrectos.");
    }
}

void registro::cargarUsuarios() {
    QString filePath = QDir::homePath() + "/.miJuego/usuarios.txt";
    QFile file(filePath);

    if (!file.exists()) {
        QDir().mkpath(QDir::homePath() + "/.miJuego");
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

void registro::guardarUsuarios() {
    QString filePath = QDir::homePath() + "/.miJuego/usuarios.txt";
    QFile file(filePath);

    if (!file.exists()) {
        QDir().mkpath(QDir::homePath() + "/.miJuego");
    }

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
