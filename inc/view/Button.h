//
// Created by jonas on 31.12.19.
//

#ifndef HEXXAGON_BUTTON_H
#define HEXXAGON_BUTTON_H


#include <SFML/Graphics.hpp>

class Button : public sf::Transformable, public sf::Drawable {
public:

    Button(float width, float height, const sf::String &text, const sf::Font &font, unsigned int characterSize = 30);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    sf::FloatRect getLocalBounds() const;

    sf::FloatRect getGlobalBounds() const;

    void setString(const sf::String &s);

private:


    sf::RectangleShape rect;

    sf::Text label;


};


#endif //HEXXAGON_BUTTON_H
