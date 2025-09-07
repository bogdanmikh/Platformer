//
// Created by Bogdan on 29.12.2024.
//

#include "Animation.hpp"
#include <Bamboo/Logger.hpp>

void Animation::start(
    SpriteRendererComponent spriteRenderer, Material material, int cols, int rows, float swapTime
) {
    m_spriteRenderer = spriteRenderer;
    m_material = material;
    m_cols = cols;
    m_rows = rows;
    m_swapTime = swapTime;
    m_index = 0;
    m_time = 0;
}

void Animation::update(double dt) {
    m_time += dt;
    if (m_time >= m_swapTime) {
        m_index++;
        m_index %= (m_cols * m_rows);
        m_time = 0;
    }
    m_spriteRenderer.setMaterial(m_material);
    m_spriteRenderer.setCell(m_cols, m_rows, m_index);
}

void Animation::reset() {
    m_time = 0;
    m_index = 0;
}