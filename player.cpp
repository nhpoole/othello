#include "player.hpp"
#include <vector>
#include <iostream>

using namespace std;

/*
 * Constructor for the player; initialize everything here. The side your AI is
 * on (BLACK or WHITE) is passed in as "side". The constructor must finish
 * within 30 seconds.
 */
Player::Player(Side side) {
    // Will be set to true in test_minimax.cpp.
    testingMinimax = false;

    /*
     * TODO: Do any initialization you need to do here (setting up the board,
     * precalculating things, etc.) However, remember that you will only have
     * 30 seconds.
     */
     
    othelloBoard = new Board;
    othelloBoard->black_score = 2;
    othelloBoard->white_score = 2;
    playerSide = side;
    if (playerSide == WHITE)
    {
        opponentSide = BLACK;
    }
    else
    {
        opponentSide = WHITE;
    }
    
}

/*
 * Destructor for the player.
 */
Player::~Player() {
}

/*
 * Compute the next move given the opponent's last move. Your AI is
 * expected to keep track of the board on its own. If this is the first move,
 * or if the opponent passed on the last move, then opponentsMove will be
 * nullptr.
 *
 * msLeft represents the time your AI has left for the total game, in
 * milliseconds. doMove() must take no longer than msLeft, or your AI will
 * be disqualified! An msLeft value of -1 indicates no time limit.
 *
 * The move returned must be legal; if there are no valid moves for your side,
 * return nullptr.
 */
Move *Player::doMove(Move *opponentsMove, int msLeft) {
    /*
     * TODO: Implement how moves your AI should play here. You should first
     * process the opponent's opponents move before calculating your own move
     */
    

    if (opponentsMove != nullptr)
    {

        othelloBoard->doMove(opponentsMove, opponentSide);
    }
        
    if (othelloBoard->hasMoves(playerSide))
    {

        vector<Move*> possible_moves = 
                othelloBoard->possibleMoves(playerSide);
                           
        // random move player
      /*  int rand_index = rand() % possible_moves.size();
        cerr << possible_moves.size() << endl;
        Move *rand_move = new Move(possible_moves[rand_index]->x,
                                  possible_moves[rand_index]->y);*/
        
        
        
        // heuristic move player
        int max_score =  -100000;
        int temp_score;
        Move *best_move = possible_moves[0];        
        for (unsigned int i = 0; i < possible_moves.size(); i++)
        {
            Board *board_copy = othelloBoard->copy();
            board_copy->doMove(possible_moves[i], playerSide);
            temp_score = board_copy->calculateScore(playerSide);
            if (max_score < temp_score)
            {
                max_score = temp_score;
                best_move->setX(possible_moves[i]->x);
                best_move->setY(possible_moves[i]->y);
            }
            delete board_copy;
        }
        
        
        
        // minimax algorithm
       // int diff_score = othelloBoard->getDiffScore(playerSide);
        
        
        
        

    //    othelloBoard->white_score = othelloBoard->calculateScore(WHITE);
    //    othelloBoard->black_score = othelloBoard->calculateScore(BLACK);
                    
        // random move player
     //   othelloBoard->doMove(rand_move, playerSide);
     //   cerr << "recorded move" << endl;
     //   return rand_move;
        
        // heuristic move player
        othelloBoard->doMove(best_move, playerSide);
        return best_move;
        
    }
    
    else
    {
        return nullptr;
    }
}
