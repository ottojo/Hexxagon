
#include <screens/MenuScreen.h>
#include <Program.h>
#include <util/FontUtil.h>

int main() {
    util::FontUtil::init("arial.ttf");
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hexxagon");
    window.setFramerateLimit(200);

    Program hexxagonProgram(window);

    std::cout << "Running hexxagonProgram" << std::endl;
    hexxagonProgram.run();
}
