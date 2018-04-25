#include "piece.h"
#include "settingsmodel.h"

Piece::Piece(Game *parent, Square *location)
    : QGraphicsObject(parent)
{
    this->game = parent;
    this->location = location;
    this->location->tryAndOccupy(this);
    this->setPos(location->getChildCenterPos(this));
    animation  = new QPropertyAnimation(this, "pos");
    animation->setEasingCurve(QEasingCurve::BezierSpline);
    activeTimer = new QTimer(this);
    activeTimer->setSingleShot(true);
    connect(activeTimer, SIGNAL(timeout()), game, SLOT(setOtherPlayersTurn()));
    connect(animation, SIGNAL(finished()), this, SIGNAL(animationEnd()));
}

void Piece::goBackToBeginning(PieceColors c) {
    if ((c == NONE) || (c != this->getColor())) // if (c != this->getColor() return
        return;
    qobject_cast<BoardSquare*>(location)->leaveWhenEvicted(this);
    crossedPathLength = 0;
    location = game->destinationSquare(this, crossedPathLength, 0);
    location->tryAndOccupy(this);
    animation->setEndValue(location->getChildCenterPos(this));
    animation->setDuration(SettingsModel::MOVE_TIME);
    animation->start();
}

void Piece::move(unsigned int squaresToMove)
{
    int timeTillNextRound = 2*SettingsModel::MOVE_TIME;
    if (squaresToMove != 0) //jesli wylosowano 0 to gra sama zmienia rundę
    {
        location->leave(this);
        location = game->destinationSquare(this, crossedPathLength, squaresToMove);
        if (location->tryAndOccupy(this) == OK_CAPTURING)
            timeTillNextRound = 3*SettingsModel::MOVE_TIME;
        crossedPathLength += squaresToMove;
        animation->setDuration(SettingsModel::MOVE_TIME);
        animation->setEndValue(location->getChildCenterPos(this));
        animation->start();
        activeTimer->start(timeTillNextRound); // sygnał dla zmiany rundy
    }
}

void PlayersPiece::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    if (!(e->buttons() & Qt::LeftButton))
        return;
    if (!wholePathCrossed && (game->getTurn() == PLAYERS_TURN)  && !game->getPlayerMoved() && game->getDiceRolled())
    {
        game->setPlayerMoved();
        move(game->getRolledNumber());
    }
}







void PlayersPiece::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setBrush(SettingsModel::PLAYER_COLOR);
    painter->drawEllipse(boundingRect());
}

void OpponentsPiece::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setBrush(SettingsModel::OPPONENT_COLOR);
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

PieceColors OpponentsPiece::getColor() {
    return OPPONENTS;
}

OpponentsPiece::OpponentsPiece(Game *parent, Square *location)
    : Piece(parent, location) {
}

PieceColors PlayersPiece::getColor() {
    return PLAYERS;
}

PlayersPiece::PlayersPiece(Game *parent, Square *location)
    : Piece(parent, location) {
}
