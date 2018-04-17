#ifndef BOARD_H
#define BOARD_H
#include <QGraphicsItem>
#include <QPainter>
#include <QColor>
#include "square.h"

class Board: public QGraphicsObject
{
public:
    Board(QGraphicsItem *parent = 0);
    ~Board();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;

private:
    QPixmap pixmap;
    Square *squares [20];
    Square *zeroGround;
    static const int X = -300, Y = -100, XW = 600, YW = 300;
};

#endif // BOARD_H
