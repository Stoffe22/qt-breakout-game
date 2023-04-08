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
    gameOver = false;
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
    if (ball->getBottom() >= B_HEIGHT)
    {
        gameOver = true;
        return;
    }

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

// NOTE: This function doesn't work as expected, sometimes the ball goes throught the bricks
bool Breakout::checkBrickCollision()
{
    int bottom, top, left, right;
    for (auto it = bricks.begin(); it != bricks.end(); it++)
    {
       if ((ball->getTop() == (*it)->getBottom()) && (ball->getLeft() >= (*it)->getLeft()) && (ball->getRight() <= (*it)->getRight()))
       {
           ball->bounce(Bounce::DOWN);
           bricks.erase(it);
           return true;
       }
       else if ((ball->getBottom() == (*it)->getTop()) && (ball->getLeft() >= (*it)->getLeft()) && (ball->getRight() <= (*it)->getRight()))
       {
           ball->bounce(Bounce::UP);
           bricks.erase(it);
           return true;
       }
       else if ((ball->getLeft() == (*it)->getRight()) && (ball->getCenterY() <= (*it)->getBottom()) && (ball->getCenterY() >= (*it)->getTop()))
       {
           ball->bounce(Bounce::RIGHT);
           bricks.erase(it);
           return true;
       }
       else if ((ball->getRight() == (*it)->getLeft()) && (ball->getCenterY() <= (*it)->getBottom()) && (ball->getCenterY() >= (*it)->getTop()))
       {
           ball->bounce(Bounce::LEFT);
           bricks.erase(it);
           return true;
       }
    }
    return false;
}



bool Breakout::checkPaddleCollision()
{
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
    if (!gameOver)
    {
        painter.drawImage(paddle->getPosition(), paddle->getImage());
        painter.drawImage(ball->getPosition(), ball->getImage());
        for (const auto& brick : bricks)
        {
            painter.drawImage(brick->getPosition(), brick->getImage());
        }
    }
    else
    {
        printMessage(painter, "Game Over");
        return;
    }

    if (bricks.size() == 0)
    {
        printMessage(painter, "Game Won");
        killTimer(timerId);
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

void Breakout::printMessage(QPainter& qp, QString&& message)
{
    QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.horizontalAdvance(message);

    qp.setFont(font);
    int w = width();
    int h = height();

    qp.translate(QPoint(w/2, h/2));
    qp.drawText(-textWidth/2, 0 , message);
}




