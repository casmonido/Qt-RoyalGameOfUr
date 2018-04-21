#include "piece.h"

void PlayersPiece::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    if (!(e->buttons() & Qt::LeftButton))
        return;
    //QPoint prevxy = location->getGameXY(this);
    location->leave(this);
    location = Board::getInstance()->nextSquare(getColor(), crossedPathLength);
    location->tryAndOccupy(this);
    QPoint xy = location->getGameXY(this);
    //this->setTransform(QTransform::fromTranslate(xy.x() - prevxy.x(), xy.y() - prevxy.y()), true);
    this->setPos(xy);
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
    painter->drawEllipse(-0.5*R, -0.5*R, R, R);
}

void OpponentsPiece::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setBrush(QColor(5, 5, 5, 255));
    painter->drawEllipse(-0.5*R, -0.5*R, R, R);
}


Piece::Piece(QGraphicsItem *parent, Square *location)
    : QGraphicsObject(parent)
{
    this->location = location;
    this->location->tryAndOccupy(this);
    //this->setParent(location);
    this->setPos(location->getGameXY(this));
    //this->installEventFilter(this);
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
