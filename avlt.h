#ifndef AVLT_H
#define AVLT_H

#include <QMainWindow>
#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>

namespace Ui {
class AVLT;
}

class AVLT : public QMainWindow
{
    Q_OBJECT

public:
    explicit AVLT(QWidget *parent = nullptr);
    ~AVLT();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AVLT *ui;
    QGraphicsScene *scene;
};

#endif // AVLT_H
