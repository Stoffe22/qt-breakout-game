#ifndef BRICK_H
#define BRICK_H

#include <QImage>
#include <QWidget>

static const int BRICK_WIDTH = 50;
static const int BRICK_HEIGHT = 20;

class Brick : public QWidget
{
    // Top left corner
    int x;
    int y;

    QImage brick_img;
public:
    Brick(int x0, int y0);
    const QImage& getImage() const { return brick_img; }
    QPoint getPosition() { return QPoint(x, y); }
};

#endif // BRICK_H
