#ifndef BALL_H
#define BALL_H

#include "bounce.h"
#include "velocity.h"
#include <QWidget>

class Ball : public QWidget
{
    Q_OBJECT

public:
    explicit Ball(QWidget *parent = nullptr, int diameter = 10, int x0 = 0, int y0 = 0);
    const QImage& getImage() const{ return ball_img; }
    QPoint getPosition() { return QPoint(x, y); }
    void move();
    void bounce(Bounce b) { bounceDir = b; }
    int getBottom() { return y + d;}
    int getTop() { return y; }

private:
    int d;
    QImage ball_img;
    int x;
    int y;
    Bounce bounceDir;
    Velocity vel;


signals:

};

#endif // BALL_H
