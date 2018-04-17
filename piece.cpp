#include "piece.h"

Piece::Piece(QGraphicsItem *parent, Square *location)
    : QGraphicsObject(parent)
{
    this->location = location;
}

void Piece::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setBrush(QColor(64, 120, 250, 220));
    painter->drawEllipse(location->getX(), location->getY(), R, R);
}


QRectF Piece::boundingRect() const
{
    return QRectF(location->getX(), location->getY(), 2*R, 2*R);
}

