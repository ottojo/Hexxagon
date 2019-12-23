#include <iostream>
#include <sstream>
#include <iomanip>
#include "Board.h"
#include "GameScreen.h"


int main() {
    Board b;
    GameScreen gameScreen(b);
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hexxagon");


    sf::Font arial;
    if (!arial.loadFromFile("arial.ttf")) {
        exit(1);
    }

    float fps = 1;
    sf::Text fpsText("", arial);
    fpsText.setFillColor(sf::Color::Blue);

    sf::Text positionText("", arial);
    positionText.setFillColor(sf::Color::Blue);
    positionText.setPosition(0, 50);

    sf::Clock clock;


    while (window.isOpen()) {
        window.clear(sf::Color::Black);
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event{};
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseMoved) {
                auto axial = gameScreen.getCurrentCoordinate(window, {static_cast<float>(event.mouseMove.x),
                                                                      static_cast<float>(event.mouseMove.y)});

                std::stringstream stream;
                stream << "X: " << axial.x << " Y: " << axial.y;
                positionText.setString(stream.str());
            }

            if (event.type == sf::Event::Resized) {
                // update the view to the new size of the window
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }
        }


        gameScreen.render(window);

        std::stringstream stream;
        stream << "FPS: " << std::setfill('0') << std::setw(8) << std::fixed << std::setprecision(2) << fps;
        fpsText.setString(stream.str());
        window.draw(fpsText);

        window.draw(positionText);

        window.display();

        fps = 1 / clock.getElapsedTime().asSeconds();
        clock.restart();
    }


}
