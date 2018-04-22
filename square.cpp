#include "square.h"

BoardSquare::BoardSquare(QGraphicsItem *parent, QImage image, int x, int y)
    : Square(parent)
{
    this->pixmap = QPixmap::fromImage(image).scaled(WIDTH, WIDTH);
    this->setPos(x, y);
}

QRectF BoardSquare::boundingRect() const
{
    return QRectF(-0.5*WIDTH, -0.5*WIDTH, WIDTH, WIDTH);
}

void BoardSquare::paint(QPainter *painter,
           const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(QPointF(-0.5*WIDTH, -0.5*WIDTH), pixmap);
}

QPointF BoardSquare::getChildCenterPos(Piece *p) const {
    Q_UNUSED(p);
    QPointF qp = QPointF(-3*piecesNum, -3*piecesNum);
    return this->mapToItem(this->parentItem()->parentItem(), qp);
}

OccupySquareResults BoardSquare::tryAndOccupy(Piece *p) {
    if (this->color != NONE && this->color != p->getColor())
    {
        // emit event
        // .leave() performed by pieces
    }
    this->piecesNum++;
    this->color = p->getColor();
    return OK; // gdybym nie okroiła zasad to tu mogłoby też być ONE_MORE_HOP
}

void BoardSquare::leave(Piece *p) {
    Q_UNUSED(p);
    this->piecesNum--;
    if (this->piecesNum == 0)
        this->color = NONE;
}

ZeroSquare::ZeroSquare(QGraphicsItem *parent, int x, int y)
    : Square(parent)
{
    for (int i = 0; i < Game::NUM_PIECES; ++i)
        pieces[i] = NULL;
    this->setPos(x, y);
}

QPointF ZeroSquare::getChildCenterPos(Piece *p) const {
    for (int i = 0; i < Game::NUM_PIECES; ++i)
        if (pieces[i] == p)
        {
            QPointF qp = QPointF((i-3)*BoardSquare::WIDTH, 0);
            return this->mapToItem(this->parentItem()->parentItem(), qp);
        }
    return QPointF(0, 0);
}

QRectF ZeroSquare::boundingRect() const
{
    return QRectF(-3.5*BoardSquare::WIDTH, -0.5*BoardSquare::WIDTH, 7*BoardSquare::WIDTH, BoardSquare::WIDTH);
}

void ZeroSquare::paint(QPainter *painter,
           const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    Q_UNUSED(painter);
}

OccupySquareResults ZeroSquare::tryAndOccupy(Piece *p)
{
    for (int i = 0; i < Game::NUM_PIECES; ++i)
        if (pieces[i] == NULL)
        {
            pieces[i] = p;
            break;
        }
    return OK;
}

void ZeroSquare::leave(Piece *p)
{
    for (int i = 0; i < Game::NUM_PIECES; ++i)
        if (pieces[i] == p)
        {
            pieces[i] = 0;
            break;
        }
}

LastSquare::LastSquare(QGraphicsItem *parent, int x, int y)
    : Square(parent) {
    this->setPos(x, y);
}

QRectF LastSquare::boundingRect() const {
    return QRectF();
}

void LastSquare::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QPointF LastSquare::getChildCenterPos(Piece *p) const {
    Q_UNUSED(p);
    return QPointF(0, 0);
}

OccupySquareResults LastSquare::tryAndOccupy(Piece *p) {
    Q_UNUSED(p);
    return OK;
}

void LastSquare::leave(Piece *p) {
     Q_UNUSED(p);
}
