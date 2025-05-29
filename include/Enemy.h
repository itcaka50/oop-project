#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include "GameObject.h"

class Enemy : public GameObject
{
protected:
    int direction;
public:
    
    Enemy() : GameObject() {};

    Enemy(int X, int Y, char Symbol, SDL_Color Color, int Direction) : GameObject(X, Y, Symbol, Color), direction(Direction) {}

    Enemy(const Enemy& other) : GameObject(other), direction(other.direction) {}

    Enemy(Enemy&& other);

    Enemy& operator=(const Enemy& other);

    Enemy& operator=(Enemy&& other);

    virtual void update() override;

    virtual void render() override;

};

class Enemy1 : public Enemy
{
    Enemy1() : Enemy() {}
    Enemy1(int X, int Y, char Symbol, SDL_Color Color, int Direction) : Enemy(X, Y, Symbol, Color, Direction) {}
    Enemy1(const Enemy1& other) : Enemy(other) {}
    Enemy1(Enemy1&& other) : Enemy(other) {}
    
    void update() override;

    void render() override;
};

class Enemy2 : public Enemy
{
    Enemy2() : Enemy() {}
    Enemy2(int X, int Y, char Symbol, SDL_Color Color, int Direction) : Enemy(X, Y, Symbol, Color, Direction) {}
    Enemy2(const Enemy1& other) : Enemy(other) {}
    Enemy2(Enemy1&& other) : Enemy(other) {}
    
    void update() override;

    void render() override;
};

class Enemy3 : public Enemy
{
    Enemy3() : Enemy() {}
    Enemy3(int X, int Y, char Symbol, SDL_Color Color, int Direction) : Enemy(X, Y, Symbol, Color, Direction) {}
    Enemy3(const Enemy1& other) : Enemy(other) {}
    Enemy3(Enemy1&& other) : Enemy(other) {}
    
    void update() override;

    void render() override;
};

class Enemy4 : public Enemy
{
    Enemy4() : Enemy() {}
    Enemy4(int X, int Y, char Symbol, SDL_Color Color, int Direction) : Enemy(X, Y, Symbol, Color, Direction) {}
    Enemy4(const Enemy1& other) : Enemy(other) {}
    Enemy4(Enemy1&& other) : Enemy(other) {}
    
    void update() override;

    void render() override;
};