
#include <screens/MenuScreen.h>
#include <Program.h>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hexxagon");

    Program hexagonProgram(window);

    hexagonProgram.run();
}
