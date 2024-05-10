#include "windownavigator.h"
#include "adminwindow.h"
#include "authwindow.h"
#include "teacherwindow.h"
#include "studentwindow.h"

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
    m_authWindow->show();
}

void WindowNavigator::onUserEntered(User::Role role, int UserID)
{
    if (role == User::Administrator) {
        AdminWindow *adminWindow(new AdminWindow);
        {
             connect(adminWindow, &AdminWindow::logout,
                     this, WindowNavigator::openAuthWindow);
        }
        m_mainWindow = adminWindow;
    }
    else if (role == User::Teacher) {
        TeacherWindow *teacherWindow(new TeacherWindow(nullptr, UserID));
        {
            connect(teacherWindow, &TeacherWindow::logout,
                    this, WindowNavigator::openAuthWindow);
        }
        m_mainWindow = teacherWindow;
    }
    else if (role == User::Student) {
        studentwindow *Studentwindow(new studentwindow(nullptr ,UserID));
        {
            connect(Studentwindow, &studentwindow::logout,
                    this, WindowNavigator::openAuthWindow);
        }
        m_mainWindow = Studentwindow;
    }

    m_mainWindow->show();
    m_authWindow->close();
}

void WindowNavigator::openAuthWindow()
{
    delete m_mainWindow;
    m_authWindow->show();
}

void WindowNavigator::openScheduleStudent()
{

}
