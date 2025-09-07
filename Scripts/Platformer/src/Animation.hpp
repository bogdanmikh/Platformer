//
// Created by Bogdan on 29.12.2024.
//

#pragma once

#include <Bamboo/Components/SpriteRendererComponent.hpp>

using namespace Bamboo;

class Animation {
public:
    void start(
        SpriteRendererComponent spriteRenderer,
        Material material,
        int cols,
        int rows,
        float swapTime = 0.25
    );

    void update(double dt);

    void reset();

private:
    int m_cols;
    int m_rows;
    float m_swapTime;
    float m_time;
    Material m_material;
    int m_index;
    SpriteRendererComponent m_spriteRenderer;
};
