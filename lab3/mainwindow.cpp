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


void MainWindow::on_addPushButton_clicked()
{
    try {
        const char *wrongLengthDesc = "field must contain smth";
        MyExeption *wrorngLengthEx = new MyExeption(wrongLengthDesc);


        if (ui->nameLineEdit->text().isEmpty()) throw wrorngLengthEx;
        if (ui->numberLineEdit->text().isEmpty()) throw wrorngLengthEx;
        if (ui->priceLineEdit->text().isEmpty()) throw wrorngLengthEx;
    }
    catch (MyExeption *ex) {
       QMessageBox::critical(NULL, "Error!", ex->what());
       return;
    }
    QString name = ui->nameLineEdit->text();
    int day = ui->daySpinBox->value();
    int month = ui->monthSpinBox->value();
    int year = ui->yearSpinBox->value();
    int number = ui->numberLineEdit->text().toInt();
    int price = ui->priceLineEdit->text().toInt();
    Product item(name, day, month, year, number, price);
    if (number == 0) {
        expectedProductList.PushBack(item);
        ui->expectedListWidget->addItem(name);
    }
    else {
        productList.PushBack(item);
        ui->productListWidget->addItem(name);
    }
}

void MainWindow::on_showPushButton_clicked()
{
   for (int i = 0; i < productList.GetSize(); i++){
        if (productList.GetSize() != 0 && ui->productLineInput->text() == productList.GetByIndex(i).GetName()){
            Product item = productList.GetByIndex(i);
            ui->showProductListWidget->addItem(QString::number(item.GetDay()) + "-" +  QString::number(item.GetMonth()) + "-" + QString::number(item.GetYear()));
            ui->showProductListWidget->addItem(QString::number(item.GetNumber()));
            ui->showProductListWidget->addItem(QString::number(item.GetPrice()));
        }
    }

   for (int i = 0; i < expectedProductList.GetSize(); i++){
        if (expectedProductList.GetSize() != 0 && ui->productLineInput->text() == expectedProductList.GetByIndex(i).GetName()){
            Product item = expectedProductList.GetByIndex(i);
            ui->showProductListWidget->addItem(item.GetDate());
            ui->showProductListWidget->addItem(QString::number(item.GetDay()) + "-" +  QString::number(item.GetMonth()) + "-" + QString::number(item.GetYear()));
            ui->showProductListWidget->addItem(QString::number(item.GetPrice()));
        }
    }
}


void MainWindow::on_datePushButton_clicked()
{
    QString inputDate = ui->productByDateLineEdit->text();
    for (int i = 0; i < productList.GetSize(); i++){
            Product item = productList.GetByIndex(i);
            int productDate = QDateTime::currentDateTime().toString("yyyy").toInt()*365
                    + QDateTime::currentDateTime().toString("MM").toInt()*31
                    + QDateTime::currentDateTime().toString("dd").toInt()
                    - item.GetDataInDays();
        if (productList.GetSize() != 0 && productDate > inputDate.toInt()) {
            ui->showProductListWidget->addItem(item.GetName());
            ui->showProductListWidget->addItem(QString::number(item.GetDay()) + "-" +  QString::number(item.GetMonth()) + "-" + QString::number(item.GetYear()));
            ui->showProductListWidget->addItem(QString::number(item.GetNumber()));
            ui->showProductListWidget->addItem(QString::number(item.GetPrice()));
        }
     }
}



void MainWindow::on_pricePushButton_clicked()
{
    for (int i = 0; i < productList.GetSize(); i++){
            if (productList.GetSize() != 0 && ui->productByPriceLineEdit->text().toInt() > productList.GetByIndex(i).GetPrice()){
            Product item = productList.GetByIndex(i);
            ui->showProductListWidget->addItem(item.GetName());
            ui->showProductListWidget->addItem(QString::number(item.GetDay()) + "-" +  QString::number(item.GetMonth()) + "-" + QString::number(item.GetYear()));
            ui->showProductListWidget->addItem(QString::number(item.GetNumber()));
            ui->showProductListWidget->addItem(QString::number(item.GetPrice()));
        }
    }
    for (int i = 0; i < expectedProductList.GetSize(); i++){
        if (expectedProductList.GetSize() != 0 && ui->productByPriceLineEdit->text().toInt() > expectedProductList.GetByIndex(i).GetPrice()){
            Product item = expectedProductList.GetByIndex(i);
            ui->showProductListWidget->addItem(item.GetName());
            ui->showProductListWidget->addItem(item.GetDate());
            ui->showProductListWidget->addItem(QString::number(item.GetDay()) + "-" +  QString::number(item.GetMonth()) + "-" + QString::number(item.GetYear()));
            ui->showProductListWidget->addItem(QString::number(item.GetPrice()));
        }
    }
}



void MainWindow::on_clearPushButton_clicked()
{
   ui->showProductListWidget->clear();
}
