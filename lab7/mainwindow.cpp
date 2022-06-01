#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_AddButton_clicked()
{
   AddToTreeWidget(ui->KeyLineEdit->text().toInt(), ui->ValueLineEdit->text());
}

void MainWindow::on_DeleteButton_clicked()
{
    hashTable.Delete(ui->treeWidget->selectedItems()[0]->text(0).toInt());
    delete ui->treeWidget->selectedItems()[0];
}

void MainWindow::on_FindButton_clicked()
{
    Person *person;
    try {
        Person *person = hashTable.Search(ui->KeyLineEdit->text().toInt());

        const char *noItemDesc = "not enough brackets";
        MyExeption *noItemEx = new MyExeption(noItemDesc);

        if (person == nullptr) throw noItemEx;
    }  catch (MyExeption *ex) {
            QMessageBox::critical(NULL, "Error!", ex->what());
            return;
    }
    ui->findLabel->setText(QString::number(person->GetId()));
}

void MainWindow::on_GenerateButton_clicked()
{
    for (int i = 1; i < 20; i++) {
        int x = QRandomGenerator::global()->bounded(10);
        QString str = GetRandomString();
        AddToTreeWidget(x, str);
    }
}

void MainWindow::on_RepeatedButton_clicked()
{
    ui->mostRepeatedLabel->setText(QString::number(hashTable.MostRepKey()));
}

QString MainWindow::GetRandomString() const
{
   const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
   const int randomStringLength = 5; // assuming you want random strings of 12 characters

   QString randomString;
   for(int i=0; i<randomStringLength; ++i)
   {
       int index = QRandomGenerator::global()->generate() % possibleCharacters.length();
       QChar nextChar = possibleCharacters.at(index);
       randomString.append(nextChar);
   }
   return randomString;
}

void MainWindow::AddToTreeWidget(int key, QString value)
{
    int index = hashTable.Insert(key, value);
    if (ui->treeWidget->topLevelItem(index)->text(0)=="") {
        ui->treeWidget->topLevelItem(index)->setText(0, QString::number(key));
        ui->treeWidget->topLevelItem(index)->setText(1, value);
     }
     else {
        QTreeWidgetItem *newItem = new QTreeWidgetItem();
        newItem->setText(0, QString::number(key));
        newItem->setText(1, value);
        ui->treeWidget->topLevelItem(index)->addChild(newItem);
    }
}
