#include <iostream>
#include "Enemy.h"

using namespace std;

    Enemy::Enemy(int X, int Y, int Dir = 1, int Speed = 1) : x(X), y(Y), direction(Dir), speed(Speed) {}

    Enemy::Enemy(const Enemy& other) : x(other.x), y(other.y), direction(other.direction), speed(other.speed) {}

    Enemy::Enemy(Enemy&& other) noexcept : x(other.x), y(other.y), direction(other.direction), speed(other.speed) 
    {
        other.x = 0;
        other.y = 0;
        other.direction = 1;
        other.speed = 0;
    }

    Enemy& Enemy::operator=(const Enemy& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
            direction = other.direction;
            speed = other.speed;
        }
        return *this;
    }

    Enemy& Enemy::operator=(Enemy&& other) noexcept {
        if (this != &other) {
            x = other.x;
            y = other.y;
            direction = other.direction;
            speed = other.speed;

            other.x = 0;
            other.y = 0;
            other.direction = 1;
            other.speed = 0;
        }
        return *this;
    }


    //kaji mi kak da gi murdam
    void Enemy::update() {
        x += direction * speed;
    }

    //kak da izglejdat shte gi risuvash s windows.h programta kato se razberete za neq
    void Enemy::render(HDC hdc) const 
    {
        Rectangle(hdc, x, y, x + 30, y + 30);
    }

    void EnemyType1::render(HDC hdc) const 
    {
        HBRUSH brush = CreateSolidBrush(color);
        HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);
        
        Ellipse(hdc, x, y, x + 40, y + 40);
        
        SelectObject(hdc, oldBrush);
        DeleteObject(brush);
    }