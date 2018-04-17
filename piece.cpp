#include "piece.h"


void PlayersPiece::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setBrush(QColor(255, 250, 250, 255));
    painter->drawEllipse(x, y, R, R);
}

void OpponentsPiece::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setBrush(QColor(5, 5, 5, 255));
    painter->drawEllipse(x, y, R, R);
}


Piece::Piece(QGraphicsItem *parent, Square *location)
    : QGraphicsObject(parent)
{
    this->location = location;
    this->location->tryAndOccupy(getColor());
    x = this->location->getX();
    y = this->location->getY();
}

PieceColors Piece::getColor() {
    return WHITE;
}

QRectF Piece::boundingRect() const
{
    return QRectF(x, y, 2*R, 2*R);
}

PieceColors OpponentsPiece::getColor()
{
    return BLACK;
}

OpponentsPiece::OpponentsPiece(QGraphicsItem *parent, Square *location)
    : Piece(parent, location)
{
}

PieceColors PlayersPiece::getColor()
{
    return WHITE;
}

PlayersPiece::PlayersPiece(QGraphicsItem *parent, Square *location)
    : Piece(parent, location)
{
}
