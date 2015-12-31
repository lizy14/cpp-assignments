#include "tempconverter.h"

#include <QDebug>
#include <QSignalMapper>

tempConverter::tempConverter(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	
	connect(ui.dialF, SIGNAL(valueChanged(int)), this, SLOT(setTempFahrenheit(int)));
	connect(ui.dialF, SIGNAL(valueChanged(int)), ui.lcdF, SLOT(display(int)));
	connect(this, SIGNAL(tempFahrenheitChanged(int)), ui.dialF, SLOT(setValue(int)));
	connect(this, SIGNAL(tempCelsiusChanged(int)), ui.dialC, SLOT(setValue(int)));

	
	QSignalMapper *m = new QSignalMapper(this);
	
	
	connect(ui.dialC, SIGNAL(valueChanged(int)),m, SLOT(map()));
	connect(ui.dialF, SIGNAL(valueChanged(int)),m, SLOT(map()));
	m->setMapping(ui.dialC,1);
	m->setMapping(ui.dialF,2);
	
	connect(m, SIGNAL(mapped(int)), this, SLOT(onStatusChange_(int)));
	
}

tempConverter::~tempConverter(){

}
void tempConverter::setTempCelsius(float tempCelsius)
{
	qDebug() << "setTempCelsius(float) called" << endl;
	if(m_tempCelsius == tempCelsius)
		return;
	m_tempCelsius = tempCelsius;
	emit tempCelsiusChanged(m_tempCelsius);
	emit tempFahrenheitChanged(tempFahrenheit());
}
void tempConverter::setTempFahrenheit(int tempFahrenheit){
	setTempCelsius((5.0/9.0)*(tempFahrenheit-32));
}
int tempConverter::tempCelsius() const{
	return m_tempCelsius;
}
int tempConverter::tempFahrenheit() const{
	int F=(m_tempCelsius*9.0/5.0)+32;
	return F;
}
void tempConverter::on_dialC_valueChanged(int x){
	qDebug() << "on_dialC_valueChanged(int) called" << endl;
	this->setTempCelsius(x);
	ui.lcdC->display(x);
}
void tempConverter::onStatusChange_(int id){
	if(id==1){
		ui.label->setText("You are converting from Celsius to Fahrenheit.");
	}else{
		ui.label->setText("You are converting from Fahrenheit to Celsius.");
	}
}