#pragma once

#include "Block.h"

#include <vector>


class Obstacle {
    public:
        Obstacle();
        Obstacle(Vector2 position);
        ~Obstacle();

        void Draw();
        void Update();

        Vector2 GetPosition() const;
        void SetPosition(Vector2 position);

        Vector2 GetSize() const;
        void SetSize(Vector2 size);

        Color GetColor() const;
        void SetColor(Color color);

        std::vector<Block> GetBlocks() const;
        void SetBlocks(std::vector<Block> blocks);

        Vector2 position;
        std::vector<Block> blocks;
        static std::vector<std::vector<int>> grid;
    private:


};