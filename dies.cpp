#include "dies.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Die::Die(QGraphicsItem *parent)
    : QGraphicsObject(parent)
{
    rolledNumber = 0;
}

QRectF Die::boundingRect() const {
    return QRectF(-0.5*BoardSquare::WIDTH, -0.5*BoardSquare::WIDTH,
                  BoardSquare::WIDTH, BoardSquare::WIDTH);
}

void Die::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QRectF rect = QRectF(-0.25*BoardSquare::WIDTH, -0.25*BoardSquare::WIDTH,
                         0.5*BoardSquare::WIDTH, 0.5*BoardSquare::WIDTH);
    QPainterPath path;
    path.moveTo(rect.left() + (rect.width() / 2), rect.top());
    path.lineTo(rect.bottomLeft());
    path.lineTo(rect.bottomRight());
    path.lineTo(rect.left() + (rect.width() / 2), rect.top());
    painter->fillPath(path, QBrush(Qt::white));
    if (rolledNumber > 0)
    {
        painter->setBrush(Qt::black);
        painter->drawEllipse(-1, -1, 2, 2);
    }
}

DiesSet::DiesSet(QGraphicsItem *parent)
    : Die(parent)
{
    srand (time(NULL));
    for (int i = 0; i < NUM_DIES; ++i)
        dies[i] = new Die(this);
}

QRectF DiesSet::boundingRect() const {
    return QRectF(-3*BoardSquare::WIDTH, -4*BoardSquare::WIDTH, 6*BoardSquare::WIDTH, 8*BoardSquare::WIDTH);
}

void DiesSet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setBrush(Qt::gray);
    painter->drawRect(boundingRect());
    painter->setBrush(QColor(5, 5, 5, 255));
    std::string s = std::to_string(rolledNumber);
    char const *num = s.c_str();
    painter->setFont(QFont("Arial", 30));
    painter->drawText(QPointF(0, 0), num);
}

int Die::roll() {
    rolledNumber = rand() % 2;
    update();
    return rolledNumber;
}

int DiesSet::roll() {
    rolledNumber = 0;
    for (int i = 0; i < NUM_DIES; ++i)
        rolledNumber += dies[i]->roll();
    update(); //moze lepiej event na rolledNumber?
    return rolledNumber;
}

void Die::setToZero() {
    rolledNumber = 0;
}

void DiesSet::setToZero() {
    for (int i = 0; i < NUM_DIES; ++i)
        dies[i]->setToZero();
}
