/**
 * @file GameScreen.h
 * @author jonas
 * @date 12/8/19
 * This Screen shows the main game.
 */

#ifndef HEXXAGON_GAMESCREEN_H
#define HEXXAGON_GAMESCREEN_H


#include <network/ServerConnection.h>
#include "view/GameView.h"

class GameScreen : public Screen {
public:
    bool handleInput(sf::Event event, sf::RenderTarget &window) override;

    ProgramState render(sf::RenderTarget &window) override;

    GameScreen(ServerConnection &connection, Player &self);

    void init() override;

private:

    ServerConnection &serverConnection;

    Player &self;

    std::mutex gameViewMutex;
    GameView view;

    UUID gameId;

    enum class State {
        WAITING,
        PLAYING,
    };

    State currentState = State::WAITING;

    std::optional<int> firstSelection;

    std::optional<GameStatus> lastGameStatus;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    void updateGameStatus(const GameStatus& gameStatus);

    bool isOwnTile(int tileIndex);
};


#endif //HEXXAGON_GAMESCREEN_H
