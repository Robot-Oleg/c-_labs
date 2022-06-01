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

void MainWindow::on_addCandidate_clicked()
{
    QString name = ui->nameLineEdit->text(),
            dateOfBirth = ui->dateOfBirthLineEdit->text(),
            specialty = ui->specialtyLineEdit->text(),
            position = ui->positionLineEdit->text(),
            bachelorDegree = ui->bachelorDegreeLineEdit->text();
    int minSalary = ui->minSalaryLineEdit->text().toInt();

    QTreeWidgetItem *treeItem = new QTreeWidgetItem(ui->candidateTreeWidget);
    treeItem->setText(0, name);
    treeItem->setText(1, dateOfBirth);
    treeItem->setText(2, specialty);
    treeItem->setText(3, position);
    treeItem->setText(4, bachelorDegree);
    treeItem->setText(5, QString::number(minSalary));

    Candidate item(name, dateOfBirth, specialty, position, bachelorDegree, minSalary);
    candidateList.pushBack(item);
    UpdateCandidateList();
}

void MainWindow::on_addCompany_clicked()
{
     QString companyName = ui->companyNameLineEdit->text(),
            specialty = ui->companySpecialtyLineEdit->text(),
            position = ui->companyPositionLineEdit->text(),
            bachelorDegree = ui->companyBachelorDegreeLineEdit->text();
    int salary = ui->salaryLineEdit->text().toInt(),
        vacationDays = ui->salaryLineEdit->text().toInt(),
        minAge = ui->minAgeLineEdit->text().toInt(),
        maxAge = ui->maxAgeLineEdit->text().toInt();

    QTreeWidgetItem *treeItem = new QTreeWidgetItem(ui->companyTreeWidget);
    treeItem->setText(0, companyName);
    treeItem->setText(1, specialty);
    treeItem->setText(2, position);
    treeItem->setText(3, QString::number(salary));
    treeItem->setText(4, QString::number(vacationDays));
    treeItem->setText(5, QString::number(minAge));
    treeItem->setText(6, QString::number(maxAge));
    treeItem->setText(7, bachelorDegree);

    Company item(companyName, specialty, position, salary, vacationDays, minAge, maxAge, bachelorDegree);
    companyList.pushBack(item);
    UpdateCompanyList();
}


void MainWindow::on_listOfAvailableSpecialtysPushButton_clicked()
{
    QTreeWidgetItem *item = ui->candidateTreeWidget->currentItem();
    for (int i = 0; i < candidateList.GetSize(); i++){
        if (candidateList[i].GetName() == item->text(0)){
            for (int j = 0; j < companyList.GetSize(); j++){
                if (candidateList[i].GetPosition() == companyList[j].GetPosition() && candidateList[i].GetSpecilty() == companyList[j].GetSpecilty() && candidateList[i].GetMinSalary() <= companyList[j].GetSalary()){
                    ui->listWidget->addItem(companyList[j].GetPosition());
                }
            }
        }
    }

}

void MainWindow::on_openCompanyFilePushButton_clicked()
{
    QString companyFileName = QFileDialog::getOpenFileName(this, tr("open company.txt file"), "/home/robot/University/OAIP/lab2/", tr("Text files(*.txt)"));
    QFile companyFile(companyFileName);

    if (!companyFile.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "ERROR", "file is not open");
    }
    else {
        ui->companyTreeWidget->clear();
        QTextStream in(&companyFile);
        int index = 0;
        while (!in.atEnd()) {
                QString company[8];
                while (index  < 8) {
                company[index++] = in.readLine();
            }
            index = 0;
            QTreeWidgetItem *treeItem = new QTreeWidgetItem(ui->companyTreeWidget);
            treeItem->setText(0, company[0]);
            treeItem->setText(1, company[1]);
            treeItem->setText(2, company[2]);
            treeItem->setText(3, company[3]);
            treeItem->setText(4, company[4]);
            treeItem->setText(5, company[5]);
            treeItem->setText(6, company[6]);
            treeItem->setText(7, company[7]);

            Company item(company[0], company[1], company[2], company[3].toInt(), company[4].toInt(), company[5].toInt(), company[6].toInt(), company[7]);
            companyList.pushBack(item);
        }
    }
}

