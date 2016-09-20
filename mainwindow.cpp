#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionBuscar_2_triggered()
{

}

void MainWindow::on_actionLoad_from_File_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Open File"),"/home","All files (*.*);;Text File (*.txt)");
    QMessageBox::information(this,tr("Archivo Seleccionado"),filename);
    vector <vector <string> > data;
    const char* fname = filename.toStdString().c_str();
    ifstream myReadFile(fname);

    while(myReadFile){
        string s;
        if(!getline( myReadFile, s)) break;
        istringstream ss(s);
        vector <string> record;
        while(ss){
            string s;
            if(!getline(ss,s,',')) break;
            record.push_back(s);
        }
        data.push_back(record);
    }
    if(!myReadFile.eof()){
        cerr << "uhmm?\n";
    }

}
