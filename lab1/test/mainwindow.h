#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "figure.h"
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include "pentagon.h"
#include "hexagon.h"
#include <QGraphicsScene>

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
    void on_rectanglePushButton_clicked();

    void on_scaleButton_clicked();

    void on_rotateButton_clicked();

    void on_setPushButton_clicked();

    void on_pushButton_clicked();

    void on_trianglePushButton_clicked();

    void on_pentagonPushButton_clicked();

    void on_hexagonPushButton_clicked();

    void on_circlePushButton_clicked();

    void on_areaPushButton_clicked();

    void on_perimetrPushButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
};
#endif // MAINWINDOW_H
