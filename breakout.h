#ifndef BREAKOUT_H
#define BREAKOUT_H

#include "paddle.h"
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>

class Breakout : public QWidget
{
    Q_OBJECT
public:
    explicit Breakout(QWidget *parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent* e) override;
    void timerEvent(QTimerEvent* e) override;

private:
    static const int B_WIDTH = 500;
    static const int B_HEIGHT = 500;
    int timerId;

    QGraphicsScene* scene;
    QGraphicsView* view;
    Paddle* paddle;
signals:

};

#endif // BREAKOUT_H
