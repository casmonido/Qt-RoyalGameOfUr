#include "square.h"

Square::Square(QGraphicsItem *parent)
    : QGraphicsObject(parent)
{

}

QRectF Square::boundingRect() const
{
    return QRectF(-15, -50, 30, 50); //left, top, width, height
}
