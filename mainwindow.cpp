#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "avlt.h"
#include "rbt.h"
#include "splayt.h"
#include "treap.h"

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

void MainWindow::on_pushButton_clicked()
{
    auto my = new AVLT();
    my->show();
    hide();
}


void MainWindow::on_pushButton_2_clicked()
{
    auto my = new RBT();
    my->show();
    hide();
}


void MainWindow::on_pushButton_3_clicked()
{
    auto my = new SPLAYT();
    my->show();
    hide();
}


void MainWindow::on_pushButton_4_clicked()
{
    auto my = new TREAP();
    my->show();
    hide();
}

