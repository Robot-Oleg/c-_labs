#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stack.h"
#include "stack.cpp"
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
    void on_pushButton_2_clicked();

    void on_translatePushButton_clicked();

    void on_answerPushButton_clicked();

private:
    Ui::MainWindow *ui;
    Stack<double> calculate;
    Stack<QChar> translate;
    double Calculate(double a, double b, QChar operation);
};
#endif // MAINWINDOW_H
