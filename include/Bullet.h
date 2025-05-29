#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include "GameObject.h"

class Bullet : public GameObject
{
private:
    int direction;
public:
    
    Bullet() : GameObject() {};

    Bullet(int X, int Y, char Symbol, SDL_Color Color, int Direction) : GameObject(X, Y, Symbol, Color), direction(Direction) {}

    Bullet(const Bullet& other) : GameObject(other), direction(other.direction) {}

    Bullet(Bullet&& other);

    Bullet& operator=(const Bullet& other);

    Bullet& operator=(Bullet&& other);

    virtual void update() override;

    virtual void render() override;

};