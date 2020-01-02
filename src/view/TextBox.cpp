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

TextBox::TextBox(float w, float h, const std::string &value, const sf::Font &font, unsigned int characterSize) :
        text(value, font, characterSize),
        border(sf::Vector2f{w, h}),
        active(false) {
    text.setOrigin(0, text.getLocalBounds().top + 0.5f * text.getLocalBounds().height);
    text.setPosition(5, 0.5f * h);
    border.setOutlineThickness(1);
    border.setFillColor(sf::Color::Black);
    border.setOutlineColor(sf::Color::Green);
    setActive(active);
}

sf::FloatRect TextBox::getGlobalBounds() const {
    return getTransform().transformRect(getLocalBounds());
}

sf::FloatRect TextBox::getLocalBounds() const {
    return border.getLocalBounds();
}

void TextBox::handleTextEvent(sf::Event::TextEvent event) {
    if (!isActive()) {
        return;
    }

    if (event.unicode == '\b') {
        sf::String newString = getText();
        if (!newString.isEmpty()) {
            newString.erase(newString.getSize() - 1);
        }
        setText(newString);
    } else {
        setText(getText() + event.unicode);
    }
}
