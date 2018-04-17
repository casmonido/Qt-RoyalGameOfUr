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
    int getX() const;
    int getY() const;
protected:
    int X, Y;
    Square(QGraphicsItem *parent = 0, int x=0, int y=0);
private:
    QPixmap pixmap;
};


class ZeroSquare : public Square
{
public:
    ZeroSquare(QGraphicsItem *parent = 0, int x=0, int y=0);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;

    int getX() const;
    int getY() const;
private:
    int pieceNumber = 0;
};

#endif // SQUARE_H
