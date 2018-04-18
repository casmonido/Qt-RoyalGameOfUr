#include "piece.h"

void PlayersPiece::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    if (!(e->buttons() & Qt::LeftButton))
        return;
    location->leave();
    int prevX = x;
    int prevY= y;
    location = Board::getInstance()->nextSquare(getColor(), crossedPathLength);
    x = location->getX();
    y = location->getY();
    this->setTransform(QTransform::fromTranslate(5, -5), true);
    update();
    crossedPathLength++;
}

bool Piece::eventFilter(QObject* target, QEvent* e) {
    if (target == this && e->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent* me = static_cast<QMouseEvent*>(e);
        qDebug() << "pozycja" << me->pos();
        return false; // lub return false;
    }
    return QObject::eventFilter(target, e);
}

void PlayersPiece::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setBrush(QColor(255, 250, 250, 255));
    painter->drawEllipse(0, 0, R, R);
}

void OpponentsPiece::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setBrush(QColor(5, 5, 5, 255));
    painter->drawEllipse(0, 0, R, R);
}


Piece::Piece(QGraphicsItem *parent, Square *location)
    : QGraphicsObject(parent)
{
    this->location = location;
    this->location->tryAndOccupy(getColor());
    x = this->location->getX();
    y = this->location->getY();
    this->setPos(x, y);
    this->installEventFilter(this);
}

PieceColors Piece::getColor() {
    return WHITE;
}

QRectF Piece::boundingRect() const
{
    return QRectF(0, 0, R, R);
}

PieceColors OpponentsPiece::getColor()
{
    return BLACK;
}

OpponentsPiece::OpponentsPiece(QGraphicsItem *parent, Square *location)
    : Piece(parent, location)
{
}

PieceColors PlayersPiece::getColor()
{
    return WHITE;
}

PlayersPiece::PlayersPiece(QGraphicsItem *parent, Square *location)
    : Piece(parent, location)
{
}
