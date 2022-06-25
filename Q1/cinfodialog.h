#ifndef CINFODIALOG_H
#define CINFODIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class CInfoDialog; }
QT_END_NAMESPACE

class CInfoDialog : public QDialog
{
    Q_OBJECT

public:
    CInfoDialog(QWidget *parent = nullptr);
    ~CInfoDialog();


private:
    QString m_pStrUsername;
    QString m_pStrNumber;
    QString m_pStrEmail;
    Ui::CInfoDialog *ui;

private:
    void saveInfoToJson();

private slots:
    void validateInfo();
};
#endif // CINFODIALOG_H
