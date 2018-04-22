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
    dice->setPos(4*BoardSquare::WIDTH, -0.5*BoardSquare::WIDTH);
    connect(this, SIGNAL(diceRolledChanged(bool)),
        dice, SLOT(diceRolledChanged(bool)));
    connect(this, SIGNAL(turnChanged(Turns)),
        this, SLOT(flashTurnOnTurnChanged(Turns)));
    connect(this, SIGNAL(turnChanged(Turns)),
        this, SLOT(makeMoveOnTurnChanged(Turns)));
    connect(dice, SIGNAL(rolledNumberChanged(unsigned int)),
        this, SLOT(rolledNumberChanged(unsigned int)));
    emit turnChanged(turn);
    emit diceRolledChanged(diceRolled);
}

void Game::rolledNumberChanged(unsigned int num)
{
    numSquares = std::to_string(num);
    update();
}

void Game::makeMoveOnTurnChanged(Turns t)
{
    if (t == OPPONENTS_TURN)
    {
        dice->roll();
        setDiceRolled();
        int i = rand() % NUM_PIECES;
        opponentsPieces[i]->move(getSquaresToMove());
        setOtherPlayersTurn();
    }
}

void Game::flashTurnOnTurnChanged(Turns t)
{
    if (t == PLAYERS_TURN)
    {
        oppontentsTurnColor = Qt::gray;
        playersTurnColor = Qt::green;
    } else
    {
        oppontentsTurnColor = Qt::red;
        playersTurnColor = Qt::gray;
    }
    update();
}

int Game::getSquaresToMove() {
    return dice->getSquaresToMoveAndReset();
}

void Game::setOtherPlayersTurn() {
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

Square *Game::nextSquare(PieceColors c, int crossedPathLength) {
    return board->nextSquare(c, crossedPathLength);
}

Square *Game::destinationSquare(PieceColors c, unsigned int crossedPathLength, unsigned int pathToCross) {
    return board->destinationSquare(c, crossedPathLength, pathToCross);
}

void Game::setDiceRolled() {
    diceRolled = true;
    emit diceRolledChanged(true);
}

QRectF Game::boundingRect() const
{
    return QRectF(-8*BoardSquare::WIDTH, -4*BoardSquare::WIDTH, 16*BoardSquare::WIDTH, 8*BoardSquare::WIDTH);
}

void Game::paint(QPainter *painter,
           const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(oppontentsTurnColor);
    QRectF rect = QRectF(1*BoardSquare::WIDTH, -4*BoardSquare::WIDTH, 6*BoardSquare::WIDTH, BoardSquare::WIDTH);
    painter->drawRect(rect);
    painter->setFont(QFont("Arial", 40));
    painter->drawText(rect, Qt::AlignCenter, "Opponent's turn");
    painter->setPen(playersTurnColor);
    rect = QRectF(1*BoardSquare::WIDTH, 3*BoardSquare::WIDTH, 6*BoardSquare::WIDTH, BoardSquare::WIDTH);
    painter->drawRect(rect);
    painter->setFont(QFont("Arial", 40));
    painter->drawText(rect, Qt::AlignCenter, "Your turn");
    painter->setPen(Qt::black);
    std::string s = "Move by " + numSquares + " squares";
    char const *num = s.c_str();
    rect = QRectF(1*BoardSquare::WIDTH, 1.5*BoardSquare::WIDTH, 6*BoardSquare::WIDTH, 1.5*BoardSquare::WIDTH);
    painter->drawRect(rect);
    painter->setFont(QFont("Arial", 40));
    painter->drawText(rect, Qt::AlignCenter, num);
}
