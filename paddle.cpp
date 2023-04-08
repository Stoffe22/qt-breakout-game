#include "paddle.h"

Paddle::Paddle(QWidget *parent, int width, int height, int x0, int y0)
    : QWidget(parent), w(width), h(height), x_init(x0), y_init(y0)
{
    QRect rect(x_init - w*2, y_init - h*2, w, h);
    x = rect.topLeft().x();
    y = rect.topLeft().y();
    QPixmap pixmap(rect.size());
    pixmap.fill(Qt::white);
    paddle_img = pixmap.toImage();
}

void Paddle::move()
{
    if (dir == Direction::Invalid)
        return;

    int dx = dir == Direction::Left ? -MOVE_LEN : MOVE_LEN;
    x += dx;
}


