#ifndef WINDOW_H
#define WINDOW_H

#include "paddle.h"
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>

class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);

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

#endif // WINDOW_H
