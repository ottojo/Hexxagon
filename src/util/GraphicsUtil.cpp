//
// Created by jonas on 30.12.19.
//

#include "util/GraphicsUtil.h"

void util::GraphicsUtil::setOriginToCenter(sf::Text &object) {
    object.setOrigin(0.5f * sf::Vector2f{object.getLocalBounds().width, object.getLocalBounds().height});
}
