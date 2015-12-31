#ifndef TEMPCONVERTER_H
#define TEMPCONVERTER_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QDial>
#include "ui_tempconverter.h"

class tempConverter : public QMainWindow
{
	Q_OBJECT

public:
	tempConverter(QWidget *parent = 0);
	~tempConverter();
	int tempCelsius() const;
	int tempFahrenheit() const;
public slots:
		void setTempCelsius(float);
		void setTempFahrenheit(int);
		void on_dialC_valueChanged(int);
		void onStatusChange_(int);
signals:
		void tempCelsiusChanged(int);
		void tempFahrenheitChanged(int);
		
private:
	float m_tempCelsius;
private:
	Ui::tempConverterClass ui;

};

#endif // TEMPCONVERTER_H
