#pragma once
#include <iostream>
#include "GameObject.h"

class Bullet : public GameObject {
public:
    Bullet() {}
    Bullet(int X, int Y, char Symbol, COLORS Color, int Speed, bool IPB) : GameObject(X, Y, Symbol, Color), speed(Speed), isPlayerBullet(IPB) {}
    Bullet(const Bullet& other);
    Bullet(Bullet&& other);
    void update() override;   
    void render() override;
    int getSpeed() const;   
    bool isOffScreen() const; 
    void setSpeed(int Speed); 
private:
    int speed;
    bool isPlayerBullet;
};
