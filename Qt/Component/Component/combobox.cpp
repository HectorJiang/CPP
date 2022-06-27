#include "combobox.h"
#include <QComboBox>
#include <QHBoxLayout>
#include <QIcon>
#include <QVariant>
#include <QAbstractItemView>

ComboBox::ComboBox(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QComboBox *comboBox = new QComboBox(this);
	comboBox->addItem(QIcon(":/1.png"), "Hello", QVariant("Hello"));
	comboBox->setView();
	QHBoxLayout *layout = new QHBoxLayout(this);
	layout->addWidget(comboBox);
	this->setLayout(layout);
}
