//
// Created by Bogdan on 02.01.2025.
//

#include "Fire.hpp"

void Fire::start() {
    spriteRenderer = getEntity().getComponent<SpriteRendererComponent>();
    animation.start(spriteRenderer, fire, 6, 1, 0.1);
}

void Fire::update(float dt) {
    animation.update(dt);
}
