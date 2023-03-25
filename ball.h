#ifndef BALL_H
#define BALL_H

#include <QWidget>
#include <QGraphicsEllipseItem>

static const int RADIUS = 20;

class Ball : public QWidget
{
    Q_OBJECT
    struct Direction
    {
        int dx;
        int dy;
    };

public:
    explicit Ball(QWidget *parent = nullptr, int x0 = 0, int y0 = 0);
    QGraphicsEllipseItem* getBall() {return ball;}
    void move();

private:
    int x_init;
    int y_init;
    QGraphicsEllipseItem* ball;


signals:

};

#endif // BALL_H
