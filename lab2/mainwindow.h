#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "list.h"
#include "list.cpp"
#include "candidate.h"
#include "company.h"
#include <QFileDialog>
#include <QMessageBox>

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
    void on_addCandidate_clicked();

    void on_addCompany_clicked();

    void on_pushButton_clicked();

    void on_listOfAvailableSpecialtysPushButton_clicked();

    void on_openFilePushButton_clicked();

    void on_clearPushButton_clicked();

    void on_openCompanyFilePushButton_clicked();

    void on_openCandiateFilePushButton_clicked();

    void on_deleteCandidatePushButton_clicked();

    void on_deleteCompanyPushButton_clicked();

    void on_listOfRareSpeciltyPushButton_clicked();

    void on_listOfFirmsWithoutAnyCandidatePushButton_clicked();

private:
    Ui::MainWindow *ui;
    List<Company> companyList;
    List<Candidate> candidateList;
    void UpdateCandidateList();
    void UpdateCompanyList();
};
#endif // MAINWINDOW_H
