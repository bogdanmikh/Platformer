//
// Created by Bogdan on 01.01.2025.
//

#pragma once

#include <Panda/ScriptClass.hpp>
#include <Panda/ScriptRegistry.hpp>
#include <Bamboo/Bamboo.hpp>
#include <Bamboo/Script.hpp>
#include <Bamboo/Components/TransformComponent.hpp>
#include <Bamboo/Components/Rigidbody2DComponent.hpp>

using namespace Bamboo;

class ParallaxEffect  : public Bamboo::Script {
public:
    void start() override;
    void update(float dt) override;

    Entity target;
    float speed;
    float offsetY;
    PANDA_FIELDS_BEGIN(ParallaxEffect)
    PANDA_FIELD(target)
    PANDA_FIELD(speed)
    PANDA_FIELD(offsetY)
    PANDA_FIELDS_END
private:
    TransformComponent transform;
    TransformComponent targetTransform;
};

REGISTER_SCRIPT(ParallaxEffect)