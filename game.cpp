#include "game.h"

Game::Game(QGraphicsItem *parent)
    : QGraphicsObject(parent)
{
    Board *board = Board::getInstance(this);
    board->setPos(-3*BoardSquare::WIDTH, 0*BoardSquare::WIDTH);
    for (int i = 0; i < NUM_PIECES; i++)
        playersPieces[i] = new PlayersPiece(this, board->getStartingSquare(PLAYERS));
    for (int i = 0; i < NUM_PIECES; i++)
        opponentsPieces[i] = new OpponentsPiece(this, board->getStartingSquare(OPPONENTS));
    dies = new Dies(this);
    dies->setPos(5*BoardSquare::WIDTH, 0*BoardSquare::WIDTH);
}

QRectF Game::boundingRect() const
{
    return QRectF();
}

void Game::paint(QPainter *painter,
           const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    Q_UNUSED(painter);
}
