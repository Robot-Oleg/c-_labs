#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(NULL));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushBackButton_clicked()
{
   circleList.PushBack(rand()%100);
   if (circleList.GetSize() == 1) ui->showLabel->setText(QString::number(circleList.GetByIndex(0)));
}


void MainWindow::on_moveLeftButton_clicked()
{
    ui->showLabel->setText(QString::number(circleList.GetByIndex(--position + circleList.GetSize())));
    if (position == -circleList.GetSize()) position = 0;
}

void MainWindow::on_moveRightButton_clicked()
{
    ui->showLabel->setText(QString::number(circleList.GetByIndex(++position)));
    if (position == circleList.GetSize()) position = 0;
}

void MainWindow::on_popButton_clicked()
{
    try {
        const char *queueIsEmptyDesc= "queue is empty";
        MyExeption *queueIsEmptyEx = new MyExeption(queueIsEmptyDesc);
       if (queue.IsEmpty()) throw queueIsEmptyEx;
    }  catch (MyExeption *ex) {
         QMessageBox::critical(NULL, "Error!", ex->what());
         return;
    }
    delete ui->queueListWidget->findItems(queue.Pop(), Qt::MatchExactly)[0];
}

void MainWindow::on_pushButton_clicked()
{
    queue.Push(ui->queueLineEdit->text());
    ui->queueListWidget->addItem(queue.Start());
}

void MainWindow::on_startAndEndButton_clicked()
{
    ui->startLabel->setText(queue.End());
    ui->endLabel->setText(queue.Start());
}
