#include "GameObject.h"

GameObject::GameObject(int X, int Y, char Symbol, COLORS Color) : x(X), y(Y), symbol(Symbol), color(Color) {}

int GameObject::getX() const {
    return x;
}

int GameObject::getY() const {
    return y;
}

char GameObject::getSymbol() const {
    return symbol;
}

int GameObject::getColor() const {
    return color;
}

void GameObject::setPosition(int newX, int newY) {
    x = newX;
    y = newY;
}

GameObject::GameObject(const GameObject& other) : x(other.x), y(other.y), symbol(other.symbol), color(other.color) {}
GameObject::GameObject(GameObject&& other) : x(other.x), y(other.y), symbol(other.symbol), color(other.color) 
{
    other.x = 0;
    other.y = 0;
    other.symbol = ' ';
    other.color = BLACK;
}
void GameObject::setColor(COLORS Color)
{
   color = Color;
}
void GameObject::setSymbol(char Symbol)
{
    symbol = Symbol;
}
GameObject& GameObject::operator=(const GameObject& other)
{
    if (this != &other)
    {
        x = other.x;
        y = other.y;
        symbol = other.symbol;
        color = other.color;
    }
    return *this;
}
GameObject& GameObject::operator=(GameObject&& other)
{
    if (this != &other)
    {
        x = other.x;
        y = other.y;
        symbol = other.symbol;
        color = other.color;

        other.x = 0;
        other.y = 0;
        other.symbol = ' ';
        other.color = BLACK;
    }
    return *this;
}