//
// Created by jonas on 30.12.19.
//

#include <util/GraphicsUtil.h>
#include "view/TextBox.h"

void TextBox::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    states.transform *= getTransform();

    target.draw(border, states);
    target.draw(text, states);
}

const sf::String &TextBox::getText() const {
    return text.getString();
}

void TextBox::setText(const sf::String &newText) {
    TextBox::text.setString(newText);
}

bool TextBox::isActive() const {
    return active;
}

void TextBox::setActive(bool newActive) {
    TextBox::active = newActive;
    if (active) {
        border.setFillColor(sf::Color(40, 40, 40));
    } else {
        border.setFillColor(sf::Color::Black);
    }
}

TextBox::TextBox(const std::string &value, float width, const sf::Font &font, unsigned int characterSize) :
        text(value, font, characterSize),
        border(sf::Vector2f{width, text.getLocalBounds().height+20}),
        active(false) {
    text.setOrigin(0, 0.5f * text.getLocalBounds().height);
    text.setPosition(5, 0.5f * border.getLocalBounds().height);
    border.setOutlineThickness(1);
    border.setFillColor(sf::Color::Black);
    border.setOutlineColor(sf::Color::Green);
}
