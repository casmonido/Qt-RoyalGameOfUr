#ifndef BOARD_H
#define BOARD_H
#include <QGraphicsItem>
#include <QPainter>

class Board: public QGraphicsObject
{
public:
    Board(QGraphicsItem *parent = 0);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;

private:
    QPixmap pixmap;
};

#endif // BOARD_H
