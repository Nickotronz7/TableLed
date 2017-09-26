#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_actionNew_triggered()
{
    bn= "";
    ui->textEdit->setPlainText("");
}

void MainWindow::on_actionOpen_triggered()
{
    QString file = QFileDialog::getOpenFileName(this,"Select a File to Open");

    if(!file.isEmpty()){
        QFile archT(file);
        if(archT.open(QFile::ReadOnly | QFile::Text)){
            bn=file;
            QTextStream n(&archT);
            QString tex = n.readAll();
            archT.close();
            ui->textEdit->setPlainText(tex);
        }
    }
}

void MainWindow::on_actionSave_triggered()
{
    QFile archJ(bn);
    if(archJ.open(QFile::WriteOnly | QFile::Text)){
        QTextStream stream(&archJ);
        stream <<  ui->textEdit->toPlainText();
        archJ.flush();
        archJ.close();
    }
}

void MainWindow::on_actionSave_As_triggered()
{
    QString file = QFileDialog::getSaveFileName(this,"Save As");
    if(!file.isEmpty()){
        bn=file;
        on_actionSave_triggered();
    }
}

void MainWindow::on_actionExit_triggered()
{

}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
   ui->textEdit->redo();
}

void MainWindow::on_actionBuild_All_triggered()
{

}

void MainWindow::on_actionRun_triggered()
{

}

void MainWindow::on_actionHelp_triggered()
{
    QMessageBox::information(this,"Help","ejemplo de menu help");
}

void MainWindow::on_actionAbout_us_triggered()
{

}

void MainWindow::on_actionSettigs_triggered()
{
    QMessageBox::information(this,"About Us","Integrated Development Environment(IDE) developted by Kevin González Sanabria, Computer Engineering Student at ITCR.");

}
