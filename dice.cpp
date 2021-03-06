#include "dice.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Die::Die(QGraphicsItem *parent, QPointF pos)
    : QGraphicsObject(parent)
{
    this->setPos(pos);
}

Dice::Dice(Game *parent, QPointF pos)
    : Die(parent, pos)
{
    srand (time(NULL));
    game = parent;
    for (int i = 0; i < DICE_NUM; ++i)
        dice[i] = new Die(this, QPointF((i-1.5)*BoardSquare::WIDTH, -0.5*BoardSquare::WIDTH));
    blinkingAnimation = new QPropertyAnimation(this, "pos"); //color
    blinkingAnimation->setDuration(1.5*SettingsModel::MOVE_TIME);
    //blinkingAnimation->setEasingCurve(QEasingCurve::BezierSpline);
    activeTimer = new QTimer(this);
    activeTimer->setSingleShot(true);
    connect(activeTimer, SIGNAL(timeout()), game, SLOT(setOtherPlayersTurn()));
    setAcceptHoverEvents(true);
}

void Dice::diceRolledChanged(bool rolled, Turns turn)
{
    if (rolled)
    {
        blinkingAnimation->stop();
        buttonColor = Qt::gray;

            if (turn == OPPONENTS_TURN)
                buttonText = "Rolled number: " + std::to_string(rolledNumber);
            else
            {
                if (rolledNumber == 0)
                    buttonText = "You rolled 0. Too bad!";
                else
                    buttonText = "Move by " + std::to_string(rolledNumber) + " squares";
            }
    }
    else
    {
        blinkingAnimation->start();
        if (turn == PLAYERS_TURN)
        {
            buttonColor = QColor(153, 54, 173, 255);
            buttonText = "Roll";
        }
        else
        {
            buttonColor = Qt::gray;
            buttonText = "...";
        }
    }
    update();
}

unsigned int Die::roll() {
    rolledNumber = rand() % 2;
    update();
    return rolledNumber;
}

unsigned int Dice::roll() {
    rolledNumber = 0;
    for (int i = 0; i < DICE_NUM; ++i)
        rolledNumber += dice[i]->roll();
    rolled = true;
    if (rolledNumber == 0)
        activeTimer->start(SettingsModel::MOVE_TIME);
    diceRolledChanged(rolled, game->getTurn());
    return rolledNumber;
}

void Dice::setNotRolled() {
    rolled = false;
    rolledNumber = 0;
    for (int i =0; i < DICE_NUM; ++i)
        dice[i]->setToZero();
    diceRolledChanged(rolled, game->getTurn());
}







void Dice::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    if (!(e->buttons() & Qt::LeftButton))
        return;
    if (!game->getGameEnd() && (game->getTurn() == PLAYERS_TURN) && !rolled)
        roll();
}

QRectF Dice::boundingRect() const {
    return QRectF(-2*BoardSquare::WIDTH, -1*BoardSquare::WIDTH, 4*BoardSquare::WIDTH, 2*BoardSquare::WIDTH);
}

QRectF Die::boundingRect() const {
    return QRectF(-0.5*BoardSquare::WIDTH, -0.5*BoardSquare::WIDTH,
                  BoardSquare::WIDTH, BoardSquare::WIDTH);
}

void Die::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QRectF rect = QRectF(-0.25*BoardSquare::WIDTH, -0.25*BoardSquare::WIDTH,
                         0.5*BoardSquare::WIDTH, 0.5*BoardSquare::WIDTH);
    QPainterPath path;
    path.moveTo(rect.left() + (rect.width() / 2), rect.top());
    path.lineTo(rect.bottomLeft());
    path.lineTo(rect.bottomRight());
    path.lineTo(rect.left() + (rect.width() / 2), rect.top());
    painter->fillPath(path, QBrush(Qt::white));
    if (rolledNumber > 0)
    {
        painter->setBrush(Qt::black);
        painter->drawEllipse(-2, -2+(0.1*BoardSquare::WIDTH), 4, 4);
    }
}

void Dice::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setBrush(buttonColor);
    painter->drawRect(boundingRect());
    painter->setBrush(QColor(5, 5, 5, 255));
    painter->setFont(SettingsModel::FONT);
    painter->drawText(QRectF(-2*BoardSquare::WIDTH, 0*BoardSquare::WIDTH,
                             4*BoardSquare::WIDTH, BoardSquare::WIDTH),
                      Qt::AlignCenter, buttonText.c_str());
}

void Die::setToZero() {
    rolledNumber = 0;
    update();
}

void Dice::hoverEnterEvent (QGraphicsSceneHoverEvent *event)
{
  QGraphicsItem::hoverEnterEvent(event);
  QApplication::setOverrideCursor(Qt::PointingHandCursor);
}

void Dice::hoverLeaveEvent (QGraphicsSceneHoverEvent *event)
{
  QGraphicsItem::hoverLeaveEvent(event);
  QApplication::setOverrideCursor(Qt::ArrowCursor);
}
