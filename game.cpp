#include "game.h"

Game::Game(QGraphicsItem *parent)
    : QGraphicsObject(parent)
{
    Board *board = Board::getInstance(this);
    board->setPos(0, 0);
    for (int i = 0; i < NUM_PIECES; i++)
        playersPieces[i] = new PlayersPiece(this, board->getStartingSquare(WHITE));
    for (int i = 0; i < NUM_PIECES; i++)
        opponentsPieces[i] = new OpponentsPiece(this, board->getStartingSquare(BLACK));
    dies = new Dies(this);
    dies->setPos( 8*Square::WIDTH, 4*Square::WIDTH);
}

QRectF Game::boundingRect() const
{
    return Board::getInstance()->boundingRect();
}

void Game::paint(QPainter *painter,
           const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
