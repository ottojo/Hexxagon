//
// Created by jonas on 30.12.19.
//

#ifndef HEXXAGON_TEXTBOX_H
#define HEXXAGON_TEXTBOX_H


#include <string>
#include <SFML/Graphics.hpp>

class TextBox : public sf::Transformable, public sf::Drawable {
public:

    TextBox(const std::string &text, float width, const sf::Font &font, unsigned int characterSize = 30);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    const sf::String &getText() const;

    void setText(const sf::String &newText);

    bool isActive() const;

    void setActive(bool newActive);

private:

    sf::Text text;
    sf::RectangleShape border;

    bool active;
};


#endif //HEXXAGON_TEXTBOX_H