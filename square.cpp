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

int Square::getX() const {
    return X;
}

int Square::getY() const {
    return Y;
}

/*int ZeroSquare::getX() const {
    return X + pieceNumber*Square::WIDTH;
}

int ZeroSquare::getY() const {
    return Y;
}

ZeroSquare::ZeroSquare(QGraphicsItem *parent, int x, int y)
    : Square(parent, null, x, y)
{
}

QRectF ZeroSquare::boundingRect() const
{
    return QRectF(X, Y, WIDTH * pieceNumber, WIDTH); //left, top, width, height 600, 300
}

void ZeroSquare::paint(QPainter *painter,
           const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
}*/
