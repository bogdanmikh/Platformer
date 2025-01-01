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
    float maxDiffPos = 1.0;
    float diffPos = targetPosition.x - position.x;

    if (diffPos > maxDiffPos) {
        position.x += speed * dt;
    } else if (diffPos < -maxDiffPos) {
        position.x -= speed * dt;
    } else {
        float stopSpeed = speed / 2;
        if (diffPos > 0.1) {
            position.x -= stopSpeed * dt;
        } else if (diffPos < -0.1) {
            position.x += stopSpeed * dt;
        } else {
            position.x = 0;
        }
    }
    transform.setPosition(position);
}
