#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPixmap>
void MainWindow::on_pushButton_clicked(){

    iconID+=1;
    iconID%=7;
    qDebug() << iconID;
    QPixmap image;
    switch (iconID){
    case 1:
        image=QPixmap(":/images/res/1.png");
        break;
    case 2:
        image=QPixmap(":/images/res/2.png");
        break;
    case 3:
        image=QPixmap(":/images/res/3.png");
        break;
    case 4:
        image=QPixmap(":/images/res/4.png");
        break;
    case 5:
        image=QPixmap(":/images/res/5.png");
        break;
    case 6:
        image=QPixmap(":/images/res/6.png");
        break;
    default:
        image=QPixmap(":/images/res/7.png");
        break;
    }

    ui->pushButton->setIcon(image);
    ui->pushButton->setIconSize(image.size());
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    iconID=0;
    on_pushButton_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}
