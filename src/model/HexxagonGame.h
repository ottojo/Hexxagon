/**
 * @file HexxagonGame.h
 * @author jonas
 * @date 12/8/19
 * Description here TODO
 */

#ifndef HEXXAGON_HEXXAGONGAME_H
#define HEXXAGON_HEXXAGONGAME_H


#include "model/Board.h"

class HexxagonGame {

private:
    Board board;

public:

    /**
     * Move  (or duplicate) a token from one tile to another tile.
     * Does not verify if move is legal.
     * @return true on success, false otherwise
     */
    void doMove(int from, int to);

    /**
     * Test if moving (or duplicating) a token from one tile to another tile is legal.
     * @return true on success, false otherwise
     */
    bool verifyMove(int from, int to);

    [[nodiscard]] Board &getBoard();
};


#endif //HEXXAGON_HEXXAGONGAME_H
