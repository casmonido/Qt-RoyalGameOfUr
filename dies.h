#ifndef DIES_H
#define DIES_H
#include <QGraphicsItem>
#include <QPainter>
#include <QColor>
#include "square.h"

class Die : public QGraphicsObject
{
public:
    Die(QGraphicsItem *parent = 0);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
    unsigned int roll();
    void setToZero();
private:
    unsigned int rolledNumber = 0; //0 / 1
};

class DiesSet : public Die
{
public:
    static const int NUM_DIES = 4;
    DiesSet(QGraphicsItem *parent = 0);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
    unsigned int roll();
    void setToZero();
    unsigned int getSquaresToMoveAndReset();

private:
    Die *dies[NUM_DIES];
    unsigned int rolledNumber = 0;
};

#endif // DIES_H
