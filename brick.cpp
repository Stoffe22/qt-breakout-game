#include "brick.h"
#include <QPixmap>

Brick::Brick(int width, int height, int x0, int y0)
    : w(width), h(height), x(x0), y(y0)
{
    QRect rect(x, y, w, h);
    x = rect.topLeft().x();
    y = rect.topLeft().y();
    QPixmap pixmap(rect.size());
    pixmap.fill(Qt::red);
    brick_img = pixmap.toImage();
}
