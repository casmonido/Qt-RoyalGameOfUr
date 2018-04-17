#include "board.h"

Board::Board(QGraphicsItem *parent)
    : QGraphicsObject(parent)
{
    zeroGround = new Square(this, QImage (":/square1.png"),
                            X+Square::WIDTH, Y+Square::WIDTH);//(this, X - 100, y - 100);
    squares[0] = new Square(this, QImage (":/square1.png"),
                                X+Square::WIDTH, Y+Square::WIDTH);
    squares[1] = new Square(this, QImage (":/square1.png"),
                                X+2*Square::WIDTH, Y);
    squares[2] = new Square(this, QImage (":/square1.png"),
                                X+2*Square::WIDTH, Y+2*Square::WIDTH);
    squares[3] = new Square(this, QImage (":/square1.png"),
                                X+4*Square::WIDTH, Y+1*Square::WIDTH);
    squares[4] = new Square(this, QImage (":/square1.png"),
                                X+7*Square::WIDTH, Y+1*Square::WIDTH);

    squares[5] = new Square(this, QImage (":/square2.png"),
                                X+7*Square::WIDTH, Y+2*Square::WIDTH);
    squares[6] = new Square(this, QImage (":/square2.png"),
                                X+7*Square::WIDTH, Y);

    squares[7] = new Square(this, QImage (":/square3.png"),
                                X, Y+Square::WIDTH);

    squares[8] = new Square(this, QImage (":/square4.png"),
                                X, Y);
    squares[9] = new Square(this, QImage (":/square4.png"),
                                X, Y+2*Square::WIDTH);
    squares[10] = new Square(this, QImage (":/square4.png"),
                                X+3*Square::WIDTH, Y+Square::WIDTH);
    squares[11] = new Square(this, QImage (":/square4.png"),
                                X+6*Square::WIDTH, Y);
    squares[12] = new Square(this, QImage (":/square4.png"),
                                X+6*Square::WIDTH, Y+2*Square::WIDTH);

    squares[13] = new Square(this, QImage (":/square5.png"),
                                X+Square::WIDTH, Y);
    squares[14] = new Square(this, QImage (":/square5.png"),
                                X+Square::WIDTH, Y+2*Square::WIDTH);
    squares[15] = new Square(this, QImage (":/square5.png"),
                                X+3*Square::WIDTH, Y);
    squares[16] = new Square(this, QImage (":/square5.png"),
                                X+3*Square::WIDTH, Y+2*Square::WIDTH);
    squares[17] = new Square(this, QImage (":/square5.png"),
                                X+6*Square::WIDTH, Y+Square::WIDTH);

    squares[18] = new Square(this, QImage (":/square6.png"),
                                X+2*Square::WIDTH, Y+Square::WIDTH);
    squares[19] = new Square(this, QImage (":/square6.png"),
                                X+5*Square::WIDTH, Y+Square::WIDTH);

}

QRectF Board::boundingRect() const
{
    return QRectF(X, Y, XW, YW);
}

Board::~Board()
{
    delete zeroGround;
    for (int i = 0; i < 20; i++)
        delete squares[i];
}

void Board::paint(QPainter *painter,
           const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    for (int i = 0; i < 20; i++)
        squares[i]->paint(painter, option, widget);
}
