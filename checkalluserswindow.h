#ifndef CHECKALLUSERSWINDOW_H
#define CHECKALLUSERSWINDOW_H

#include <QDialog>

namespace Ui {
class checkalluserswindow;
}

class checkalluserswindow : public QDialog
{
    Q_OBJECT

public:
    explicit checkalluserswindow(QWidget *parent = nullptr);
    ~checkalluserswindow();

private slots:
    void on_ButtonBack_clicked();

private:
    Ui::checkalluserswindow *ui;
};

#endif // CHECKALLUSERSWINDOW_H
