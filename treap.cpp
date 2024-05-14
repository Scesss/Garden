#include "treap.h"
#include "ui_treap.h"

TREAP::TREAP(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TREAP)
{
    ui->setupUi(this);
}

TREAP::~TREAP()
{
    delete ui;
}
