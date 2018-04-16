#include "board.h"

Board::Board(QGraphicsItem *parent)
    : QGraphicsObject(parent)
{
    QImage image(":/RoyalGameofUr.jpg");
    this->pixmap = QPixmap::fromImage(image).scaled(400, 400);
}

QRectF Board::boundingRect() const
{
    return QRectF(-200, -200, 400, 400); //left, top, width, height
}

void Board::paint(QPainter *painter,
           const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    //painter->scale(.2272, .2824);
    painter->drawPixmap(QPointF(-15 * 4.4, -50 * 3.54), pixmap);
}
