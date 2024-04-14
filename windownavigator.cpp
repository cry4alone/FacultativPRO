#include "windownavigator.h"
#include "adminwindow.h"
#include "authwindow.h"
#include "teacherwindow.h"

WindowNavigator::WindowNavigator(QObject *parent)
    : QObject{ parent }
    , m_authWindow(new AuthWindow)
    , m_mainWindow(nullptr)
{
    connect(m_authWindow, &AuthWindow::userEntered,
            this, &WindowNavigator::onUserEntered);
}

void WindowNavigator::start()
{
    m_authWindow->exec();
}

void WindowNavigator::onUserEntered(User::Role role)
{
    if (role == User::admin) {
        AdminWindow *adminWindow(new AdminWindow);
        {
             connect(adminWindow, &AdminWindow::logout,
                     this, WindowNavigator::openAuthWindow);
        }
        m_mainWindow = adminWindow;
    }
    else if (role == User::teacher) {
        TeacherWindow *teacherWindow(new TeacherWindow);
        {
            connect(teacherWindow, &TeacherWindow::logout,
                    this, WindowNavigator::openAuthWindow);
        }
        m_mainWindow = teacherWindow;
    }
    else if (role == User::student) {
        //...
    }

    m_mainWindow->show();
    m_authWindow->close();
}

void WindowNavigator::openAuthWindow()
{
    delete m_mainWindow;
    m_authWindow->show();
}
