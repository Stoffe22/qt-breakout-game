#ifndef PADDLE_H
#define PADDLE_H

#include "direction.h"
#include <QWidget>

static const int P_WIDTH = 50;
static const int P_HEIGHT = 20;
static const int MOVE_LEN = 10;

class Paddle : public QWidget
{
    Q_OBJECT

public:
    explicit Paddle(QWidget *parent = nullptr, int x0 = 0, int y0 = 0);

    QRect& getRect() { return rect; }
    void setDirection(Direction d) {dir = d;}
    void move();

private:
    int x;
    int y;
    int x_init;
    int y_init;
    Direction dir;
    QRect rect;

signals:

};



#endif // PADDLE_H
