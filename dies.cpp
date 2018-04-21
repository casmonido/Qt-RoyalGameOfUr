#include "dies.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Die::Die(QGraphicsItem *parent)
    : QGraphicsObject(parent)
{
    srand (time(NULL));
    rolledNumber = 0;
}

DiesSet::DiesSet(QGraphicsItem *parent)
    : Die(parent)
{
}

QRectF Die::boundingRect() const {
    return QRectF(0, 0, BoardSquare::WIDTH, BoardSquare::WIDTH);
}

void Die::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(Qt::white);
    //painter->setBrush(QColor(50, 50, 50, 255));
    painter->drawEllipse(QPoint(0, 0), BoardSquare::WIDTH, BoardSquare::WIDTH);
}

QRectF DiesSet::boundingRect() const {
    return QRectF(0, 0, BoardSquare::WIDTH, BoardSquare::WIDTH);
}

void DiesSet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setBrush(QColor(5, 5, 5, 255));
    std::string s = std::to_string(rolledNumber);
    char const *num = s.c_str();
    painter->setFont(QFont("Arial", 30));
    painter->drawText(QPointF(0, 0), num);
}

int Die::roll() {
    return rolledNumber;
}

int DiesSet::roll() {
    return rolledNumber;
}
