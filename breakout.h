#ifndef BREAKOUT_H
#define BREAKOUT_H

#include "paddle.h"
#include "ball.h"
#include "brick.h"
#include <QWidget>
#include <QGridLayout>


static const int B_WIDTH = 500;
static const int B_HEIGHT = 500;
static const int P_WIDTH = 50;
static const int P_HEIGHT = 20;
static const int BRICK_WIDTH = 50;
static const int BRICK_HEIGHT = 20;
static const int BRICK_OFFSET = 5;
static const int BRICKS_COLUMNS = B_WIDTH / (BRICK_WIDTH + BRICK_OFFSET);
static const int BRICKS_ROWS = 5;
static const int BALL_DIAMETER = 20;
static const int DELAY= 5;

class Breakout : public QWidget
{
    Q_OBJECT
public:
    explicit Breakout(QWidget *parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent* e) override;
    void timerEvent(QTimerEvent* e) override;
    void paintEvent(QPaintEvent* e) override;

private:
    void checkCollision();
    bool checkPaddleCollision();
    bool checkBrickCollision();
    bool checkWallCollision();
    void gameOverMessage(QPainter& qp);

    bool gameOver;
    int timerId;
    bool keyPressed;

    QGridLayout* grid;
    std::unique_ptr<Paddle> paddle;
    std::unique_ptr<Ball> ball;
    std::vector<std::unique_ptr<Brick>> bricks;
signals:

};

#endif // BREAKOUT_H
