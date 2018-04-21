#include "board.h"

Board::Board(QGraphicsItem *parent)
    : QGraphicsObject(parent)
{
    playersZeroGround = new ZeroSquare(this, 0*BoardSquare::WIDTH, -2*BoardSquare::WIDTH);
    opponentsZeroGround = new ZeroSquare(this, 0*BoardSquare::WIDTH, 2*BoardSquare::WIDTH);

    squares[0] = new BoardSquare(this, QImage (":/square1.png"),
                                -1.5*BoardSquare::WIDTH, -1*BoardSquare::WIDTH);
    squares[1] = new BoardSquare(this, QImage (":/square1.png"),
                                -2.5*BoardSquare::WIDTH, 0*BoardSquare::WIDTH);
    squares[2] = new BoardSquare(this, QImage (":/square1.png"),
                                0.5*BoardSquare::WIDTH, 0*BoardSquare::WIDTH);
    squares[3] = new BoardSquare(this, QImage (":/square1.png"),
                                3.5*BoardSquare::WIDTH, 0*BoardSquare::WIDTH);
    squares[4] = new BoardSquare(this, QImage (":/square1.png"),
                                -1.5*BoardSquare::WIDTH, 1*BoardSquare::WIDTH);

    squares[5] = new BoardSquare(this, QImage (":/square2.png"),
                                3.5*BoardSquare::WIDTH, -1*BoardSquare::WIDTH);
    squares[6] = new BoardSquare(this, QImage (":/square2.png"),
                                3.5*BoardSquare::WIDTH, 1*BoardSquare::WIDTH);

    squares[7] = new BoardSquare(this, QImage (":/square3.png"),
                                -3.5*BoardSquare::WIDTH, 0*BoardSquare::WIDTH);

    squares[8] = new BoardSquare(this, QImage (":/square4.png"),
                                -0.5*BoardSquare::WIDTH, 0*BoardSquare::WIDTH);
    squares[9] = new BoardSquare(this, QImage (":/square4.png"),
                                -3.5*BoardSquare::WIDTH, -1*BoardSquare::WIDTH);
    squares[10] = new BoardSquare(this, QImage (":/square4.png"),
                                -3.5*BoardSquare::WIDTH, 1*BoardSquare::WIDTH);
    squares[11] = new BoardSquare(this, QImage (":/square4.png"),
                                2.5*BoardSquare::WIDTH, -1*BoardSquare::WIDTH);
    squares[12] = new BoardSquare(this, QImage (":/square4.png"),
                                2.5*BoardSquare::WIDTH, 1*BoardSquare::WIDTH);

    squares[13] = new BoardSquare(this, QImage (":/square5.png"),
                                -0.5*BoardSquare::WIDTH, -1*BoardSquare::WIDTH);
    squares[14] = new BoardSquare(this, QImage (":/square5.png"),
                                -0.5*BoardSquare::WIDTH, 1*BoardSquare::WIDTH);
    squares[15] = new BoardSquare(this, QImage (":/square5.png"),
                                -2.5*BoardSquare::WIDTH, -1*BoardSquare::WIDTH);
    squares[16] = new BoardSquare(this, QImage (":/square5.png"),
                                -2.5*BoardSquare::WIDTH, 1*BoardSquare::WIDTH);
    squares[17] = new BoardSquare(this, QImage (":/square5.png"),
                                2.5*BoardSquare::WIDTH, 0*BoardSquare::WIDTH);

    squares[18] = new BoardSquare(this, QImage (":/square6.png"),
                                -1.5*BoardSquare::WIDTH, 0*BoardSquare::WIDTH);
    squares[19] = new BoardSquare(this, QImage (":/square6.png"),
                                1.5*BoardSquare::WIDTH, 0*BoardSquare::WIDTH);

    playersPath[0] = squares[13];
    playersPath[1] = squares[0];
    playersPath[2] = squares[15];
    playersPath[3] = squares[9];
    playersPath[4] = squares[7];
    playersPath[5] = squares[1];
    playersPath[6] = squares[18];
    playersPath[7] = squares[8];
    playersPath[8] = squares[2];
    playersPath[9] = squares[19];
    playersPath[10] = squares[17];
    playersPath[11] = squares[3];
    playersPath[12] = squares[5];
    playersPath[13] = squares[11];

    opponentsPath[0] = squares[14];
    opponentsPath[1] = squares[4];
    opponentsPath[2] = squares[16];
    opponentsPath[3] = squares[10];
    opponentsPath[4] = squares[7];
    opponentsPath[5] = squares[1];
    opponentsPath[6] = squares[18];
    opponentsPath[7] = squares[8];
    opponentsPath[8] = squares[2];
    opponentsPath[9] = squares[19];
    opponentsPath[10] = squares[17];
    opponentsPath[11] = squares[3];
    opponentsPath[12] = squares[6];
    opponentsPath[13] = squares[12];
}

Square *Board::nextSquare(PieceColors c, int crossedPathLength)
{
    if (crossedPathLength >= PATH_LEN)
    {
        return getStartingSquare(c); //tak naprawdę powinien istnieć jakiś końcowy wspólny?
        // emituj event że square skończył podróż i nie powinien się odrysowywać
    }
    if (c == PLAYERS)
        return playersPath[crossedPathLength];
    if (c = OPPONENTS)
        return opponentsPath[crossedPathLength];
    return getStartingSquare(c);
}

QRectF Board::boundingRect() const
{
    return QRectF(-4*BoardSquare::WIDTH, -3*BoardSquare::WIDTH,
                  8*BoardSquare::WIDTH, 6*BoardSquare::WIDTH);
}

void Board::paint(QPainter *painter,
           const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    //Q_UNUSED(painter);
    painter->setBrush(QColor(235, 185, 185, 255));
    painter->drawRect(boundingRect());
}

ZeroSquare *Board::getStartingSquare(PieceColors c)
{
    if (c == PLAYERS)
        return playersZeroGround;
    return opponentsZeroGround;
}
