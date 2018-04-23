#include "game.h"

Game::Game(QGraphicsItem *parent)
    : QGraphicsObject(parent)
{
    board = new Board(this);
    board->setPos(-3*BoardSquare::WIDTH, 0*BoardSquare::WIDTH);
    for (int i = 0; i < NUM_PIECES; i++)
        playersPieces[i] = new PlayersPiece(this, board->getStartingSquare(PLAYERS));
    for (int i = 0; i < NUM_PIECES; i++)
        opponentsPieces[i] = new OpponentsPiece(this, board->getStartingSquare(OPPONENTS));
    dice = new Dice(this);
    dice->setPos(4*BoardSquare::WIDTH, 0*BoardSquare::WIDTH);
    connect(this, SIGNAL(diceRolledChanged(bool)),
        dice, SLOT(diceRolledChanged(bool)));
    connect(this, SIGNAL(turnChanged(Turns)),
        this, SLOT(flashTurnOnTurnChanged(Turns)));
    connect(this, SIGNAL(turnChanged(Turns)),
        this, SLOT(makeMoveOnTurnChanged(Turns)));
    emit turnChanged(turn);
    emit diceRolledChanged(diceRolled);
}

void Game::makeMoveOnTurnChanged(Turns t)
{
    if (t != OPPONENTS_TURN)
        return;
    dice->roll();
    setDiceRolled();
    int i = 0;
    do {
        i = rand() % NUM_PIECES;
    } while (opponentsPieces[i]->getWholePathCrossed()); // potential infinite loop
    opponentsPieces[i]->move(getSquaresToMove());
}

void Game::flashTurnOnTurnChanged(Turns t)
{
    if (t == PLAYERS_TURN)
    {
        oppontentsTurnColor = Qt::gray;
        playersTurnColor = Qt::green;
    } else
    {
        oppontentsTurnColor = Qt::green;
        playersTurnColor = Qt::gray;
    }
    update();
}

int Game::getSquaresToMove() {
    return dice->getSquaresToMoveAndReset();
}

void Game::setOtherPlayersTurn() {
    int playerScore = getPlayersScore();
    int opponentsScore = getOpponentsScore();
    if (playerScore >= NUM_PIECES && opponentsScore >= NUM_PIECES)
    {
        emit gameEnd(DRAW);
        return;
    }
    if (playerScore >= NUM_PIECES)
    {
        emit gameEnd(PLAYER);
        return;
    }
    if (opponentsScore >= NUM_PIECES)
    {
        emit gameEnd(OPPONENT);
        return;
    }
    if (turn == PLAYERS_TURN)
        turn = OPPONENTS_TURN;
    else
        turn = PLAYERS_TURN;
    diceRolled = false;
    emit turnChanged(turn);
    emit diceRolledChanged(false);
}

ZeroSquare *Game::getStartingSquare(PieceColors c) {
    return board->getStartingSquare(c);
}

unsigned int Game::getPlayersScore() {
    unsigned int tmp = 0;
    for (int i = 0; i < NUM_PIECES; i++)
        tmp += playersPieces[i]->getWholePathCrossed() ? 1 : 0;
    return tmp;
}

unsigned int Game::getOpponentsScore() {
    unsigned int tmp = 0;
    for (int i = 0; i < NUM_PIECES; i++)
        tmp += opponentsPieces[i]->getWholePathCrossed() ? 1 : 0;
    return tmp;
}

Square *Game::destinationSquare(Piece *p, unsigned int crossedPathLength, unsigned int pathToCross) {
    return board->destinationSquare(p, crossedPathLength, pathToCross);
}

void Game::setDiceRolled() {
    diceRolled = true;
    emit diceRolledChanged(true);
}

QRectF Game::boundingRect() const
{
    return QRectF(-8*BoardSquare::WIDTH, -3*BoardSquare::WIDTH, 16*BoardSquare::WIDTH, 6*BoardSquare::WIDTH);
}

void Game::paint(QPainter *painter,
           const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(oppontentsTurnColor);
    QRectF rect = QRectF(1*BoardSquare::WIDTH, -2.5*BoardSquare::WIDTH, 6*BoardSquare::WIDTH, BoardSquare::WIDTH);
    painter->drawRect(rect);
    painter->setFont(QFont("Arial", 40));
    painter->drawText(rect, Qt::AlignCenter, "Opponent's turn");
    painter->setPen(playersTurnColor);
    rect = QRectF(1*BoardSquare::WIDTH, 1.5*BoardSquare::WIDTH, 6*BoardSquare::WIDTH, BoardSquare::WIDTH);
    painter->drawRect(rect);
    painter->setFont(QFont("Arial", 40));
    painter->drawText(rect, Qt::AlignCenter, "Your turn");
}
