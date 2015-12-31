#include "mainwindow.h"
#include "ui_mainwindow.h"


bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->textEdit) {
        if (event->type() == QEvent::KeyPress) {
            QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
                if(keyEvent->key()==Qt::Key_C){
                    qDebug() << "Ate key press" << keyEvent->key();
                    return true;
                }
        }
    }
    return QMainWindow::eventFilter(obj, event);
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
