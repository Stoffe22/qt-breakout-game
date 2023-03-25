#include "paddle.h"

Paddle::Paddle(QWidget *parent, int x0, int y0)
    : QWidget(parent), x_init{x0}, y_init{y0}
{
    rect = QRect{x_init - P_WIDTH, y_init, P_WIDTH, P_HEIGHT};
}

void Paddle::move()
{
    if (dir == Direction::Invalid)
        return;

    int dx = dir == Direction::Left ? MOVE_LEN : -MOVE_LEN;
    rect.translate(dx, 0);
}


