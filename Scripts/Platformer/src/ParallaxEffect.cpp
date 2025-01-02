//
// Created by Bogdan on 01.01.2025.
//

#include <Bamboo/Math.hpp>
#include <Bamboo/Logger.hpp>

#include "ParallaxEffect.hpp"

void ParallaxEffect::start() {
    transform = getEntity().getComponent<TransformComponent>();
    targetTransform = target.getComponent<TransformComponent>();
}

void ParallaxEffect::update(float dt) {
    if (!target.isValid()) {
        LOG_ERROR("Player not valid");
        return;
    }

    Vec3 targetPosition = targetTransform.getPosition();
    Vec3 position = transform.getPosition();

    position.x = targetPosition.x;
    position.y = targetPosition.y + offsetY;

    transform.setPosition(position);
}
