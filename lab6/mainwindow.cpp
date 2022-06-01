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

void MainWindow::PushToTreeWidget(Node<QString> *node,  QTreeWidgetItem *item)
{
    if(node != nullptr) {
            QTreeWidgetItem *newItem;
            if(item == nullptr) {
                newItem = new QTreeWidgetItem(ui->treeWidget);
                newItem->setText(0, QString::number(node->_key));
                newItem->setText(1, node->_data);
                ui->treeWidget->addTopLevelItem(newItem);
            }
            else {
                newItem = new QTreeWidgetItem();
                newItem->setText(0, QString::number(node->_key));
                newItem->setText(1, node->_data);
                item->addChild(newItem);
            }
            PushToTreeWidget(node->leftChild, newItem);
            PushToTreeWidget(node->rightChild, newItem);
        }
}


void MainWindow::on_deleteFromTreeButton_clicked()
{
    tree.Delete(ui->treeWidget->selectedItems()[0]->text(0).toInt());
    delete ui->treeWidget->selectedItems()[0];
}

void MainWindow::on_balanceButton_clicked()
{
    ui->treeWidget->clear();
    tree.FromBinaryTreeToArray(array);
    tree.DeleteTree(tree.GetRoot());
    tree.Balance(0, -1, array);
    PushToTreeWidget(tree.GetRoot());
}

void MainWindow::on_addToArrayButton_clicked()
{
   QTreeWidgetItem *newItem = new QTreeWidgetItem(ui->arrayTreeWidget);
   newItem->setText(0, ui->keyLineEdit->text());
   newItem->setText(1, ui->valueLineEdit->text());
   ui->arrayTreeWidget->addTopLevelItem(newItem);
}

void MainWindow::on_FromArrayToTreeButton_clicked()
{
    tree.DeleteTree(tree.GetRoot());
    ui->treeWidget->clear();
    QTreeWidgetItemIterator it(ui->arrayTreeWidget);
    while (*it){
        tree.Insert((*it)->text(0).toInt(), (*it)->text(1));
        ++it;
    }
    PushToTreeWidget(tree.GetRoot());
}

void MainWindow::on_searchButton_clicked()
{
    ui->searchLabel->setText(tree.Search(ui->searchLineEdit->text().toInt())->_data);
}

void MainWindow::on_insertInTreeButton_clicked()
{
    ui->treeWidget->clear();
    tree.Insert(ui->keyLineEdit->text().toInt(), ui->valueLineEdit->text());
    PushToTreeWidget(tree.GetRoot());
}

void MainWindow::on_numberButton_clicked()
{
    tree.SetCount(0);
    tree.NumberOfNodsInLeftTree();
    ui->numberLabel->setText(QString::number(tree.GetCount()));
}

void MainWindow::on_traversInorderButton_clicked()
{

    ui->arrayTreeWidget->clear();
    tree.TraversInOrder();
    foreach(Node<QString> *item, tree.travers){
       QTreeWidgetItem *newItem = new QTreeWidgetItem(ui->arrayTreeWidget);
       newItem->setText(0, QString::number(item->_key));
       newItem->setText(1, item->_data);
       ui->arrayTreeWidget->addTopLevelItem(newItem);
    }
    tree.travers.clear();
}

void MainWindow::on_traversPosorderButton_clicked()
{
     ui->arrayTreeWidget->clear();
    tree.TraversPostOrder();
    foreach(Node<QString> *item, tree.travers){
       QTreeWidgetItem *newItem = new QTreeWidgetItem(ui->arrayTreeWidget);
       newItem->setText(0, QString::number(item->_key));
       newItem->setText(1, item->_data);
       ui->arrayTreeWidget->addTopLevelItem(newItem);
    }
    tree.travers.clear();

}

void MainWindow::on_traversPreorderButton_clicked()
{
      ui->arrayTreeWidget->clear();
    tree.TraversPreOrder();
    foreach(Node<QString> *item, tree.travers){
       QTreeWidgetItem *newItem = new QTreeWidgetItem(ui->arrayTreeWidget);
       newItem->setText(0, QString::number(item->_key));
       newItem->setText(1, item->_data);
       ui->arrayTreeWidget->addTopLevelItem(newItem);
    }
    tree.travers.clear();

}
