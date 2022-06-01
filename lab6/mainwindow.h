#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tree.h"
#include "tree.cpp"
#include "mytree.h"
#include "mytree.cpp"
#include "node.h"
#include <QTreeWidgetItem>
#include <QString>


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
    void on_deleteFromTreeButton_clicked();

    void on_balanceButton_clicked();

    void on_addToArrayButton_clicked();

    void on_FromArrayToTreeButton_clicked();

    void on_searchButton_clicked();

    void on_insertInTreeButton_clicked();

    void on_numberButton_clicked();

    void on_traversInorderButton_clicked();

    void on_traversPosorderButton_clicked();

    void on_traversPreorderButton_clicked();

private:
    Ui::MainWindow *ui;
//    Tree<QString> tree;
    MyTree<QString> tree;
    QVector<Node<QString>> array;
    void PushToTreeWidget(Node<QString> *tree,  QTreeWidgetItem *item = nullptr);
};
#endif // MAINWINDOW_H
