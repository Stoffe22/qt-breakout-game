#ifndef BRICK_H
#define BRICK_H

#include <QImage>
#include <QWidget>

class Brick : public QWidget
{
    // Top left corner
    int x;
    int y;

    int w;
    int h;

    QImage brick_img;
public:
    Brick(int w, int h, int x0, int y0);
    const QImage& getImage() const { return brick_img; }
    QPoint getPosition() { return QPoint(x, y); }
    int getLeft() { return x; }
    int getRight() { return x + w; }
    int getTop() { return y; }
    int getBottom() { return y + h; }
};

#endif // BRICK_H
