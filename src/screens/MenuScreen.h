//
// Created by jonas on 24.12.19.
//

#ifndef HEXXAGON_MENUSCREEN_H
#define HEXXAGON_MENUSCREEN_H


#include <model/Player.h>
#include <TGUI/TGUI.hpp>
#include "Screen.h"
#include "network/ServerConnection.h"

class MenuScreen : public Screen {

public:

    explicit MenuScreen(ServerConnection &ServerConnection, Player &self, sf::RenderTarget &window);

    bool handleInput(sf::Event event, sf::RenderTarget &window) override;

    ProgramState render(sf::RenderTarget &window) override;

    void init() override;

private:
    ServerConnection &serverConnection;

    Player &self;

    void handleWelcome(const Welcome& welcomeMessage);

    void connect();

    tgui::Gui gui;
    tgui::Label::Ptr titleLabel;
    tgui::Button::Ptr connectButton;
    tgui::Button::Ptr exitButton;
    tgui::EditBox::Ptr serverEditBox;

    ProgramState nextState = ProgramState::MAIN_MENU;

};


#endif //HEXXAGON_MENUSCREEN_H
