#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "list.h"
#include "list.cpp"
#include "product.h"
#include "myexeption.h"
#include <QDateTime>

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
    void on_addPushButton_clicked();

    void on_showPushButton_clicked();

    void on_datePushButton_clicked();

    void on_pricePushButton_clicked();

    void on_clearPushButton_clicked();

private:
    List<Product> productList;
    List<Product> expectedProductList;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
