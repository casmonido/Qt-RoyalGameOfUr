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
    activeTimer = new QTimer(this);
    activeTimer->setSingleShot(true);

    connect(this, SIGNAL(turnChanged(Turns)),
        this, SLOT(changeTurnsColorOnTurnChanged(Turns)));
    connect(this, SIGNAL(turnChanged(Turns)),
        this, SLOT(opponentsActionOnTurnChanged(Turns)));
    emit turnChanged(turn);
}

void Game::opponentsActionOnTurnChanged(Turns t)
{
    if (t != OPPONENTS_TURN)
        return;
    connect(activeTimer, SIGNAL(timeout()), this, SLOT(rollForOpponent()));
    activeTimer->start(ONE_MOVE_TIME);
}

void Game::rollForOpponent() {
    disconnect(activeTimer, SIGNAL(timeout()), this, SLOT(rollForOpponent()));
    if (dice->roll() > 0)
    {
       connect(activeTimer, SIGNAL(timeout()), this, SLOT(makeMoveForOpponent()));
       activeTimer->start(ONE_MOVE_TIME);
    }
}

void Game::makeMoveForOpponent() {
    disconnect(activeTimer, SIGNAL(timeout()), this, SLOT(makeMoveForOpponent()));
    int i = 0;
    do {
        i = rand() % NUM_PIECES;
    } while (opponentsPieces[i]->getWholePathCrossed()); // potential infinite loop
    opponentMoved = true; // niewykorzystywane ale jest dla symetrii
    opponentsPieces[i]->move(getRolledNumber());
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
    dice->setNotRolled();
    playerMoved = false;
    opponentMoved = false;
    emit turnChanged(turn);
}












void Game::changeTurnsColorOnTurnChanged(Turns t)
{
    if (t == PLAYERS_TURN)
    {
        oppontentsTurnColor = Qt::darkGray;
        playersTurnColor = Qt::white;
    } else
    {
        oppontentsTurnColor = Qt::white;
        playersTurnColor = Qt::darkGray;
    }
    update();
}

bool Game::getDiceRolled() const {
    return dice->getRolled();
}

int Game::getRolledNumber() {
    return dice->getRolledNumber();
}

unsigned int Game::getPlayersScore() const {
    unsigned int tmp = 0;
    for (int i = 0; i < NUM_PIECES; i++)
        tmp += playersPieces[i]->getWholePathCrossed() ? 1 : 0;
    return tmp;
}

unsigned int Game::getOpponentsScore() const {
    unsigned int tmp = 0;
    for (int i = 0; i < NUM_PIECES; i++)
        tmp += opponentsPieces[i]->getWholePathCrossed() ? 1 : 0;
    return tmp;
}

Square *Game::destinationSquare(Piece *p, unsigned int crossedPathLength, unsigned int pathToCross) {
    return board->destinationSquare(p, crossedPathLength, pathToCross);
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
    //painter->setPen(oppontentsTurnColor);
    //painter->setBrush(oppontentsTurnColor);
    QRectF rect = QRectF(1*BoardSquare::WIDTH, -2.5*BoardSquare::WIDTH, 6*BoardSquare::WIDTH, BoardSquare::WIDTH);
    //painter->drawRect(rect);
    painter->setPen(oppontentsTurnColor);
    painter->setFont(QFont("Arial", 40));
    painter->drawText(rect, Qt::AlignCenter, "Opponent's turn");
    painter->setPen(playersTurnColor);
    //painter->setBrush(playersTurnColor);
    rect = QRectF(1*BoardSquare::WIDTH, 1.5*BoardSquare::WIDTH, 6*BoardSquare::WIDTH, BoardSquare::WIDTH);
    //painter->drawRect(rect);
    //painter->setPen(Qt::white);
    painter->setFont(QFont("Arial", 40));
    painter->drawText(rect, Qt::AlignCenter, "Your turn");
}
