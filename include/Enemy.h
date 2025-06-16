#pragma once
#include <iostream>
#include "GameObject.h"

class Enemy : public GameObject
{
protected:
int direction;
int speed = 1;
public:
Enemy() : GameObject() {};

Enemy(int X, int Y, char Symbol, COLORS Color, int Direction) : GameObject(X, Y, Symbol, Color), direction(Direction) {}

Enemy(const Enemy& other) : GameObject(other), direction(other.direction) {}

Enemy(Enemy&& other);

Enemy& operator=(const Enemy& other);

Enemy& operator=(Enemy&& other);

virtual void update() override;

virtual void render() override;

virtual int getPoints() const = 0;

int getSpeed() const { return speed; }
void setSpeed(int s) { speed = s; }
};

class Enemy1 : public Enemy
{
public: 
Enemy1() : Enemy() {}
Enemy1(int X, int Y, char Symbol, COLORS Color, int Direction) : Enemy(X, Y, Symbol, Color, Direction) {}
Enemy1(const Enemy1& other) : Enemy(other) {}
Enemy1(Enemy1&& other) : Enemy(other) {}

void update() override;
void render() override;
int getPoints() const override;
};
class Enemy2 : public Enemy
{
public:
Enemy2() : Enemy() {}
Enemy2(int X, int Y, char Symbol, COLORS Color, int Direction) : Enemy(X, Y, Symbol, Color, Direction) {}
Enemy2(const Enemy2& other) : Enemy(other) {}
Enemy2(Enemy2&& other) : Enemy(other) {}

void update() override;
void render() override;
int getPoints() const override;
};
class Enemy3 : public Enemy
{
public:
Enemy3() : Enemy() {}
Enemy3(int X, int Y, char Symbol, COLORS Color, int Direction) : Enemy(X, Y, Symbol, Color, Direction) {}
Enemy3(const Enemy3& other) : Enemy(other) {}
Enemy3(Enemy3&& other) : Enemy(other) {}

void update() override;
void render() override;
int getPoints() const override;
};
class Enemy4 : public Enemy
{
public:
Enemy4() : Enemy() {}
Enemy4(int X, int Y, char Symbol, COLORS Color, int Direction) : Enemy(X, Y, Symbol, Color, Direction) {}
Enemy4(const Enemy4& other) : Enemy(other) {}
Enemy4(Enemy4&& other) : Enemy(other) {}

void update() override;
void render() override;
int getPoints() const override;
};