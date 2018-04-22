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
    Game(QGraphicsItem *parent = 0);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
    ZeroSquare *getStartingSquare(PieceColors c);
    Square *destinationSquare(Piece *p, unsigned int crossedPathLength, unsigned int pathToCross);
    Turns getTurn() const {return turn;}
    int getSquaresToMove();
    void setOtherPlayersTurn();
    bool getDiceRolled() {return diceRolled;}
    void setDiceRolled();
    unsigned int getPlayersScore();
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
    std::string numSquares = "0";
private slots:
    void flashTurnOnTurnChanged(Turns);
    void rolledNumberChanged(unsigned int);
    void makeMoveOnTurnChanged(Turns);
};

#endif // GAME_H
