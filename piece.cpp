#include "piece.h"

void PlayersPiece::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    if (!(e->buttons() & Qt::LeftButton))
        return;
    if (game->getTurn() == PLAYERS_TURN && game->getDiceRolled())
    {
        move(game->getSquaresToMove());
        game->setOtherPlayersTurn();
    }
}

void Piece::move(unsigned int squaresToMove)
{
    if (squaresToMove == 0)
        return;
    location->leave(this);
    location = game->nextSquare(getColor(), crossedPathLength);
    location->tryAndOccupy(this);
    this->setParentItem(location);
    this->setPos(location->getChildCenterPos(this));
    update();
    crossedPathLength++;
}

void PlayersPiece::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setBrush(QColor(255, 250, 250, 255));
    painter->drawEllipse(boundingRect());
}

void OpponentsPiece::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setBrush(QColor(5, 5, 5, 255));
    painter->drawEllipse(boundingRect());
}


Piece::Piece(Game *parent, Square *location)
    : QGraphicsObject(parent)
{
    this->game = parent;
    this->location = location;
    this->location->tryAndOccupy(this);
    this->setParentItem(location);
    this->setPos(location->getChildCenterPos(this));
}

PieceColors Piece::getColor() {
    return PLAYERS;
}

QRectF Piece::boundingRect() const
{
    return QRectF(-0.5*R, -0.5*R, R, R);
}

PieceColors OpponentsPiece::getColor()
{
    return OPPONENTS;
}

OpponentsPiece::OpponentsPiece(Game *parent, Square *location)
    : Piece(parent, location)
{
}

PieceColors PlayersPiece::getColor()
{
    return PLAYERS;
}

PlayersPiece::PlayersPiece(Game *parent, Square *location)
    : Piece(parent, location)
{
}
