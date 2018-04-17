#include "piece.h"

Piece::Piece(QGraphicsItem *parent, Square *location)
    : QGraphicsObject(parent)
{
    this->location = location;
    this->location->tryAndOccupy(this);
    x = this->location->getX();
    y = this->location->getY();
}

PieceColors Piece::getColor() {
    return WHITE;
}

void Piece::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setBrush(QColor(64, 120, 250, 220));
    painter->drawEllipse(x, y, R, R);
}


QRectF Piece::boundingRect() const
{
    return QRectF(x, y, 2*R, 2*R);
}

