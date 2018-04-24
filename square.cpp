#include "square.h"

BoardSquare::BoardSquare(QGraphicsItem *parent, QImage image, int x, int y)
    : Square(parent)
{
    this->pixmap = QPixmap::fromImage(image).scaled(WIDTH, WIDTH);
    this->setPos(x, y);
}

OccupySquareResults BoardSquare::tryAndOccupy(Piece *p) {
    OccupySquareResults retVal = OK;
    if (this->color != NONE && this->color != p->getColor())
    {
        piecesNum = 0;
        prevColor = color;
        retVal = OK_CAPTURING;
    }
    connect(this, SIGNAL(commandLeave(PieceColors)),
        p, SLOT(goBackToBeginning(PieceColors)));
    connect(p, SIGNAL(animationEnd()), this, SLOT(emitCommandLeave()));
    this->piecesNum++;
    this->color = p->getColor();
    return retVal;
}

void BoardSquare::leave(Piece *p) {
    disconnect(this, SIGNAL(commandLeave(PieceColors)),
        p, SLOT(goBackToBeginning(PieceColors)));
    disconnect(p, SIGNAL(animationEnd()), this, SLOT(emitCommandLeave()));
    this->piecesNum--;
    if (this->piecesNum == 0)
    {
        this->prevColor = NONE;
        this->color = NONE;
    }
}

void BoardSquare::leaveWhenEvicted(Piece *p) {
    disconnect(this, SIGNAL(commandLeave(PieceColors)),
        p, SLOT(goBackToBeginning(PieceColors)));
    disconnect(p, SIGNAL(animationEnd()), this, SLOT(emitCommandLeave()));
}

void BoardSquare::emitCommandLeave() {
    emit commandLeave(prevColor);
}

QPointF BoardSquare::getChildCenterPos(Piece *p) const {
    Q_UNUSED(p);
    QPointF qp = QPointF(-3*piecesNum, -3*piecesNum);
    return this->mapToItem(this->parentItem()->parentItem(), qp);
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
