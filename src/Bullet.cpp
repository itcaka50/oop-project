#include "Bullet.h"

Bullet::Bullet(Bullet&& other) : GameObject(other), direction(other.direction)
{
    other.x = 0;
    other.y = 0;
    other.symbol = NULL;
    other.color = {0,0,0,0};
    other.direction = 0;
}

Bullet& Bullet::operator=(const Bullet& other)
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

Bullet& Bullet::operator=(Bullet&& other)
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

void Bullet::render()
{

}

void Bullet::update()
{

}