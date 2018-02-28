#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ZorkUL.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_teleButton_clicked();

    void on_startButton_clicked();

    void on_mapButton_clicked();

    void on_NorthButton_clicked();

    void on_westButton_clicked();

    void on_EastButton_clicked();

    void on_SouthButton_clicked();

    void on_testButton_clicked();

private:
    void check_exit_rooms();
    Ui::MainWindow *ui;
    ZorkUL *zork;
};

#endif // MAINWINDOW_H
