#include "breakout.h"
#include <QKeyEvent>
#include <QGridLayout>
#include <QPainter>

Breakout::Breakout(QWidget *parent)
    : QWidget{parent},
      grid(new QGridLayout()),
      paddle(new Paddle{this, P_WIDTH, P_HEIGHT, B_WIDTH/2, B_HEIGHT}),
      ball(new Ball{this, BALL_DIAMETER, B_WIDTH/2, B_HEIGHT/2})
{
    setFixedSize(B_WIDTH, B_HEIGHT);
    setFocusPolicy(Qt::StrongFocus);
    setFocus();

    int xOffset, yOffset = 0;
    for (int row = 0; row < BRICKS_ROWS; row++)
    {
        xOffset = BRICK_OFFSET;
        yOffset += BRICK_OFFSET;
        for (int col = 0; col < BRICKS_COLUMNS; col++)
        {
            int x = col * BRICK_WIDTH + xOffset;
            int y = row * BRICK_HEIGHT + yOffset;
            std::unique_ptr<Brick> b = std::make_unique<Brick>(BRICK_WIDTH, BRICK_HEIGHT, x, y);
            bricks.emplace_back(std::move(b));
            grid->addWidget(b.get(), row, col);
            xOffset += BRICK_OFFSET;
        }
    }

    timerId = startTimer(DELAY);
}

void Breakout::checkCollision()
{
    if (checkWallCollision())
        return;
    if (checkPaddleCollision())
        return;
    if (checkBrickCollision())
        return;

    ball->bounce(Bounce::NONE);
}

bool Breakout::checkWallCollision()
{
    if (ball->getLeft() <= 0)
    {
        ball->bounce(Bounce::RIGHT);
        return true;
    }
    else if (ball->getRight() >= B_WIDTH)
    {
        ball->bounce(Bounce::LEFT);
        return true;
    }
    else if (ball->getTop() <= 0)
    {
        ball->bounce(Bounce::DOWN);
        return true;
    }
    return false;
}

bool Breakout::checkBrickCollision()
{
    int bottom, top, left, right;
    for (auto it = bricks.begin(); it != bricks.end(); it++)
    {
       if (ball->getTop() == (*it)->getBottom())
       {
           ball->bounce(Bounce::DOWN);
           return true;
       }
    }
    return false;
}



bool Breakout::checkPaddleCollision()
{
    qDebug() << "ball bottom:" << ball->getBottom();
    qDebug() << "paddle top" << paddle->getY();
    qDebug() << "ball left: " << ball->getLeft();
    qDebug() << "paddle left: " << paddle->getLeft();
    qDebug() << "paddle right: " << paddle->getRight();
    if (ball->getBottom() == paddle->getY() &&
        ball->getRight() > paddle->getLeft() &&
        ball->getLeft() < paddle->getRight())
    {
        ball->bounce(Bounce::UP);
        return true;
    }
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
    for (const auto& brick : bricks)
    {
        painter.drawImage(brick->getPosition(), brick->getImage());
    }
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

