#include "game.h"

Game::Game(QGraphicsItem *parent)
    : QGraphicsObject(parent)
{
    board = new Board(this);
    board->setPos(0, 0);
    for (int i = 0; i < NUM_PIECES; i++)
        pieces[i] = new Piece(this, board->getStartingSquare());
}

Game::~Game()
{
    delete board;
    for (int i = 0; i < NUM_PIECES; i++)
        delete pieces[i];
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
        pieces[i]->paint(painter, option, widget);
}
