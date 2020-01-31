//
// Created by jonas on 24.12.19.
//

#include <iostream>
#include <util/FontUtil.h>
#include <util/GraphicsUtil.h>
#include "screens/MenuScreen.h"

ProgramState MenuScreen::render(sf::RenderTarget &window) {
    gui.draw();
    return nextState;
}

bool MenuScreen::handleInput(sf::Event event, sf::RenderTarget &window) {
    if (event.type == sf::Event::Resized) {
        gui.setView(window.getView());
    }
    gui.handleEvent(event);
    return false;
}

MenuScreen::MenuScreen(ServerConnection &ServerConnection, Player &self, sf::RenderTarget &window) :
        serverConnection{ServerConnection},
        self{self},
        gui{window},
        titleLabel{tgui::Label::create("HEXXAGON")},
        connectButton{tgui::Button::create("Connect")},
        exitButton{tgui::Button::create("Exit")},
        serverEditBox{tgui::EditBox::create()} {
    ServerConnection.welcomeListener.subscribe(
            std::bind(&MenuScreen::handleWelcome, this, std::placeholders::_1));

    serverEditBox->setText("hexxagon.otto.cool:4444");
    connectButton->onClick.connect(static_cast<tgui::Signal::Delegate >(std::bind(&MenuScreen::connect, this)));
    exitButton->onClick.connect([] { std::exit(0); });


    titleLabel->setTextSize(200);
    titleLabel->getRenderer()->setTextColor(tgui::Color::White);
    serverEditBox->setPosition(0.5 * (tgui::bindSize(gui).x - tgui::bindSize(serverEditBox).x),
                               tgui::bindBottom(titleLabel) + 20);
    connectButton->setPosition(0.5 * (tgui::bindSize(gui).x - tgui::bindSize(connectButton).x),
                               tgui::bindBottom(serverEditBox) + 20);
    exitButton->setPosition(0.5 * (tgui::bindSize(gui).x - tgui::bindSize(exitButton).x),
                            tgui::bindBottom(connectButton) + 20);

    gui.add(titleLabel);
    gui.add(serverEditBox);
    gui.add(connectButton);
    gui.add(exitButton);

    auto height = exitButton->getPosition().y - titleLabel->getPosition().y;
    titleLabel->setPosition(0.5 * (tgui::bindSize(gui).x - tgui::bindSize(titleLabel).x),
                            tgui::bindSize(gui).y * 0.5 - 0.5 * height);
}

void MenuScreen::handleWelcome(const Welcome &welcomeMessage) {
    std::cout << "Welcome message received in menu screen: " << welcomeMessage.welcomeMessage << " User: "
              << welcomeMessage.userId << std::endl;
    self.id = welcomeMessage.userId;
    nextState = ProgramState::LOBBY_SELECT;
}

void MenuScreen::init() {
    nextState = ProgramState::MAIN_MENU;
}

void MenuScreen::connect() {
    auto url = serverEditBox->getText();
    int port = 4444;
    auto colonPosition = url.find(":");
    if (colonPosition != sf::String::InvalidPos) {
        port = std::stoi(url.substring(colonPosition+1).toAnsiString());
    }
    serverConnection.connect(url.substring(0, colonPosition), port);
}
