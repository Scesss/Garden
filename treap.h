#ifndef TREAP_H
#define TREAP_H

#include <QMainWindow>

namespace Ui {
class TREAP;
}

class TREAP : public QMainWindow
{
    Q_OBJECT

public:
    explicit TREAP(QWidget *parent = nullptr);
    ~TREAP();

private:
    Ui::TREAP *ui;
};

#endif // TREAP_H
