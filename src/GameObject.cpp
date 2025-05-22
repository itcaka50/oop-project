#include "GameObject.h"

GameObject::GameObject(GameObject&& other) : x(other.x), y(other.y), symbol(other.symbol), color(other.color)
{
    other.x = 0;
    other.y = 0;
    other.symbol = NULL;
    other.color = {0,0,0,0};
}

GameObject& GameObject::operator=(const GameObject& other)
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

GameObject& GameObject::operator=(GameObject&& other)
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
    }
    return *this;
}

int GameObject::getX()
{
    return x;
}

int GameObject::getY()
{
    return y;
}

char GameObject::getSymbol()
{
    return symbol;
}

SDL_Color GameObject::getColor()
{
    return color;
}

void GameObject::setX(int X)
{
    x = X;
}

void GameObject::setY(int Y)
{
    y = Y;
}

void GameObject::setSymbol(char Symbol)
{
    symbol = Symbol;
}

void GameObject::setColor(SDL_Color Color)
{
    color = Color;
}