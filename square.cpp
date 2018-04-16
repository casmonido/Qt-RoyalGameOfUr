#include "square.h"

Square::Square(QGraphicsItem *parent, QImage image, int x, int y)
    : QGraphicsObject(parent)
{
    this->pixmap = QPixmap::fromImage(image).scaled(WIDTH, WIDTH);
    X = x;
    Y = y;
}

QRectF Square::boundingRect() const
{
    return QRectF(X, Y, WIDTH, WIDTH); //left, top, width, height 600, 300
}

void Square::paint(QPainter *painter,
           const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(QPointF(X, Y), pixmap);
}
