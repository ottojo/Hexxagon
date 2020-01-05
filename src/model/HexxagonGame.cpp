/**
 * @file HexxagonGame.cpp
 * @author jonas
 * @date 12/8/19
 * Description here TODO
 */

#include "model/HexxagonGame.h"

void HexxagonGame::doMove(int from, int to) {
}

bool HexxagonGame::verifyMove(int from, int to) {
    return false;
}

Board &HexxagonGame::getBoard() {
    return board;
}

void HexxagonGame::setBoard(const Board &newBoard) {
    HexxagonGame::board = newBoard;
}
