#ifndef CHECTORMAINWINDOW_H
#define CHECTORMAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class CHectorMainWindow; }
QT_END_NAMESPACE

class CHectorMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    CHectorMainWindow(QWidget *parent = nullptr);
    ~CHectorMainWindow();

protected:
    void resizeEvent(QResizeEvent* event);
    void moveEvent(QMoveEvent* event);

private:
    Ui::CHectorMainWindow *ui;
    QLabel *m_pLbImg;
    QRect m_ret;
};
#endif // CHECTORMAINWINDOW_H
