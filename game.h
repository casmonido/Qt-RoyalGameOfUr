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
#include "settingsmodel.h"
class Board;
class Dice;
class Piece;
class ZeroSquare;
class Square;

class Game: public QGraphicsObject
{
    Q_OBJECT
public:
    static const int NUM_PIECES = 7;
    Game(QGraphicsItem *parent = 0);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;
    Square *destinationSquare(Piece *p, unsigned int crossedPathLength, unsigned int pathToCross);
    Turns getTurn() const {return turn;}
    int getRolledNumber(); //zmienic nazwę
    bool getDiceRolled() const;
    bool getPlayerMoved() const {return playerMoved;}
    void setPlayerMoved() {playerMoved = true;}
    bool getGameEnd() const {return gameEnd;}

signals:
    void turnChanged(Turns);
    void gameEnded(WhoWon);
private:
    bool gameEnd = false;
    Piece *opponentsPieces [NUM_PIECES];
    Piece *playersPieces [NUM_PIECES];
    Dice *dice;
    Board *board;
    Turns turn = PLAYERS_TURN;
    bool playerMoved = false, opponentMoved = false;
    QColor oppontentsTurnColor = Qt::darkGray;
    QColor playersTurnColor = Qt::darkGray;
    QTimer *activeTimer;
    unsigned int getPlayersScore() const;
    unsigned int getOpponentsScore() const;
private slots:
    void changeTurnsColorOnTurnChanged(Turns);
    void rollForOpponent();
    void makeMoveForOpponent();
    void opponentsActionOnTurnChanged(Turns);
public slots:
    void setOtherPlayersTurn();
};

#endif // GAME_H
