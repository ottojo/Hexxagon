
#include <screens/MenuScreen.h>
#include <controller/Program.h>
#include <util/FontUtil.h>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hexxagon");
    window.setFramerateLimit(200);

    util::FontUtil::init();
    tgui::setGlobalFont(util::FontUtil::getTguiFont());
    tgui::setGlobalTextSize(20);

    Program hexxagonProgram(window);

    std::cout << "Running hexxagonProgram" << std::endl;
    hexxagonProgram.run();
}
