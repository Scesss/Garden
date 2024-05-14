#include "avlt.h"
#include "ui_avlt.h"
#include "QGraphicsEllipseItem"
#include "QGraphicsScene"
#include <iostream>
#include <cmath>


AVLT::AVLT(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AVLT)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

}

AVLT::~AVLT()
{
    delete ui;
}


QGraphicsEllipseItem vertex(int x, int y, int r, QGraphicsScene *scene) {
    QBrush br(Qt::red);
    QPen whitePen(Qt::white);
    whitePen.setWidth(3);
    QGraphicsEllipseItem *vert;
    vert = scene->addEllipse(x, y, r, r, whitePen);
    vert->setFlag(QGraphicsItem::ItemIsSelectable);
    return *vert;
}



void AVLT::on_pushButton_clicked()
{

    auto vert = vertex(50, 50, 50, scene);




    // scene->addEllipse(50, 50, 50, 50, whitePen, br);
    // ellipse = scene->addEllipse(75, 120, 100, 100, whitePen, br);

    // // ellipse->;

    // ellipse->setFlag(QGraphicsItem::ItemIsSelectable);

    // scene->removeItem(vert);

}


void AVLT::on_pushButton_2_clicked()
{
    // if (ellipse->isSelected()) scene->addText("huio");

}

