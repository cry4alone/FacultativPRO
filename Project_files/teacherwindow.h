#ifndef TEACHERWINDOW_H
#define TEACHERWINDOW_H

#include <QMainWindow>

namespace Ui {
class TeacherWindow;
}

class TeacherWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TeacherWindow(QWidget *parent = nullptr, int UserID = -1);
    ~TeacherWindow();

signals:
    void logout();

private slots:
    void on_facultativButton_clicked();

    void on_createButton_clicked();

private:
    Ui::TeacherWindow *ui;
    int m_UserID;
};

#endif // TEACHERWINDOW_H
