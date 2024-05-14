#include "rbt.h"
#include "ui_rbt.h"

RBT::RBT(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RBT)
{
    ui->setupUi(this);
}

RBT::~RBT()
{
    delete ui;
}
