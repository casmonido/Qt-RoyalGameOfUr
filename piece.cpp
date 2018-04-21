#include "piece.h"

void PlayersPiece::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    if (!(e->buttons() & Qt::LeftButton))
        return;
    QPoint prevxy = location->getGameXY(this);
    location->leave(this);
    location = Board::getInstance()->nextSquare(getColor(), crossedPathLength);
    location->tryAndOccupy(this);
    QPoint xy = location->getGameXY(this);
    this->setTransform(QTransform::fromTranslate(xy.x() - prevxy.x(), xy.y() - prevxy.y()), true);
    update();
    crossedPathLength++;
}

//bool Piece::eventFilter(QObject* target, QEvent* e) {
//    if (target == this && e->type() == QEvent::MouseButtonPress)
//    {
//        QMouseEvent* me = static_cast<QMouseEvent*>(e);
//        qDebug() << "pozycja" << me->pos();
//        return false; // lub return false;
//    }
//    return QObject::eventFilter(target, e);
//}

void PlayersPiece::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setBrush(QColor(255, 250, 250, 255));
    painter->drawEllipse(-R/2, -R/2, R, R);
}

void OpponentsPiece::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setBrush(QColor(5, 5, 5, 255));
    painter->drawEllipse(-R/2, -R/2, R, R);
}


Piece::Piece(QGraphicsItem *parent, Square *location)
    : QGraphicsObject(parent)
{
    this->location = location;
    this->location->tryAndOccupy(this);
    this->setPos(location->getGameXY(this));
    //this->installEventFilter(this);
}

PieceColors Piece::getColor() {
    return PLAYERS;
}

QRectF Piece::boundingRect() const
{
    return QRectF(-R/2, -R/2, R, R);
}

PieceColors OpponentsPiece::getColor()
{
    return OPPONENTS;
}

OpponentsPiece::OpponentsPiece(QGraphicsItem *parent, Square *location)
    : Piece(parent, location)
{
}

PieceColors PlayersPiece::getColor()
{
    return PLAYERS;
}

PlayersPiece::PlayersPiece(QGraphicsItem *parent, Square *location)
    : Piece(parent, location)
{
}
