#include "Player.h"
#include <iostream>


void Player::moveLeft() {
    if (x > 1)
    {
        x--;
    }  
}

void Player::moveRight() {
    if (x < 78) 
    { 
        x++; 
    }
}

void Player::shoot() {
    std::cout << "Player shoots!\n";
}


void Player::printStatus() const {
    std::cout << "Player Position: (" << x << ", " << y << ") | Lives: " << lives << " | Score: " << score << std::endl;
}

int Player::getScore() const {
    return score;
}

int Player::getLives() const
{
    return lives;
}

Player& Player::operator++(int)
{
    lives++;
    return *this;
}

Player& Player::operator--(int)
{
    lives--;
    return *this;
}

Player& Player::operator=(const Player& other)
{
    if (this != &other)
    {
        x = other.x;
        y = other.y;
        symbol = other.symbol;
        color = other.color;
        lives = other.lives;
        score = other.score;
    }
    return *this;
}

void Player::render()
{
    if (y < 23)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
        SetConsoleCursorPosition(hConsole, pos);
        cout << static_cast<char>(symbol);
    }
}

void Player::update()
{
    this->render();
}