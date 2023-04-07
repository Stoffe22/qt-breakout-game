#include "brick.h"
#include <QPixmap>

Brick::Brick(int x0, int y0)
    : x(x0), y(y0)
{
    QRect rect(x, y, BRICK_WIDTH, BRICK_HEIGHT);
    x = rect.topLeft().x();
    y = rect.topLeft().y();
    QPixmap pixmap(rect.size());
    pixmap.fill(Qt::red);
    brick_img = pixmap.toImage();
}
