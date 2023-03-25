#ifndef BREAKOUT_H
#define BREAKOUT_H

#include "paddle.h"
#include "ball.h"
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>

static const int B_WIDTH = 1000;
static const int B_HEIGHT = 1000;

class Breakout : public QWidget
{
    Q_OBJECT
public:
    explicit Breakout(QWidget *parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent* e) override;
    void timerEvent(QTimerEvent* e) override;

private:
    int timerId;
    bool keyPressed;

    QGraphicsScene* scene;
    QGraphicsView* view;
    Paddle* paddle;
    Ball* ball;
    void updateScene();
signals:

};

#endif // BREAKOUT_H
