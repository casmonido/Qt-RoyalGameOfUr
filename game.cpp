#include "game.h"

Game::Game(QGraphicsItem *parent)
    : QGraphicsObject(parent)
{
    board = Board::getInstance(this);
    board->setPos(0, 0);
    for (int i = 0; i < NUM_PIECES; i++)
        playersPieces[i] = new PlayersPiece(this, board->getStartingSquare());
    for (int i = 0; i < NUM_PIECES; i++)
        opponentsPieces[i] = new OpponentsPiece(this, board->getStartingSquare());
}

Game::~Game()
{
    delete board;
    for (int i = 0; i < NUM_PIECES; i++)
        delete opponentsPieces[i];
    for (int i = 0; i < NUM_PIECES; i++)
        delete playersPieces[i];
}

QRectF Game::boundingRect() const
{
    return board->boundingRect();
}

void Game::paint(QPainter *painter,
           const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    for (int i = 0; i < NUM_PIECES; i++)
        opponentsPieces[i]->paint(painter, option, widget);
    for (int i = 0; i < NUM_PIECES; i++)
        playersPieces[i]->paint(painter, option, widget);
}
