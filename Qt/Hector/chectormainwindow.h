#ifndef CHECTORMAINWINDOW_H
#define CHECTORMAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QGraphicsScene>

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
    void initUI();
    void createActions();
    void showImage(QString strPath);


private slots:
    void openImage();
    void zoomIn();

private:
//    Ui::CHectorMainWindow *ui;
    QLabel *m_pLbImg;
    QRect m_ret;
    QMenu *m_pMenuFile;
    QMenu *m_pMenuView;
    QToolBar *m_pToolBarFile;
    QToolBar *m_pToolBarView;

    QAction *m_pActionOpen;
    QAction *m_pActionExit;
    QAction *m_pActionZoomIn;

    QGraphicsScene *m_pSceneImage;
    QGraphicsView *m_pViewImage;

    QStatusBar *m_pStatusBarMain;
    QLabel *m_pLbMainStatus;

};
#endif // CHECTORMAINWINDOW_H
