#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myhashtable.h"
#include "hashtable.h"
#include "person.h"

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
    void on_AddButton_clicked();

    void on_DeleteButton_clicked();

    void on_FindButton_clicked();

    void on_GenerateButton_clicked();

    void on_RepeatedButton_clicked();

private:
    Ui::MainWindow *ui;
    QString GetRandomString() const;
    void AddToTreeWidget(int key, QString value);
    MyHashTable hashTable;
//    HashTable hashTable;
};
#endif // MAINWINDOW_H
