#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "dialog.h"
void MainWindow::on_action_triggered(){
    qDebug()<<"triggered";
    Dialog *dialog =new Dialog(this, ui->calendar->selectedDate());
    connect(dialog, SIGNAL(updateDateInMainWindow(const QDate)), ui->calendar, SLOT(setSelectedDate(const QDate)));
    dialog->exec();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
