//
// Created by Bogdan on 28.12.2024.
//

#include <Bamboo/Logger.hpp>

#include <Bamboo/Math.hpp>
#include "Camera.hpp"

void Camera::start() {
    transform = getEntity().getComponent<TransformComponent>();
    targetTransform = target.getComponent<TransformComponent>();
}

void Camera::update(float dt) {
    if (!target.isValid()) {
        LOG_ERROR("Player not valid");
        return;
    }
    Vec3 targetPosition = targetTransform.getPosition();
    Vec3 position = transform.getPosition();
    static Vec3 velocity;
    Vec3 result = Math::smoothDamp(position, targetPosition, velocity, 0.15, dt);
    transform.setPosition({result.x, result.y, position.z});
}