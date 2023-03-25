#include "breakout.h"
#include <QKeyEvent>

Breakout::Breakout(QWidget *parent)
    : QWidget{parent},
      scene(new QGraphicsScene{this}),
      view(new QGraphicsView{scene, this}),
      paddle(new Paddle{this, B_WIDTH, B_HEIGHT}),
      ball(new Ball{this, B_WIDTH/2, B_HEIGHT/2})
{
    view->setFixedSize(B_WIDTH, B_HEIGHT);
    setFocusPolicy(Qt::StrongFocus);
    setFocus();
    scene->addRect(paddle->getRect(), QPen(Qt::white), QBrush(Qt::white));
    scene->addItem(ball->getBall());
    scene->setSceneRect(0, 0, B_WIDTH, B_HEIGHT);
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

void Breakout::timerEvent(QTimerEvent* e)
{
    if (keyPressed)
        paddle->move();
    //ball->move();
    updateScene();
    keyPressed = false;

}

void Breakout::updateScene()
{
    scene->setSceneRect(paddle->getRect());
    //scene->addItem(ball->getBall());
    scene->update();
}

