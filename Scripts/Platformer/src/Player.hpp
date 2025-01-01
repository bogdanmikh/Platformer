#pragma once

#include <Panda/ScriptClass.hpp>
#include <Panda/ScriptRegistry.hpp>
#include <Bamboo/Bamboo.hpp>
#include <Bamboo/Script.hpp>
#include <Bamboo/Components/SpriteRendererComponent.hpp>
#include <Bamboo/Components/Rigidbody2DComponent.hpp>
#include <Bamboo/Components/TransformComponent.hpp>

#include "Animation.hpp"

using namespace Bamboo;

class Player : public Bamboo::Script {
public:
    void start() override;
    void update(float dt) override;

    void beginCollisionTouch(Entity other) override;
    void endCollisionTouch(Entity other) override;
    void beginSensorOverlap(Entity sensor) override;

    float jumpForce;
    float speed;
    Texture run;
    Texture rest;
    Texture jump;

    PANDA_FIELDS_BEGIN(Player)
    PANDA_FIELD(jumpForce)
    PANDA_FIELD(speed)
    PANDA_FIELD(run)
    PANDA_FIELD(jump)
    PANDA_FIELD(rest)
    PANDA_FIELDS_END
private:
    enum State { REST, RUN, JUMP };
    enum Direction { LEFT, RIGHT };

    void setState(State newState);
    void setDirection(Direction newDirection);

    Vec3 defaultPos;

    Direction direction;
    State state;
    bool onGround;

    Animation runAnim;
    Animation jumpAnim;
    Animation restAnim;
    Animation *currentAnimation;

    Rigidbody2DComponent rigidbody;
    SpriteRendererComponent sprite;
    TransformComponent transform;
};

REGISTER_SCRIPT(Player)