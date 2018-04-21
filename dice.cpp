#include "dice.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Die::Die(QGraphicsItem *parent, QPointF pos)
    : QGraphicsObject(parent)
{
    this->setPos(pos);
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
        painter->drawEllipse(-2, -2+(0.1*BoardSquare::WIDTH), 4, 4);
    }
}

Dice::Dice(Game *parent, QPointF pos)
    : Die(parent, pos)
{
    srand (time(NULL));
    game = parent;
    for (int i = 0; i < NUM_DIES; ++i)
        dies[i] = new Die(this, QPointF((i-1.5)*BoardSquare::WIDTH, -0.5*BoardSquare::WIDTH));
}

QRectF Dice::boundingRect() const {
    return QRectF(-2*BoardSquare::WIDTH, -1*BoardSquare::WIDTH, 4*BoardSquare::WIDTH, 2*BoardSquare::WIDTH);
}

void Dice::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setBrush(buttonColor);
    painter->drawRect(boundingRect());
    painter->setBrush(QColor(5, 5, 5, 255));
    painter->setFont(QFont("Arial", 40));
    painter->drawText(QRectF(-2*BoardSquare::WIDTH, 0*BoardSquare::WIDTH,
                             4*BoardSquare::WIDTH, BoardSquare::WIDTH),
                      Qt::AlignCenter, "ROLL");
}

void Dice::diceRolledChanged(bool b)
{
    if (b)
        buttonColor = Qt::gray;
    else
        buttonColor = Qt::green;
    update();
}

unsigned int Die::roll() {
    rolledNumber = rand() % 2;
    update();
    return rolledNumber;
}

unsigned int Dice::roll() {
    rolledNumber = 0;
    for (int i = 0; i < NUM_DIES; ++i)
        rolledNumber += dies[i]->roll();
    update(); //moze lepiej event na rolledNumber?
    return rolledNumber;
}

void Die::setToZero() {
    rolledNumber = 0;
}

void Dice::setToZero() {
    for (int i = 0; i < NUM_DIES; ++i)
        dies[i]->setToZero();
}

unsigned int Dice::getSquaresToMoveAndReset() {
    unsigned int tmp = rolledNumber;
    setToZero();
    return tmp;
}

void Dice::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    if (!(e->buttons() & Qt::LeftButton))
        return;
    if (!game->getDiceRolled())
    {
        roll();
        game->setDiceRolled();
    }
}
