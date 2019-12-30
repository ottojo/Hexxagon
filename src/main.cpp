
#include <screens/MenuScreen.h>
#include <Program.h>
#include <util/FontUtil.h>

int main() {
    FontUtil::init("arial.ttf");
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hexxagon");

    Program hexagonProgram(window);

    hexagonProgram.run();
}
