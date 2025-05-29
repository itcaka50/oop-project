#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>


class GameObject
{
protected:
    int x,y;
    char symbol;
    SDL_Color color;
public:
    GameObject() : x(0), y(0), symbol(NULL), color({0,0,0,0}) {}
    
    GameObject(int X, int Y, char Symbol, SDL_Color Color) : x(X), y(Y), symbol(Symbol), color(Color) {}

    GameObject(const GameObject& other) : x(other.x), y(other.y), symbol(other.symbol), color(other.color) {}

    GameObject(GameObject&& other);

    GameObject& operator=(const GameObject& other);

    GameObject& operator=(GameObject&& other);

    //napishi
    virtual void update();
    //napishi
    virtual void render();

    int getX();

    int getY();

    char getSymbol();

    SDL_Color getColor();

    void setX(int X);

    void setY(int Y);

    void setSymbol(char Symbol);

    void setColor(SDL_Color Color);

};