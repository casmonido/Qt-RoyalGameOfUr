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
    int roll();
    void setToZero();
private:
    int rolledNumber = 0; //0 / 1
};

class DiesSet : public Die
{
public:
    static const int NUM_DIES = 4;
    DiesSet(QGraphicsItem *parent = 0);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
    int roll();
    void setToZero();
    int getSquaresToMove() const {return rolledNumber;}

private:
    Die *dies[NUM_DIES];
    int rolledNumber = 0;
};

#endif // DIES_H
