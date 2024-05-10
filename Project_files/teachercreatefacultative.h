#ifndef TEACHERCREATEFACULTATIVE_H
#define TEACHERCREATEFACULTATIVE_H

#include <QDialog>
#include <QtSvg/QSvgRenderer>
#include <QPainter>
#include "facultativ.h"
#include "userdb.h"
#include <QMessageBox>

namespace Ui {
class teacherCreateFacultative;
}

class teacherCreateFacultative : public QDialog
{
    Q_OBJECT

public:
    explicit teacherCreateFacultative(QWidget *parent = nullptr, int UserID = -1);
    ~teacherCreateFacultative();

private slots:
    void on_backButton_clicked();

    void on_createButton_clicked();

private:
    Ui::teacherCreateFacultative *ui;
    int m_UserID;
};

#endif // TEACHERCREATEFACULTATIVE_H
