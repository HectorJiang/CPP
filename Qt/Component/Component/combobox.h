#pragma once

#include <QtWidgets/QWidget>
#include "ui_combobox.h"

class ComboBox : public QWidget
{
	Q_OBJECT

public:
	ComboBox(QWidget *parent = Q_NULLPTR);

private:
	Ui::ComboBoxClass ui;
};
