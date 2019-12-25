#include <iostream>
#include <iomanip>
#include <chrono>
#include "Board.h"
#include "../inc/GameView.h"
#include "../inc/GameScreen.h"


int main() {
    Board b;
    //GameView gameScreen(b);

    GameScreen gameController;

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
                continue;
            }

            if (event.type == sf::Event::Resized) {
                // update the view to the new size of the window
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));

                continue;
            }
            auto start = std::chrono::system_clock::now();
            auto didSomething = gameController.handleInput(event, window);
            auto end = std::chrono::system_clock::now();
            auto duration = end - start;
            if (didSomething) {
                std::cout << std::chrono::duration_cast<std::chrono::microseconds>(duration).count() << "µs"
                          << std::endl;
            }
        }



        gameController.render(window);

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
