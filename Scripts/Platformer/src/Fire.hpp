//
// Created by Bogdan on 02.01.2025.
//
//
// Created by Bogdan on 01.01.2025.
//

#pragma once

#include <Panda/ScriptClass.hpp>
#include <Panda/ScriptRegistry.hpp>
#include <Bamboo/Bamboo.hpp>
#include <Bamboo/Script.hpp>
#include "Animation.hpp"

using namespace Bamboo;

class Fire  : public Bamboo::Script {
public:
    void start() override;

    void update(float dt) override;

    Texture fire;

    PANDA_FIELDS_BEGIN(Fire)
    PANDA_FIELD(fire)
    PANDA_FIELDS_END
private:
    SpriteRendererComponent spriteRenderer;
    Animation animation;
};

REGISTER_SCRIPT(Fire)