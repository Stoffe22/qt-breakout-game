#include "breakout.h"
#include <QKeyEvent>

Breakout::Breakout(QWidget *parent)
    : QWidget{parent},
      paddle(new Paddle{this, B_WIDTH, B_HEIGHT}),
      ball(new Ball{this, B_WIDTH/2, B_HEIGHT/2})
{
    setFixedSize(B_WIDTH, B_HEIGHT);
    setFocusPolicy(Qt::StrongFocus);
    setFocus();
    timerId = startTimer(100);
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
}

void Breakout::timerEvent(QTimerEvent* e)
{
    if (keyPressed)
        paddle->move();

    update();
    keyPressed = false;
}

