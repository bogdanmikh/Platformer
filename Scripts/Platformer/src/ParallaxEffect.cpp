//
// Created by Bogdan on 01.01.2025.
//

#include <Bamboo/Math.hpp>
#include <Bamboo/Logger.hpp>

#include "ParallaxEffect.hpp"

void ParallaxEffect::start() {
    transform = getEntity().getComponent<TransformComponent>();
    targetTransform = target.getComponent<TransformComponent>();
    offsetY = transform.getPosition().y - targetTransform.getPosition().y;
    offsetX = transform.getPosition().x - targetTransform.getPosition().x;
}

void ParallaxEffect::update(float dt) {
    Vec3 targetPosition = targetTransform.getPosition();
    Vec3 position = transform.getPosition();

    position.x = targetPosition.x * speed + offsetX;
    position.y = targetPosition.y * speed + offsetY;

    transform.setPosition(position);
}
