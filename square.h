#ifndef SQUARE_H
#define SQUARE_H
#include <QGraphicsItem>
#include <QPainter>

class Square : public QGraphicsObject
{
public:
    static const int WIDTH =100;
    Square(QGraphicsItem *parent = 0, QImage image = QImage (":/square1.png"), int x=0, int y=0);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
private:
    QPixmap pixmap;
    int X, Y;
};

#endif // SQUARE_H
