#include "mainwindow.h"
#include "ui_mainwindow.h"

std::string lineNumber;

int lineNumberT = 1;
std::vector <std::string> KeyWords;
bool endComment = true;
bool compiled = false;

int fw;
QColor tc;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
    ui->textEdit->installEventFilter(this);
    ui->textBrowser->insertPlainText(QString::fromStdString(std::to_string(lineNumberT) + "\n"));
    lineNumberT += 1;

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

bool MainWindow::eventFilter(QObject *watched, QEvent *event){
    if (watched == ui->textEdit){
        if (event->type() == QEvent::KeyPress){
            QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Return){
                lineNumber = std::to_string(lineNumberT) + "\n";
                ui->textBrowser->insertPlainText(QString::fromStdString(lineNumber));
                lineNumberT += 1;
                //ui->textEdit->insertPlainText("\n");
            }
            if (keyEvent->key() == Qt::Key_Backspace){
                disconnect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(veryKeywords()));
                //std::string linea = ui->lineTextEdit->toPlainText();
                QTextCursor cursor = ui->textEdit->textCursor();
                cursor.select(QTextCursor::LineUnderCursor);
                QString word = cursor.selectedText();

                int lengthText = ui->textEdit->toPlainText().length();
                int posCursor = cursor.position();

                qInfo() << "word: "  << word;
                qInfo() << "length text: " << lengthText;
                qInfo() << "cursor position: " << posCursor;
                qInfo() << "linea actual: " << lineNumberT-1;

                if ((word == "") && (lengthText == posCursor)){
                   ui->textBrowser->setText("");

                   for (int i = 1; i < (lineNumberT-1); i++){
                       ui->textBrowser->insertPlainText(QString::fromStdString(std::to_string(i) + "\n"));
                   }
                   lineNumberT = lineNumberT-1;
                   if(lineNumberT < 1){
                       lineNumberT = 1;
                   }
                }

            }
            else{
                connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(veryKeywords()));
            }
        }
    }
    return QMainWindow::eventFilter(watched, event);
}

void MainWindow::veryKeywords(){

    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.select(QTextCursor::WordUnderCursor);
    QString word = cursor.selectedText();

    if (word == "D"){
        insertKeywords(word, cursor, "#29088A");
    }
    if (word == "P"){
        insertKeywords(word, cursor, "#29088A");
    }
    if (word == "Call"){
        insertKeywords(word, cursor, "#29088A");
    }
    if (word == "TurnOn"){
        insertKeywords(word, cursor, "#B40486");
    }
    if (word == "TurnOf"){
        insertKeywords(word, cursor, "#B40486");
    }
    if (word == "TurnON"){
        insertKeywords(word, cursor, "#B40486");
    }
    if (word == "TurnOFF"){
        insertKeywords(word, cursor, "#B40486");
    }
    if (word == "SoundOn"){
        insertKeywords(word, cursor, "#B40486");
    }
    if (word == "SoundOff"){
        insertKeywords(word, cursor, "#B40486");
    }
    if (word == "+"){
        insertKeywords(word, cursor, "#ff6732");
    }
    if (word == "-"){
        insertKeywords(word, cursor, "#ff6732");
    }
    if (word == "dow"){
        insertKeywords(word, cursor, "#01DFA5");
    }
    if (word == "Exit"){
        insertKeywords(word, cursor, "#01DFA5");
    }
    if (word == "Enddo"){
        insertKeywords(word, cursor, "#01DFA5");
    }
    if (word == "For"){
        insertKeywords(word, cursor, "#01DFA5");
    }
    if (word == "Times"){
        insertKeywords(word, cursor, "#B40486");
    }
    if (word == "Time"){
        insertKeywords(word, cursor, "#B40486");
    }
    if (word == "FEnd"){
        insertKeywords(word, cursor, "#01DFA5");
    }
    if (word == "FEnd"){
        insertKeywords(word, cursor, "#01DFA5");
    }
    if (word == "If"){
        insertKeywords(word, cursor, "#01DFA5");
    }
    if (word == "elseIf"){
        insertKeywords(word, cursor, "#01DFA5");
    }
    if (word == "else"){
        insertKeywords(word, cursor, "#01DFA5");
    }
    if (word == "Endif"){
        insertKeywords(word, cursor, "#01DFA5");
    }

    else{
        QTextCursor cursorLine = ui->textEdit->textCursor();
        cursorLine.select(QTextCursor::LineUnderCursor);
        QString line = cursorLine.selectedText();
        if ( line == "/* " ){
            fw = ui->textEdit->fontWeight();
            tc = ui->textEdit->textColor();


            QTextCharFormat format(cursorLine.charFormat());
            format.setForeground(QColor(QString::fromStdString("#42F453")));
            cursorLine.insertText(line + "  ", format);
            endComment = false;
        }
        else if (line.contains(">>")){
            endComment = true;
            ui->textEdit->setFontWeight( fw );
            ui->textEdit->setTextColor( tc );
        }
    }



}

void MainWindow::insertKeywords(QString words, QTextCursor cursors, std::string color){
    int fw = ui->textEdit->fontWeight();
    QColor tc = ui->textEdit->textColor();

    QTextCharFormat format(cursors.charFormat());
    format.setForeground(QColor(QString::fromStdString(color)));
    cursors.insertText(words + " ", format);

    // restore

    ui->textEdit->setFontWeight( fw );
    ui->textEdit->setTextColor( tc );
}
