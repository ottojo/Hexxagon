//
// Created by jonas on 31.12.19.
//

#include <util/GraphicsUtil.h>
#include "view/Button.h"

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(rect, states);
    target.draw(label, states);
}

sf::FloatRect Button::getGlobalBounds() const {
    return getTransform().transformRect(getLocalBounds());
}

sf::FloatRect Button::getLocalBounds() const {
    return rect.getLocalBounds();
}

Button::Button(float width, float height, const sf::String &text, const sf::Font &font, unsigned int characterSize) :
        rect{sf::Vector2f{width, height}},
        label{"", font, characterSize} {
    Button::setString(text);
    label.setPosition(0.5f * width, 0.5f * height);
    rect.setFillColor({152, 152, 152});
}

void Button::setString(const sf::String &s) {
    label.setString(s);
    util::GraphicsUtil::setOriginToCenter(label);
}
