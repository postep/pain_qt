#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <boardmodel.h>
#include <boardview.h>
#include <fielddelegate.h>
#include <gamestate.h>
#include <QPropertyAnimation>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void onGameStateChange(GameState gs);

private slots:
    void on_actionUstawienia_triggered();

    void on_actionZamknij_triggered();

private:
    Ui::MainWindow *ui;
    BoardModel *board;
    FieldDelegate *delegate;
};

#endif // MAINWINDOW_H
