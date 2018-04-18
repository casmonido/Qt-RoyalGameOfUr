#include "board.h"

Board::Board(QGraphicsItem *parent)
    : QGraphicsObject(parent)
{
    zeroGround = new ZeroSquare(this, X, Y - 100);

    squares[0] = new Square(this, QImage (":/square1.png"),
                                Square::WIDTH, Square::WIDTH);
    squares[1] = new Square(this, QImage (":/square1.png"),
                                2*Square::WIDTH, 0);
    squares[2] = new Square(this, QImage (":/square1.png"),
                                2*Square::WIDTH, 2*Square::WIDTH);
    squares[3] = new Square(this, QImage (":/square1.png"),
                                4*Square::WIDTH, 1*Square::WIDTH);
    squares[4] = new Square(this, QImage (":/square1.png"),
                                7*Square::WIDTH, 1*Square::WIDTH);

    squares[5] = new Square(this, QImage (":/square2.png"),
                                7*Square::WIDTH, 2*Square::WIDTH);
    squares[6] = new Square(this, QImage (":/square2.png"),
                                7*Square::WIDTH, 0);

    squares[7] = new Square(this, QImage (":/square3.png"),
                                0, Square::WIDTH);

    squares[8] = new Square(this, QImage (":/square4.png"),
                                0, 0);
    squares[9] = new Square(this, QImage (":/square4.png"),
                                0, 2*Square::WIDTH);
    squares[10] = new Square(this, QImage (":/square4.png"),
                                3*Square::WIDTH, Square::WIDTH);
    squares[11] = new Square(this, QImage (":/square4.png"),
                                6*Square::WIDTH, 0);
    squares[12] = new Square(this, QImage (":/square4.png"),
                                6*Square::WIDTH, 2*Square::WIDTH);

    squares[13] = new Square(this, QImage (":/square5.png"),
                                Square::WIDTH, 0);
    squares[14] = new Square(this, QImage (":/square5.png"),
                                Square::WIDTH, 2*Square::WIDTH);
    squares[15] = new Square(this, QImage (":/square5.png"),
                                3*Square::WIDTH, 0);
    squares[16] = new Square(this, QImage (":/square5.png"),
                                3*Square::WIDTH, 2*Square::WIDTH);
    squares[17] = new Square(this, QImage (":/square5.png"),
                                6*Square::WIDTH, Square::WIDTH);

    squares[18] = new Square(this, QImage (":/square6.png"),
                                2*Square::WIDTH, Square::WIDTH);
    squares[19] = new Square(this, QImage (":/square6.png"),
                                5*Square::WIDTH, Square::WIDTH);

    playersPath[0] = squares[15];
    playersPath[1] = squares[1];
    playersPath[2] = squares[13];
    playersPath[3] = squares[8];
    playersPath[4] = squares[7];
    playersPath[5] = squares[0];
    playersPath[6] = squares[18];
    playersPath[7] = squares[10];
    playersPath[8] = squares[3];
    playersPath[9] = squares[19];
    playersPath[10] = squares[17];
    playersPath[11] = squares[4];
    playersPath[12] = squares[6];
    playersPath[13] = squares[11];
}

Board *Board::getInstance(QGraphicsItem *parent) {
    if (!Board::instance)
        Board::instance = new Board(parent);
    return Board::instance;
}


Square *Board::nextSquare(PieceColors c, int crossedPathLength)
{
    if (c == WHITE)
        return playersPath[crossedPathLength];
    return zeroGround;
}

QRectF Board::boundingRect() const
{
    return QRectF(0, 0, XW, YW);
}

void Board::paint(QPainter *painter,
           const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

ZeroSquare *Board::getStartingSquare()
{
    return zeroGround;
}
