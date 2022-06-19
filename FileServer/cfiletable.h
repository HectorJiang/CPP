#ifndef CFILETABLE_H
#define CFILETABLE_H

#include <QMainWindow>

namespace Ui {
class CFileTable;
}

class CFileTable : public QMainWindow
{
    Q_OBJECT

public:
    explicit CFileTable(QWidget *parent = nullptr);
    ~CFileTable();

private:
    Ui::CFileTable *ui;
};

#endif // CFILETABLE_H
