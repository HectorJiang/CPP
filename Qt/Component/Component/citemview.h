#pragma once

#include <QAbstractItemView>
#include "ui_citemview.h"

class CItemView : public QAbstractItemView
{
	Q_OBJECT

public:
	CItemView(QWidget *parent = Q_NULLPTR);
	~CItemView();

private:
	Ui::CItemView ui;
};
