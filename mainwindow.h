#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <boardmodel.h>
#include <boardview.h>
#include <fielddelegate.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    BoardModel *board;
    FieldDelegate *delegate;
};

#endif // MAINWINDOW_H
