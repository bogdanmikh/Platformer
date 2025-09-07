//
// Created by Bogdan on 28.12.2024.
//

#pragma once

#include <Panda/ScriptClass.hpp>
#include <Panda/ScriptRegistry.hpp>
#include <Bamboo/Bamboo.hpp>
#include <Bamboo/Script.hpp>
#include <Bamboo/Components/TransformComponent.hpp>
#include <Bamboo/Components/Rigidbody2DComponent.hpp>

using namespace Bamboo;

class Camera : public Bamboo::Script {
public:
    void start() override;
    void update(float dt) override;

    Entity target;
    PANDA_FIELDS_BEGIN(Camera)
    PANDA_FIELD(target)
    PANDA_FIELDS_END
private:
    TransformComponent transform;
    TransformComponent targetTransform;
};

REGISTER_SCRIPT(Camera)
