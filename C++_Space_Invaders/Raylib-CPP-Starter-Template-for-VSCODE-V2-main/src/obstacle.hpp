#pragma once
#include <vector>
#include "block.hpp"

class Obstacle {
    public:
        Obstacle(Vector2 position);
        void Draw();
        Rectangle getRect();
        Vector2 position;
        std::vector<Block> blocks;
        static std::vector<std::vector<int>> grid;
    private:
};