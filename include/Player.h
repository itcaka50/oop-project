#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include "GameObject.h"

class Player : public GameObject
{
private:
    int lives;
    int score;
public:
    Player() : GameObject(), lives(0), score(0) {}

    Player(int X, int Y, char Symbol, SDL_Color Color, int Lives, int Score) : GameObject(X, Y, Symbol, Color), lives(Lives), score(Score) {}

    Player(const Player& other) : GameObject(other), lives(other.lives), score(other.score) {}

    Player(Player&& other) {}

    Player& operator=(const Player& other);

    Player& operator=(Player&& other);
    //napishi
    void moveRight();
    //napishi
    void moveLeft();
    //napishi
    void shoot();

    int getLives() const;

    int getScore() const;

    void setLives(int Lives);

    void setScore(int Score);

    void operator+();

    void operator-();
    //napishi
    void update() override;
    //napishi
    void render() override;
};