#include "Player.h"

    Player::Player(Player& other)
    {
        
    }

    Player::Player(Player&& other) 
    {

    }

    Player& Player::operator=(const Player& other)
    {

    }

    Player& Player::operator=(Player&& other)
    {

    }
    
    void moveRight();

    void moveLeft();

    void shoot();

    void getLives();

    void getScore();

    void setLives();

    void setScore();