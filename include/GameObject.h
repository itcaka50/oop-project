#pragma once

#include <Windows.h>
#include "HelpRend.h"

class GameObject
{
public:
    GameObject() {}
    GameObject(int x, int y, char symbol, COLORS color);
    GameObject(const GameObject& other);
    GameObject(GameObject&& other);
    virtual ~GameObject() = default;

    int getX() const;
    int getY() const;
    char getSymbol() const;
    int getColor() const;

    void setPosition(int newX, int newY);
    void setColor(COLORS Color);
    void setSymbol(char Symbol);

    virtual void render() = 0; 

    virtual void update() = 0;

    GameObject& operator=(const GameObject& other);
    GameObject& operator=(GameObject&& other);


protected:
    int x;
    int y;
    char symbol;
    COLORS color;
};