#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include "common.hpp"
#include "board.hpp"
using namespace std;

class Player {

public:
    Player(Side side);
    ~Player();

    Move *doMove(Move *opponentsMove, int msLeft);
    double alphaBeta(Board *board, int depth, double alpha, double beta, bool maximizing, Side player);
    // Flag to tell if the player is running within the test_minimax context
    Move * doAlphaBeta(Board *board, int depth, Side player);
    bool testingMinimax;
    Side playerSide;
    Side opponentSide;
    Board *othelloBoard;
};

#endif
