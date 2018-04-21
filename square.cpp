#include "square.h"

BoardSquare::BoardSquare(QGraphicsItem *parent, QImage image, int x, int y)
    : QGraphicsObject(parent)
{
    this->pixmap = QPixmap::fromImage(image).scaled(WIDTH, WIDTH);
    xy = QPoint(x, y);
    this->setPos(xy);
}

QRectF BoardSquare::boundingRect() const
{
    return QRectF(-WIDTH/2, -WIDTH/2, WIDTH, WIDTH);
}

void BoardSquare::paint(QPainter *painter,
           const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(QPointF(-WIDTH/2, -WIDTH/2), pixmap);
}

QPoint BoardSquare::getGameXY(Piece *p) const {
    Q_UNUSED(p);
    return xy;
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
    : QGraphicsObject(parent)
{
    for (int i = 0; i < Game::NUM_PIECES; ++i)
        pieces[i] = NULL;
    this->setPos(x, y);
    X = x;
    Y = y;
}

QPoint ZeroSquare::getGameXY(Piece *p) const {
    for (int i = 0; i < Game::NUM_PIECES; ++i)
        if (pieces[i] == p)
            return QPoint(X - 3*BoardSquare::WIDTH + i * BoardSquare::WIDTH, Y);
    return QPoint(X, Y);
}

QRectF ZeroSquare::boundingRect() const
{
    return QRectF(-3.5*BoardSquare::WIDTH, -1/2*BoardSquare::WIDTH, 7*BoardSquare::WIDTH, BoardSquare::WIDTH);
}

void ZeroSquare::paint(QPainter *painter,
           const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    Q_UNUSED(painter);
}

OccupySquareResults ZeroSquare::tryAndOccupy(Piece *p) {
    for (int i = 0; i < Game::NUM_PIECES; ++i)
        if (pieces[i] == NULL)
        {
            pieces[i] = p;
            break;
        }
    return OK;
}

void ZeroSquare::leave(Piece *p) {
    for (int i = 0; i < Game::NUM_PIECES; ++i)
        if (pieces[i] == p)
        {
            pieces[i] = 0;
            break;
        }
}
