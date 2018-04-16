#ifndef SQUARE_H
#define SQUARE_H
#include <QGraphicsItem>

class Square : public QGraphicsObject
{
public:
    Square(QGraphicsItem *parent = 0);

    QRectF boundingRect() const override;
    //void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
};

#endif // SQUARE_H
