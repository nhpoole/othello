Nikhil wrote the board class, random player, and heuristic move maker for the first part of the assignment.  Harry wrote the minimax algorithm with some corrections from Nikhil.  For the
second part of the assignment Harry wrote a preliminary alpha-beta pruning code and Nikhil fixed it so that it worked.  Additionally Nikhil rewrote the heuristic so that it accounted for
mobility. 

For the tournament we decided not to implement iterative deepening because it seemed inefficient without a transposition table because it would evaluate the dfs many times at
lower depths before reaching the final depth.  Without iterative deepening it is guaranteed that the dfs will get to a lower depth within the alloted time.  For the tournament we also
updated the heuristic so that it accounted for mobility in addition to the desirable board positions.  Initially we also implemented a recursive depth first search that went to a limited
depth. Then we modified the recursive dfs function so that it did alpha beta pruning, which will allow us to search to a greater depth in our recursive dfs without running out of time/memory. These combined improvements of a recursive alpha beta function at depth 7 and the improved heuristic already markedly improved results against BetterPlayer and should allow us to do sufficiently well in the tournament.
