/**
 * @file GameScreen.h
 * @author jonas
 * @date 12/8/19
 * Description here TODO
 */

#ifndef HEXXAGON_GAMESCREEN_H
#define HEXXAGON_GAMESCREEN_H


#include <network/ServerConnection.h>
#include "view/GameView.h"
#include "model/HexxagonGame.h"

class GameScreen : public Screen {
public:
    bool handleInput(sf::Event event, sf::RenderTarget &window) override;

    ProgramState render(sf::RenderTarget &window) override;

    GameScreen(ServerConnection &connection, Player &self);

    void init() override;

private:
    HexxagonGame game;

    ServerConnection &serverConnection;

    Player &self;

    GameView view;

    UUID gameId;

    enum class State {
        WAITING,
        PLAYING,
    };

    State currentState = State::WAITING;

    std::optional<int> firstSelection;

    void updateGameStatus(GameStatus gameStatus);
};


#endif //HEXXAGON_GAMESCREEN_H
