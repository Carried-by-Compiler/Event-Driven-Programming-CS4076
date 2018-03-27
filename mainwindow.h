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
    //void on_teleButton_clicked();

    //void on_startButton_clicked();

   // void on_mapButton_clicked();

    //void on_testButton_clicked();

    void on_goButton_clicked();

    void on_upButton_clicked();

    void on_downButton_clicked();

    void on_SearchButton_clicked();

    void on_UseItem_clicked();

private:
    Ui::MainWindow *ui;
    ZorkUL *zork;

    void check_exit_rooms();
    void displayCurrentRoomInfo();
    void displayExitList();
    void clearExitList();
    void floorMoveAllowed();
    void inventoryDisplay();
};

#endif // MAINWINDOW_H
