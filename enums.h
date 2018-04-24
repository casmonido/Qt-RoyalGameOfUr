#ifndef ENUMS_H
#define ENUMS_H

enum OccupySquareResults {
    OK, ONE_MORE_HOP, OK_CAPTURING
};

enum PieceColors {
    OPPONENTS, PLAYERS, NONE
};

enum Turns {
    PLAYERS_TURN, OPPONENTS_TURN, GAME_END
};

enum WhoWon {
    PLAYER, OPPONENT, DRAW
};

#endif // ENUMS_H
