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


void MainWindow::on_translatePushButton_clicked()
{
    QMap<QChar, int> map;
    map['('] = 1;
    map[')'] = 1;
    map['+'] = 2;
    map['-'] = 2;
    map['*'] = 3;
    map['/'] = 3;
    QString str,
            polishStr,
            number,
            signs = "()+-*/";

    try {
        str = ui->inputLineEdit->text();

        const char *wrongBracketsNumberDesc = "not enough brackets";
        MyExeption *wrongBracketsNumberEx = new MyExeption(wrongBracketsNumberDesc);

        int count = 0;
        foreach(QChar a, str) {
           if (a == '(') count++;
           if (a == ')') count--;
        }
        if (count != 0) throw wrongBracketsNumberEx;
    }  catch (MyExeption *ex) {
            QMessageBox::critical(NULL, "Error!", ex->what());
            return;
    }
        foreach(QChar a, str){
         if (signs.contains(a)) {

             if (!number.isEmpty()) {
                 calculate.Push(number.toDouble());
                 number.clear();
             }

             switch (a.unicode()) {
                case u'(':
                    translate.Push(a);
                    break;
                case u')':
                    while(translate.Top() != '(') {
                        QChar operation = translate.Pop();
                        calculate.Push(Calculate(calculate.Pop(), calculate.Pop(), operation));
                        polishStr.append(operation);
                    }
                    translate.Pop();
                    break;
                default:
                    if (translate.IsEmpty() || map[translate.Top()] < map[a]) translate.Push(a);
                    else {
                        while (!translate.IsEmpty() && map[translate.Top()] >= map[a]) {
                            QChar operation = translate.Pop();
                            calculate.Push(Calculate(calculate.Pop(), calculate.Pop(), operation));
                            polishStr.append(operation);

                        }
                        translate.Push(a);
                    }
              }
         }
         else {
             polishStr.append(a);
             number.append(a);
         }
    }
    if (!number.isEmpty()) {
        calculate.Push(number.toDouble());
        number.clear();
    }

    while (!translate.IsEmpty()) {
        QChar operation = translate.Pop();
        calculate.Push(Calculate(calculate.Pop(), calculate.Pop(), operation));
        polishStr.append(operation);

    }
        ui->outputLabel->setText(polishStr);
}

void MainWindow::on_answerPushButton_clicked()
{
        ui->answerLabel->setText(QString::number(calculate.Pop()));
}

double MainWindow::Calculate(double a, double b, QChar operation)
{
    switch (operation.unicode()) {
        case u'+':
            return a+b;
            break;
        case u'-':
            return a-b;
            break;
        case u'*':
            return a*b;
            break;
        case u'/':
            return a/b;
            break;
    }
}


