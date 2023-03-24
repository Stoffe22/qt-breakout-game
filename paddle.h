#ifndef PADDLE_H
#define PADDLE_H

#include <QWidget>

class Paddle : public QWidget
{
    Q_OBJECT

public:
    explicit Paddle(QWidget *parent = nullptr, int x0 = 0, int y0 = 0);

    const QRect& getRect() const { return rect; }

private:
    static const int P_WIDTH = 50;
    static const int P_HEIGHT = 20;
    int x;
    int y;
    int x_init;
    int y_init;
    int dx = 10;

    QRect rect;

signals:

};

#endif // PADDLE_H
