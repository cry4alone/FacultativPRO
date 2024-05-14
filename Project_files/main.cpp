// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include "mainwindow.h"
#include "authwindow.h"
#include "windownavigator.h"
#include "userdb.h"
#include <QtSql>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile file(":/resc/FacultativPRO.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    a.setStyleSheet(styleSheet);
    UserDb::instance();

    WindowNavigator wn;
    wn.start();

    return a.exec();
}
