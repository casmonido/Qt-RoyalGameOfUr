#include "piece.h"

Piece::Piece(QGraphicsItem *parent)
    : QGraphicsObject(parent)
{

}

QRectF Piece::boundingRect() const
{
    return QRectF(-15, -50, 30, 50); //left, top, width, height
}

