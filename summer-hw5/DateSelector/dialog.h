#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDate>
#include <QDebug>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent, QDate mainDate);
    ~Dialog();

private:
    QDate myDate;

public slots:
    void onDateChange(QDate date){
        myDate=date;
    }
    void toUpdateDateInMainWindow(){
        qDebug() << myDate;
        emit updateDateInMainWindow(myDate);
    }

signals:
    void updateDateInMainWindow(QDate);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
