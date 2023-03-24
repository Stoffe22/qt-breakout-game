#include "breakout.h"

Breakout::Breakout(QWidget *parent)
    : QWidget{parent},
      scene(new QGraphicsScene(this)),
      view(new QGraphicsView(scene, this)),
      paddle(new Paddle{this, B_WIDTH, B_HEIGHT})
{
    view->setFixedSize(B_WIDTH, B_HEIGHT);
    QGraphicsRectItem* rectItem = scene->addRect(paddle->getRect(), QPen(Qt::black), QBrush(Qt::red));
    timerId = startTimer(10);
}

void Breakout::keyPressEvent(QKeyEvent* e)
{

}

void Breakout::timerEvent(QTimerEvent* e)
{
    //paddle->getRect().moveTo(paddle->Get)
    scene->update();
}
