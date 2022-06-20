#pragma once
#include <QThread>
class CDbThread :public QThread
{
	Q_OBJECT
public:
	CDbThread();
protected:
	void run();
};

