#ifndef SPLAYT_H
#define SPLAYT_H

#include <QMainWindow>

namespace Ui {
class SPLAYT;
}

class SPLAYT : public QMainWindow
{
    Q_OBJECT

public:
    explicit SPLAYT(QWidget *parent = nullptr);
    ~SPLAYT();

private:
    Ui::SPLAYT *ui;
};

#endif // SPLAYT_H
