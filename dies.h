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
private:
    int rolledNumber = 0; //0 / 1
    int roll();
};

class Dies : public Die
{
public:
    Dies(QGraphicsItem *parent = 0);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
private:
    int rolledNumber = 0;
    int roll();
};

#endif // DIES_H
