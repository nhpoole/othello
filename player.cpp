#include "player.hpp"
#include <vector>
#include <iostream>
#include <climits>
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
Move * Player::doAlphaBeta(Board *board, int depth, Side player)
{
    double max  = INT_MIN;
    int bestx;
    Side otherPlayer = player;
    if(player == playerSide)
    {
        otherPlayer = opponentSide;
    }
    if(player == opponentSide)
    {
        otherPlayer = playerSide;
    }
    for(int x = 0;x<othelloBoard->possibleMoves(player).size();x++)
    {
        Board *othelloBoardCopy = board->copy();
        board->doMove(othelloBoardCopy->possibleMoves(player)[x], player);
        int z = alphaBeta(othelloBoardCopy, depth, INT_MIN, INT_MAX, true, otherPlayer);
        delete othelloBoardCopy;
        if(z > max)
        {
            max = z;
            bestx = x;
        }
    }
    return othelloBoard->possibleMoves(player)[bestx];
}
double Player::alphaBeta(Board *board, int depth, double alpha, double beta, bool maximizing, Side player)
{
    if(depth ==0 || board->possibleMoves(player).size() ==0)
    {
        return (double)board->getDiffScore(player);
    }
    Side otherPlayer = player;
    if(player == playerSide)
    {
        otherPlayer = opponentSide;
    }
    if(player == opponentSide)
    {
        otherPlayer = playerSide;
    }
    if (maximizing)
    {
        double v = INT_MIN;
        for(int x = 0;x<board->possibleMoves(player).size();x++)
        {
            Board *othelloBoardCopy = board->copy();
            othelloBoardCopy->doMove(board->possibleMoves(player)[x], player);
            double alphaBetaCurrent = alphaBeta(othelloBoardCopy, depth-1, alpha, beta, true, otherPlayer);
            delete othelloBoardCopy;
            if(v<alphaBetaCurrent)
            {
                v = alphaBetaCurrent;
            }
            if(alpha < v)
            {
                alpha = v;
            }
            if(beta <= alpha)
            {
                break;
            }
        }
        return v;
    }
    else
    {
        double v = INT_MAX;
        for(int x = 0;x<board->possibleMoves(player).size();x++)
        {
            Board *othelloBoardCopy = board->copy();
            othelloBoardCopy->doMove(board->possibleMoves(player)[x], player);
            double alphaBetaCurrent = alphaBeta(othelloBoardCopy, depth-1, alpha, beta, false, otherPlayer);
            delete othelloBoardCopy;
            if(v > alphaBetaCurrent)
            {
                v = alphaBetaCurrent;
            }
            if(beta > v)
            {
                beta = v;
            }
            if(beta<=alpha)
            {
                break;
            }
        }
        return v;
    }
}
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

        // vector<Move*> possible_moves = 
        //         othelloBoard->possibleMoves(playerSide);
                           
        // random move player
        /*  int rand_index = rand() % possible_moves.size();
        cerr << possible_moves.size() << endl;
        Move *rand_move = new Move(possible_moves[rand_index]->x,
                                  possible_moves[rand_index]->y);*/
        
        
        
        // heuristic move player
        //
        // int max_score =  -100000;
        // int temp_score;
        // Move *best_move = possible_moves[0];        
        // for (unsigned int i = 0; i < possible_moves.size(); i++)
        // {
        //     Board *board_copy = othelloBoard->copy();
        //     board_copy->doMove(possible_moves[i], playerSide);
        //     temp_score = board_copy->calculateScore(playerSide);
        //     if (max_score < temp_score)
        //     {
        //         max_score = temp_score;
        //         cerr << "got here" << endl;
        //         best_move->setX(possible_moves[i]->x);
        //         best_move->setY(possible_moves[i]->y);
        //     }
        //     delete board_copy;
        // }
        
        
        
        // minimax algorithm
       // int diff_score = othelloBoard->getDiffScore(playerSide);
        
        
        
        

    //    othelloBoard->white_score = othelloBoard->calculateScore(WHITE);
    //    othelloBoard->black_score = othelloBoard->calculateScore(BLACK);
                    
        // random move player
     //   othelloBoard->doMove(rand_move, playerSide);
     //   cerr << "recorded move" << endl;
     //   return rand_move;
        
        // heuristic move player
        // othelloBoard->doMove(best_move, playerSide);
        // return best_move;


        //minimax
        // int maximum_min = INT_MIN;
        // int bestX = 0;
        
        // for (unsigned int x = 0; 
        //      x < othelloBoard->possibleMoves(playerSide).size(); x++)
        // {
        //     Board *newOthelloCopy = othelloBoard->copy();
        //     newOthelloCopy->doMove(newOthelloCopy->possibleMoves(playerSide)[x],playerSide);
        //     int localMin = INT_MAX;
        //     for (unsigned int y = 0; y < newOthelloCopy->possibleMoves(opponentSide).size(); y++)
        //     {
        //         Board *newNewOthelloCopy = newOthelloCopy->copy();
        //         newNewOthelloCopy->doMove(newNewOthelloCopy->possibleMoves(opponentSide)[y], opponentSide);
               
        //         if (newNewOthelloCopy->getDiffScore(playerSide) < localMin)
        //         {
        //             localMin = newNewOthelloCopy->getDiffScore(playerSide);
        //         }
               
        //       // For better heuristic
        //        /* if (newNewOthelloCopy->calculateScore(playerSide) < localMin)
        //         {
        //             localMin = newNewOthelloCopy->calculateScore(playerSide);
        //         } */
        //         delete newNewOthelloCopy;
        //     }
        //     if (localMin > maximum_min)
        //     {
        //         maximum_min = localMin;
        //         bestX = x;
        //     }
        //     delete newOthelloCopy;
        // }
        
        // Move *bestMove = othelloBoard->possibleMoves(playerSide)[bestX];
        Move *bestMove = doAlphaBeta(othelloBoard, 10, playerSide);
        std::cerr<<"move";
        othelloBoard->doMove(bestMove, playerSide);
        return bestMove;
    }
    
    else
    {
        return nullptr;
    }
}
