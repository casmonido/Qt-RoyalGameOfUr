#ifndef DIES_H
#define DIES_H
#include <QGraphicsItem>
#include <QPainter>
#include <QColor>
#include "square.h"
#include "game.h"
class Game;

class Die : public QGraphicsObject
{
public:
    Die(QGraphicsItem *parent = 0, QPointF pos = QPointF(0, 0));
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
    unsigned int roll();
    void setToZero();
private:
    unsigned int rolledNumber = 0;
};

class Dice : public Die
{
public:
    static const int NUM_DIES = 4;
    Dice(Game *parent = 0, QPointF pos = QPointF(0, 0));
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
    unsigned int roll();
    void setToZero();
    unsigned int getSquaresToMoveAndReset();
    void mousePressEvent(QGraphicsSceneMouseEvent *e);

private:
    Die *dies[NUM_DIES];
    Game *game;
    unsigned int rolledNumber = 0;
};

#endif // DIES_H
