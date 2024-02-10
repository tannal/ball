#pragma once

#include <cmath>
#include <string>
#include <utility>

class Vec2
{

public:
    float x;

    float y;

    Vec2(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}

    std::string to_string() const
    {
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }

    Vec2 operator+(const Vec2 &other) const
    {

        return Vec2(x + other.x, y + other.y);
    }

    Vec2 operator-(const Vec2 &other) const
    {

        return Vec2(x - other.x, y - other.y);
    }

    Vec2 operator*(float scalar) const
    {

        return Vec2(x * scalar, y * scalar);
    }

    Vec2 operator/(float scalar) const
    {

        return Vec2(x / scalar, y / scalar);
    }

    bool operator==(const Vec2 &other) const
    {

        return x == other.x && y == other.y;
    }

    bool operator!=(const Vec2 &other) const
    {

        return !(*this == other);
    }

    Vec2 &operator+=(const Vec2 &other)
    {

        x += other.x;

        y += other.y;

        return *this;
    }

    Vec2 &operator-=(const Vec2 &other)
    {

        x -= other.x;

        y -= other.y;

        return *this;
    }

    Vec2 &operator*=(float scalar)
    {

        x *= scalar;

        y *= scalar;

        return *this;
    }

    Vec2 &operator/=(float scalar)
    {

        x /= scalar;

        y /= scalar;

        return *this;
    }

    float length() const
    {

        return sqrtf(x * x + y * y);
    }

    Vec2 normalized() const
    {

        return *this / length();
    }

    Vec2 &normalize()
    {

        return *this /= length();
    }

    float dot(const Vec2 &other) const
    {

        return x * other.x + y * other.y;
    }

    float cross(const Vec2 &other) const
    {

        return x * other.y - y * other.x;
    }

    Vec2 project(const Vec2 &other) const
    {

        return other * (dot(other) / other.dot(other));
    }

    Vec2 reflect(const Vec2 &normal) const
    {

        return *this - normal * 2.0f * dot(normal);
    }

    Vec2 rotate(float angle) const
    {

        float rad = angle * 3.14159265358979323846f / 180.0f;

        float c = cos(rad);

        float s = sin(rad);

        return Vec2(x * c - y * s, x * s + y * c);
    }

    Vec2 lerp(const Vec2 &other, float t) const
    {

        return *this + (other - *this) * t;
    }

    Vec2 slerp(const Vec2 &other, float t) const
    {

        float dot = this->dot(other);

        dot = std::max(std::min(dot, 1.0f), -1.0f);

        float theta = acos(dot) * t;

        Vec2 relative = (other - *this * dot).normalize();

        return *this * cos(theta) + relative * sin(theta);
    }

    Vec2 nlerp(const Vec2 &other, float t) const
    {

        return lerp(other, t).normalize();
    }

    float distance(const Vec2 &other) const
    {

        return (*this - other).length();
    }
};