#ifndef BREAKOUT_H
#define BREAKOUT_H

#include "paddle.h"
#include "ball.h"
#include "brick.h"
#include <QWidget>
#include <QGridLayout>


static const int B_WIDTH = 500;
static const int B_HEIGHT = 500;
static const int BRICKS_COLUMNS = 10;
static const int BRICKS_ROWS = 5;
static const int BALL_DIAMETER = 20;
static const int DELAY= 10;

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
    bool paddleCollision();

    int timerId;
    bool keyPressed;

    QGridLayout* grid;
    std::unique_ptr<Paddle> paddle;
    std::unique_ptr<Ball> ball;
    std::vector<std::unique_ptr<Brick>> bricks;
signals:

};

#endif // BREAKOUT_H
