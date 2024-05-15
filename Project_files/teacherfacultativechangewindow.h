#ifndef TEACHERFACULTATIVECHANGEWINDOW_H
#define TEACHERFACULTATIVECHANGEWINDOW_H

#include <QDialog>
#include "userdb.h"
#include "studentsmodel.h"
#include <QMessageBox>
#include <QImageReader>


namespace Ui {
class teacherFacultativeChangeWindow;
}

class teacherFacultativeChangeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit teacherFacultativeChangeWindow(QWidget *parent = nullptr, int FacID = -1);
    ~teacherFacultativeChangeWindow();

private slots:
    void on_pushButton_clicked();

    void on_confirmButton_clicked();

    void on_deleteButton_clicked();

private:
    Facultativ m_facultativ;
    int m_FacID;
    void setEditingWidget();
    void setGradingWidget();
    bool getAllTheData();
    bool checkDate(QDate start, QDate finish);
    StudentsModel *m_StudentsModel;
    Ui::teacherFacultativeChangeWindow *ui;
};

#endif // TEACHERFACULTATIVECHANGEWINDOW_H
