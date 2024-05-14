#include "splayt.h"
#include "ui_splayt.h"

SPLAYT::SPLAYT(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SPLAYT)
{
    ui->setupUi(this);
}

SPLAYT::~SPLAYT()
{
    delete ui;
}
