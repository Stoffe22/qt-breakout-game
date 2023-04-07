#ifndef BREAKOUT_H
#define BREAKOUT_H

#include "paddle.h"
#include "ball.h"
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>

static const int B_WIDTH = 500;
static const int B_HEIGHT = 500;
static const int BALL_DIAMETER = 20;
static const int DELAY= 20;

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
    Paddle* paddle;
    Ball* ball;

signals:

};

#endif // BREAKOUT_H
