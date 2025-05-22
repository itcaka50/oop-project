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

    Player(Player& other) {}

    Player(Player&& other) {}

    Player& operator=(const Player& other);

    Player& operator=(Player&& other);
    //napishi
    void moveRight();
    //napishi
    void moveLeft();
    //napishi
    void shoot();

    void getLives();

    void getScore();

    void setLives(int Lives);

    void setScore(int Score);

    //napishi
    void operator+();

    //napishi
    void operator-();
};