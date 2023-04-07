#include "ball.h"

Ball::Ball(QWidget *parent, int diameter, int x0, int y0)
    : QWidget{parent}, d{diameter}, x{x0}, y{y0}
{
    QPixmap ball_pm;
    ball_pm.load("/Users/jonason/Documents/code/projects/qt/snake/dot.png");
    ball_pm = ball_pm.scaled(diameter, diameter, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ball_img = ball_pm.toImage();
    vel.setVelocity(0, 1);

}

void Ball::move()
{
    switch (bounceDir) {
    case Bounce::LEFT:
        vel.vx = -vel.vx;
        break;
    case Bounce::RIGHT:
        vel.vx = -vel.vx;
        break;
    case Bounce::DOWN:
        vel.vy = -vel.vy;
        break;
    case Bounce::UP:
        vel.vy = -vel.vy;
        break;
    default:
        break;
    }
    x += vel.vx;
    y += vel.vy;
}
