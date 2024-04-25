#ifndef STUDENTPERSONALWINDOW_H
#define STUDENTPERSONALWINDOW_H

#include <QDialog>

namespace Ui {
class studentpersonalwindow;
}

class studentpersonalwindow : public QDialog
{
    Q_OBJECT

public:
    explicit studentpersonalwindow(QWidget *parent = nullptr);
    ~studentpersonalwindow();

private slots:
    void on_CancelButton_clicked();

private:
    Ui::studentpersonalwindow *ui;
};

#endif // STUDENTPERSONALWINDOW_H
