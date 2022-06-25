#ifndef CQ3_H
#define CQ3_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class CQ3; }
QT_END_NAMESPACE

class CQ3 : public QDialog
{
    Q_OBJECT

public:
    CQ3(QWidget *parent = nullptr);
    ~CQ3();

private slots:
    void getPath();
    void getColor();

private:
    Ui::CQ3 *ui;
};
#endif // CQ3_H
