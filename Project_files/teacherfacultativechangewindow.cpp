#include "teacherfacultativechangewindow.h"
#include "ui_teacherfacultativechangewindow.h"

teacherFacultativeChangeWindow::teacherFacultativeChangeWindow(QWidget *parent, int FacID)
    : QDialog(parent)
    , ui(new Ui::teacherFacultativeChangeWindow)
    , m_StudentsModel(nullptr)
{
    ui->setupUi(this);
    m_FacID = FacID;
    ui->tabWidget->setTabText(0, "Editing");
    ui->tabWidget->setTabText(1, "Grading");
    m_facultativ = UserDb::instance().getFacultativByID(FacID);
    setEditingWidget();
    setGradingWidget();
}

teacherFacultativeChangeWindow::~teacherFacultativeChangeWindow()
{
    delete ui;
}

void teacherFacultativeChangeWindow::on_pushButton_clicked()
{
    close();
}

void teacherFacultativeChangeWindow::setEditingWidget()
{
    ui->nameEdit->setText(m_facultativ.Discipline_Name);
    ui->startDateEdit->setDate(m_facultativ.Start_Date);
    ui->endDateEdit->setDate(m_facultativ.End_Date);
    ui->dayBox->setCurrentIndex(m_facultativ.Day_of_Week);
    Facultativ::Type_of_Lesson Lesson_Type = m_facultativ.Type_of_lesson;
    int BoxType_Lesson;
    if (Lesson_Type == Facultativ::Type_of_Lesson::Laboratory_work)
    {
        BoxType_Lesson = 0;
    }
    else if (Lesson_Type == Facultativ::Type_of_Lesson::Practice_work)
    {
        BoxType_Lesson = 1;
    }
    else
    {
        BoxType_Lesson = 2;
    }
    ui->laboratoryBox->setCurrentIndex(BoxType_Lesson);
}

void teacherFacultativeChangeWindow::setGradingWidget()
{
    m_StudentsModel = new StudentsModel(nullptr, m_FacID);
    ui->tableView->setModel(m_StudentsModel);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}


void teacherFacultativeChangeWindow::on_confirmButton_clicked()
{
    QVector<QPair<int, int>> changedUsers = m_StudentsModel->getChangedUsers();

    for (const QPair<int, int> &user : changedUsers) {
        UserDb::instance().setFinalGrade(user.first, user.second, m_FacID);
    }

    // Очищаем список измененных строк и временные значения FinalGrade
    m_StudentsModel->clearChangedRows();
    m_StudentsModel->m_tempFinalGrades.clear();
    //TODO: запись изменных данных с первого виджета
    close();
}

