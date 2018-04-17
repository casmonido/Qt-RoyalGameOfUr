#include "square.h"

Square::Square(QGraphicsItem *parent, QImage image, int x, int y)
    : QGraphicsObject(parent)
{
    this->pixmap = QPixmap::fromImage(image).scaled(WIDTH, WIDTH);
    X = x;
    Y = y;
}

Square::Square(QGraphicsItem *parent, int x, int y)
    : QGraphicsObject(parent)
{
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

OccupySquareResults Square::tryAndOccupy(PieceColors c) {
    if (this->color != NONE && this->color != c)
    {
        // emit event
        // .leave() performed by pieces
    }
    this->piecesNum++;
    this->color = c;
    return OK;
}

void Square::leave() {
    this->piecesNum--;
    if (this->piecesNum == 0)
        this->color = NONE;
}

ZeroSquare::ZeroSquare(QGraphicsItem *parent, int x, int y)
    : Square(parent, x, y)
{
}

int ZeroSquare::getX() const {
    return X + piecesNum*Square::WIDTH;
}

int ZeroSquare::getY() const {
    return Y;
}

QRectF ZeroSquare::boundingRect() const
{
    return QRectF(X, Y, WIDTH * piecesNum, WIDTH); //left, top, width, height 600, 300
}

void ZeroSquare::paint(QPainter *painter,
           const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

OccupySquareResults ZeroSquare::tryAndOccupy(PieceColors c) {
    this->piecesNum++;
    return OK;
}

void ZeroSquare::leave() {
    this->piecesNum--;
}
