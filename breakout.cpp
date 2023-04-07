#include "breakout.h"
#include <QKeyEvent>

Breakout::Breakout(QWidget *parent)
    : QWidget{parent},
      paddle(new Paddle{this, B_WIDTH/2 + 30 , B_HEIGHT}),
      ball(new Ball{this, BALL_DIAMETER, B_WIDTH/2, B_HEIGHT/2})
{
    setFixedSize(B_WIDTH, B_HEIGHT);
    setFocusPolicy(Qt::StrongFocus);
    setFocus();
    timerId = startTimer(DELAY);
}

void Breakout::checkCollision()
{
    QPoint pos = ball->getPosition();
    int x = pos.x();
    int y = pos.y();
    qDebug() << "ball x: " << x << "ball y: " << y;
    if (x == 0)
        ball->bounce(Bounce::RIGHT);
    else if (x == B_WIDTH - BALL_DIAMETER)
        ball->bounce(Bounce::LEFT);
    else if (y == 0)
        ball->bounce(Bounce::DOWN);
    else if (paddleCollision())
        ball->bounce(Bounce::UP);
    else
        ball->bounce(Bounce::NONE);
}

bool Breakout::paddleCollision()
{
    if (ball->getBottom() == paddle->getY() &&
        ball->getPosition().x() > paddle->getLeft() &&
        ball->getPosition().x() < paddle->getRight())
        return true;
    return false;
}

void Breakout::keyPressEvent(QKeyEvent* e)
{
    switch (e->key()) {
    case Qt::Key_Left:
        paddle->setDirection(Direction::Left);
        break;
    case Qt::Key_Right:
        paddle->setDirection(Direction::Right);
        break;
    default:
        paddle->setDirection(Direction::Invalid);
        break;
    }
    QWidget::keyPressEvent(e);
    keyPressed = true;
}

void Breakout::paintEvent(QPaintEvent* e)
{
    QPainter painter(this);
    painter.drawImage(paddle->getPosition(), paddle->getImage());
    painter.drawImage(ball->getPosition(), ball->getImage());
}

void Breakout::timerEvent(QTimerEvent* e)
{
    checkCollision();
    if (keyPressed)
        paddle->move();
    ball->move();

    update();
    keyPressed = false;
}

