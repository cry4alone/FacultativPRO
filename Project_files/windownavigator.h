#ifndef WINDOWNAVIGATOR_H
#define WINDOWNAVIGATOR_H

#include <QObject>
#include <QMainWindow>
#include "facultativschedulewindow.h"
#include "user.h"

class AuthWindow;

class WindowNavigator : public QObject
{
    Q_OBJECT
public:
    explicit WindowNavigator(QObject *parent = nullptr);
    void start();

private slots:
    void onUserEntered(User::Role, int);
    void openAuthWindow();
    void openScheduleStudent();

private:
    AuthWindow* m_authWindow;
    QMainWindow* m_mainWindow;
    facultativScheduleWindow* m_scheduleWindow;
};

#endif // WINDOWNAVIGATOR_H
