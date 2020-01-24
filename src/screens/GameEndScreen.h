//
// Created by jonas on 29.12.19.
//

#ifndef HEXXAGON_GAMEENDSCREEN_H
#define HEXXAGON_GAMEENDSCREEN_H


#include <screens/Screen.h>
#include <network/ServerConnection.h>

class GameEndScreen : public Screen {
public:

    GameEndScreen(ServerConnection &connection, Player &self);

    ProgramState render(sf::RenderTarget &window) override;

    bool handleInput(sf::Event event, sf::RenderTarget &window) override;

    void init() override;

private:
    ServerConnection &serverConnection;

    Player &self;

    std::mutex winnerLabelMutex;
    sf::Text winnerLabel;

    void onGameStatus(const GameStatus &gameStatus);
};


#endif //HEXXAGON_GAMEENDSCREEN_H
