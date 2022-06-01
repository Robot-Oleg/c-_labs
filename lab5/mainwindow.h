#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "queue.h"
#include "queue.cpp"
#include "mylist.h"
#include "mylist.cpp"
#include <QRandomGenerator>
#include <ctime>
#include "myexeption.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushBackButton_clicked();

    void on_pushFrontButton_clicked();

    void on_moveLeftButton_clicked();

    void on_moveRightButton_clicked();

    void on_popButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_startAndEndButton_clicked();

private:
    Ui::MainWindow *ui;
    MyList<int> circleList;
    Queue<QString> queue;
    int position = 0;

};
#endif // MAINWINDOW_H
