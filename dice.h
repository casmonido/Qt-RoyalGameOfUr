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
    Q_OBJECT
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
    Q_OBJECT
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
    QColor buttonColor = Qt::green;
private slots:
    void diceRolledChanged(bool);
};

#endif // DIES_H
