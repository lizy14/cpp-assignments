#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent, QDate mainDate) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(mainDate);
    connect(this->ui->dateEdit,SIGNAL(dateChanged(const QDate)),this,SLOT(onDateChange(QDate)));
    connect(this, SIGNAL(accepted()), this, SLOT(toUpdateDateInMainWindow()));
}

Dialog::~Dialog()
{
    delete ui;
}
