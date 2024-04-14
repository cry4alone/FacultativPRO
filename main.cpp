#include "mainwindow.h"
#include "authwindow.h"
#include "windownavigator.h"
#include "userdb.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    UserDb::instance();


    WindowNavigator wn;
    wn.start();

    return a.exec();
}
