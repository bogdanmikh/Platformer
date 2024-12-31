#include "Player.hpp"

#include <Bamboo/Logger.hpp>
#include <Bamboo/Input.hpp>
#include <Bamboo/Component.hpp>
#include <Bamboo/Math.hpp>

void Player::start() {
    rigidbody = getEntity().getComponent<Rigidbody2DComponent>();
    sprite = getEntity().getComponent<SpriteRendererComponent>();
    transform = getEntity().getComponent<TransformComponent>();

    restAnim.start(sprite, rest, 2, 1, 0.7);
    //    jumpAnim.start(sprite, jump, 2, 1);
    runAnim.start(sprite, run, 4, 1, 0.1);
    setState(State::REST);
    onGround = false;
    currentAnimation = &restAnim;
}

void Player::beginCollisionTouch(Entity other) {
    if (strCmp("Ground", other.getName(), 6) == 0) {
        LOG_INFO("Enter");
        onGround = true;
    }
}

void Player::endCollisionTouch(Entity other) {
    if (strCmp("Ground", other.getName(), 6) == 0) {
        LOG_INFO("Exit");
        onGround = false;
    }
}

void Player::update(float dt) {
    auto velocity = rigidbody.getLinearVelocity();

    if (onGround && Input::isKeyJustPressed(Key::SPACE)) {
        velocity.y += jumpForce * dt;
    }

    if (Input::isKeyPressed(Key::A)) {
        setState(State::RUN);
        setDirection(Direction::LEFT);
        velocity.x = -speed * dt;
    } else if (Input::isKeyPressed(Key::D)) {
        setState(State::RUN);
        setDirection(Direction::RIGHT);
        velocity.x = speed * dt;
    } else {
        float stopSpeed = 30.;
        if (velocity.x > 0.1) {
            velocity.x -= stopSpeed * dt;
        } else if (velocity.x < -0.1) {
            velocity.x += stopSpeed * dt;
        } else {
            setState(State::REST);
        }
    }

    transform.setRotationEuler({0, (direction == Direction::LEFT ? 180.f : 0.f), 0});
    currentAnimation->update(dt);
    rigidbody.setLinearVelocity(velocity);
}

void Player::setDirection(Player::Direction newDirection) {
    direction = newDirection;
}

void Player::setState(State newState) {
    if (state == newState) {
        return;
    }
    switch (newState) {
        case State::RUN:
            currentAnimation = &runAnim;
            break;
        case State::REST:
            currentAnimation = &restAnim;
            break;
        case JUMP:
            break;
    }
    state = newState;
}