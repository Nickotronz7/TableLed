#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QFileDialog>
#include <QMessageBox>
#include <QKeyEvent>
#include <QtGui>
#include <QDockWidget>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QGraphicsScene>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    bool eventFilter(QObject *watched, QEvent *event);

    void insertKeywords(QString words, QTextCursor cursors, std::string color);


private slots:
    void veryKeywords();

    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionExit_triggered();

    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionBuild_All_triggered();

    void on_actionRun_triggered();

    void on_actionHelp_triggered();

    void on_actionAbout_us_triggered();

    void on_actionSettigs_triggered();

private:
    Ui::MainWindow *ui;
    QString bn;
};

#endif // MAINWINDOW_H
