#include "mainwindow.h"
#include "authwindow.h"
#include "windownavigator.h"
#include "userdb.h"
#include <QtSql>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    UserDb::instance();

    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName("OSOGO.sqlite");
    if (!sdb.open()) {
        qDebug()<<"Не удалось открыть базу данных";
    }

    WindowNavigator wn;
    wn.start();

    return a.exec();
}
