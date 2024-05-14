#ifndef RBT_H
#define RBT_H

#include <QMainWindow>

namespace Ui {
class RBT;
}

class RBT : public QMainWindow
{
    Q_OBJECT

public:
    explicit RBT(QWidget *parent = nullptr);
    ~RBT();

private:
    Ui::RBT *ui;
};

#endif // RBT_H
