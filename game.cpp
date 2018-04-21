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
    dies = new Dice(this);
    dies->setPos(4*BoardSquare::WIDTH, -0.5*BoardSquare::WIDTH);
    connect(this, SIGNAL(diceRolledChanged(bool)),
        dies, SLOT(diceRolledChanged(bool)));
}

int Game::getSquaresToMove() {
    return dies->getSquaresToMoveAndReset();
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
    painter->setPen(Qt::red);
    QRectF rect = QRectF(1*BoardSquare::WIDTH, -4*BoardSquare::WIDTH, 6*BoardSquare::WIDTH, BoardSquare::WIDTH);
    painter->drawRect(rect);
    painter->setFont(QFont("Arial", 40));
    painter->drawText(rect, Qt::AlignCenter, "Opponent's turn");
    rect = QRectF(1*BoardSquare::WIDTH, 3*BoardSquare::WIDTH, 6*BoardSquare::WIDTH, BoardSquare::WIDTH);
    painter->drawRect(rect);
    painter->setFont(QFont("Arial", 40));
    painter->drawText(rect, Qt::AlignCenter, "Your turn");
    std::string n = std::to_string(45); //rolledNumber event
    std::string s = "Move by " + n + " squares";
    char const *num = s.c_str();
    rect = QRectF(1*BoardSquare::WIDTH, 1.5*BoardSquare::WIDTH, 6*BoardSquare::WIDTH, 1.5*BoardSquare::WIDTH);
    painter->drawRect(rect);
    painter->setFont(QFont("Arial", 40));
    painter->drawText(rect, Qt::AlignCenter, num);
}
