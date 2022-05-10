#ifndef CFILEGRAPH_H
#define CFILEGRAPH_H

#include <QtCharts>
#include <QChartView>
#include <QMainWindow>
QT_CHARTS_USE_NAMESPACE
namespace Ui {
class CFileGraph;
}

class CFileGraph : public QMainWindow
{
    Q_OBJECT

public:
    explicit CFileGraph(QWidget *parent = nullptr);
    ~CFileGraph();

private:
    Ui::CFileGraph *ui;
};

#endif // CFILEGRAPH_H
