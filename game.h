#ifndef GAME_H
#define GAME_H
#include <QGraphicsItem>
#include <QPainter>
#include <QColor>
#include "square.h"
#include "piece.h"
#include "enums.h"
#include "board.h"
#include "dice.h"
class Board;
class Dice;
class Piece;
class ZeroSquare;
class Square;

class Game: public QGraphicsObject
{
    Q_OBJECT
    Q_PROPERTY(Turns turn READ getTurn NOTIFY turnChanged)
    Q_PROPERTY(bool diceRolled READ getDiceRolled NOTIFY diceRolledChanged)
public:
    static const int NUM_PIECES = 7;
    static const int ONE_MOVE_TIME = 1000;
    Game(QGraphicsItem *parent = 0);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
    ZeroSquare *getStartingSquare(PieceColors c);//deprecated
    Square *destinationSquare(Piece *p, unsigned int crossedPathLength, unsigned int pathToCross);//deprecated
    Turns getTurn() const {return turn;}
    int getSquaresToMove();
    bool getDiceRolled() const {return diceRolled;}
    void setDiceRolled();
    unsigned int getPlayersScore();//const
    unsigned int getOpponentsScore();

signals:
    void turnChanged(Turns);
    void gameEnd(WhoWon);
    void diceRolledChanged(bool);

private:
    Piece *opponentsPieces [NUM_PIECES];
    Piece *playersPieces [NUM_PIECES];
    Dice *dice;
    Board *board;
    Turns turn = PLAYERS_TURN;
    bool diceRolled = false;
    QColor oppontentsTurnColor = Qt::gray;
    QColor playersTurnColor = Qt::gray;
    //QTimer *activeTimer;
private slots:
    void changeTurnsColorOnTurnChanged(Turns);
    void makeMoveOnTurnChanged(Turns);
public slots:
    void setOtherPlayersTurn();
};

#endif // GAME_H
