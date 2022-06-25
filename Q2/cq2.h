#ifndef CQ2_H
#define CQ2_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class CQ2; }
QT_END_NAMESPACE

class CQ2 : public QDialog
{
    Q_OBJECT

public:
    CQ2(QWidget *parent = nullptr);
    ~CQ2();
private slots:
    //改变按钮输入框状态
    void changeStatus();
    //检查数据有效性
    void checkData();
private:
    //输入框状态
    bool m_bStatus = true;
    Ui::CQ2 *ui;
};
#endif // CQ2_H
