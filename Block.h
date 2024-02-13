#pragma once

#include <raylib.h>

class Block
{
public:
    Block();
    Block(Vector2 position);
    ~Block();

    void Draw();
    void Update();

    Vector2 GetPosition() const;
    void SetPosition(Vector2 position);

    Vector2 GetSize() const;
    void SetSize(Vector2 size);

    Color GetColor() const;
    void SetColor(Color color);

private:
    Vector2 position;
    Vector2 size;
    Color color;
};