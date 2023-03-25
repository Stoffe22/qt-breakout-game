#include "ball.h"

Ball::Ball(QWidget *parent, int x0, int y0)
    : QWidget{parent}, x_init{x0}, y_init{y0}, ball(new QGraphicsEllipseItem(x_init, y_init, RADIUS, RADIUS))
{
    ball->setBrush(QBrush(Qt::white));
}

void move()
{
    //ball->move
}

