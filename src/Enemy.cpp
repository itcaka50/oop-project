#include "Enemy.h"

Enemy::Enemy(Enemy&& other) : GameObject(other), direction(other.direction)
{
    other.x = 0;
    other.y = 0;
    other.symbol = NULL;
    other.color = {0,0,0,0};
    other.direction = 0;
}

Enemy& Enemy::operator=(const Enemy& other)
{
    if(this != &other)
    {
        this->x = other.x;
        this->y = other.y;
        this->symbol = other.symbol;
        this->color = other.color;
    }
    return *this;
}

Enemy& Enemy::operator=(Enemy&& other)
{
    if(this != &other)
    {
        this->x = other.x;
        this->y = other.y;
        this->symbol = other.symbol;
        this->color = other.color;

        other.x = 0;
        other.y = 0;
        other.symbol = NULL;
        other.color = {0,0,0,0};
        other.direction = 0;
    }
    return *this;
}

void Enemy::render()
{

}

void Enemy::update()
{

}

void Enemy1::update()
{

}

void Enemy1::render()
{

}

void Enemy2::update()
{

}

void Enemy2::render()
{

}

void Enemy3::update()
{

}

void Enemy3::render()
{

}

void Enemy4::update()
{

}

void Enemy4::render()
{

}