void MainWindow::on_openCandiateFilePushButton_clicked()
{
    QString candidateFileName = QFileDialog::getOpenFileName(this, tr("open candidate.txt file"), "/home/robot/University/OAIP/lab2/", tr("Text files(*.txt)"));
    QFile candidateFile(candidateFileName);

    if (!candidateFile.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "ERROR", "file is not open");
    }
    else {
        ui->candidateTreeWidget->clear();
        QTextStream in(&candidateFile);
        int index = 0;
        while (!in.atEnd()) {
                QString candidate[6];
                while (index < 6) {
                candidate[index++] = in.readLine();
            }
            index = 0;
            QTreeWidgetItem *treeItem = new QTreeWidgetItem(ui->candidateTreeWidget);
            treeItem->setText(0, candidate[0]);
            treeItem->setText(1, candidate[1]);
            treeItem->setText(2, candidate[2]);
            treeItem->setText(3, candidate[3]);
            treeItem->setText(4, candidate[4]);
            treeItem->setText(5, candidate[5]);

            Candidate item(candidate[0], candidate[1], candidate[2], candidate[3], candidate[4], candidate[5].toInt());
            candidateList.pushBack(item);
            candidateFile.close();
        }
    }
}

void MainWindow::UpdateCandidateList()
{
    QFile candidateFile("/home/robot/University/OAIP/lab2/candidate.txt");
    if (!candidateFile.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "ERROR", "file is not open");
    }
    else {
        QTextStream write(&candidateFile);
        for (int index = 0; index < candidateList.GetSize(); index++){
            write << candidateList[index].GetName() << "\n";
            write << candidateList[index].GetDateOfBirth() << "\n";
            write << candidateList[index].GetSpecilty() << "\n";
            write << candidateList[index].GetPosition() << "\n";
            write << candidateList[index].GetBachelorDegree() << "\n";
            write << candidateList[index].GetMinSalary() << "\n";
        }
        candidateFile.flush();
        candidateFile.close();
    }

}

void MainWindow::UpdateCompanyList()
{
    QFile companyFile("/home/robot/University/OAIP/lab2/company.txt");
    if (!companyFile.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "ERROR", "file is not open");
    }
    else {
        QTextStream write(&companyFile);
        for (int index = 0; index < companyList.GetSize(); index++){
            write << companyList[index].GetCompanyName() << "\n";
            write << companyList[index].GetSpecilty() << "\n";
            write << companyList[index].GetPosition() << "\n";
            write << companyList[index].GetSalary() << "\n";
            write << companyList[index].GetVacationDays() << "\n";
            write << companyList[index].GetMinAge() << "\n";
            write << companyList[index].GetMaxAge() << "\n";
            write << companyList[index].GetBachelorDegree() << "\n";
        }
        companyFile.flush();
        companyFile.close();
    }
}

void MainWindow::on_clearPushButton_clicked()
{
    ui->listWidget->clear();
}


void MainWindow::on_deleteCandidatePushButton_clicked()
{
    for (int i = 0; i < candidateList.GetSize(); i++){
        if (candidateList[i].GetName() == ui->candidateTreeWidget->currentItem()->text(0)){
            candidateList.Delete(i);
            break;
        }
    }
    delete ui->candidateTreeWidget->currentItem();
    UpdateCandidateList();
}

void MainWindow::on_deleteCompanyPushButton_clicked()
{
    for (int i = 0; i < companyList.GetSize(); i++){
        if (companyList[i].GetCompanyName() == ui->companyTreeWidget->currentItem()->text(0)){
            companyList.Delete(i);
            break;
        }
    }
    delete ui->candidateTreeWidget->currentItem();
    UpdateCompanyList();
}

void MainWindow::on_listOfRareSpeciltyPushButton_clicked()
{
    int count = 0;
    for (int i = 0; i < companyList.GetSize(); i++) {
        for(int j = 0; i < candidateList.GetSize(); j++) {
            if (companyList[i].GetSpecilty() == candidateList[j].GetSpecilty()) {
                count++;
            }
        }
        if (count == 0) ui->listWidget->addItem(companyList[i].GetSpecilty());
    }
}

void MainWindow::on_listOfFirmsWithoutAnyCandidatePushButton_clicked()
{
    int count = 0;
    for (int i = 0; i < companyList.GetSize(); i++) {
        for(int j = 0; i < candidateList.GetSize(); j++) {
            if (companyList[i].GetSpecilty() == candidateList[j].GetSpecilty()) {
                count++;
            }
        }
        if (count == 0) ui->listWidget->addItem(companyList[i].GetCompanyName());
    }
}
