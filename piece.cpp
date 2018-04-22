#include "piece.h"

Piece::Piece(Game *parent, Square *location)
    : QGraphicsObject(parent)
{
    this->game = parent;
    this->location = location;
    this->location->tryAndOccupy(this);
    this->setPos(location->getChildCenterPos(this));
    animation  = new QPropertyAnimation(this, "pos");
    animation->setDuration(Game::ONE_MOVE_TIME);
    animation->setEasingCurve(QEasingCurve::BezierSpline);
}

void Piece::goBackToBeginning(PieceColors c) {
    if (c != this->getColor())
        return;
    location->leave(this);
    crossedPathLength = 0;
    location = game->destinationSquare(this, crossedPathLength, 0);
    location->tryAndOccupy(this);
    animation->setEndValue(location->getChildCenterPos(this));
    animation->start();
}

void PlayersPiece::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    if (!(e->buttons() & Qt::LeftButton))
        return;
    if (!wholePathCrossed && (game->getTurn() == PLAYERS_TURN) && game->getDiceRolled())
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
    location = game->destinationSquare(this, crossedPathLength, squaresToMove);
    location->tryAndOccupy(this);
    crossedPathLength += squaresToMove;
    animation->setEndValue(location->getChildCenterPos(this));
    animation->start();
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

PieceColors Piece::getColor() {
    return NONE;
}

QRectF Piece::boundingRect() const
{
    if (wholePathCrossed)
        return QRectF(0, 0, 0, 0);
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
