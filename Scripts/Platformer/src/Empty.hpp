//
// Created by Bogdan on 31.12.2024.
//

#pragma once

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

class Empty : public Bamboo::Script {
public:
    void start() override {
        getEntity().getComponent<Rigidbody2DComponent>();
    }
    void update(float dt) override;

private:
};

REGISTER_SCRIPT(Empty)
