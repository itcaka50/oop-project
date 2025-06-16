#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include "GameObject.h"

class Player : public GameObject{
private:
    int lives;
    int score;

public:
    Player() {}
    Player(int X, int Y, char Symbol, COLORS Color, int Lives, int Score) : GameObject(X, Y, Symbol, Color), lives(Lives), score(Score) {}
    Player(Player& other);
    Player(Player&& other);
    void moveLeft();
    void moveRight();
    void shoot();
    void printStatus() const;
    int getScore() const;
    int getLives() const;
    Player& operator++(int);
    Player& operator--(int);
    void update() override;
    void render() override;
    void setLives();
    void setScore();
    Player& operator=(const Player& other);
};
