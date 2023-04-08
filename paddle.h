#ifndef PADDLE_H
#define PADDLE_H

#include "direction.h"
#include <QWidget>


static const int MOVE_LEN = 10;

class Paddle : public QWidget
{
    Q_OBJECT

public:
    explicit Paddle(QWidget *parent = nullptr, int w = 20, int h = 10, int x0 = 0, int y0 = 0);

    const QImage& getImage() const{ return paddle_img; }
    QPoint getPosition() { return QPoint(x, y); }
    void setDirection(Direction d) { dir = d; }
    int getLeft() { return x; }
    int getRight() { return x + w; }
    int getY() { return y; }
    void move();

private:
    int w;
    int h;
    QImage paddle_img;
    int x;
    int y;
    int x_init;
    int y_init;
    Direction dir;

signals:

};



#endif // PADDLE_H
