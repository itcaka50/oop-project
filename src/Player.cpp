#include "Player.h"

    Player::Player(Player&& other) : GameObject(other), lives(other.lives), score(other.score)
    {
        other.x = 0;
        other.y = 0;
        other.symbol = NULL;
        other.color = {0,0,0,0};
        other.lives = 0;
        other.score = 0;
    }

    Player& Player::operator=(const Player& other)
    {
        if(this != &other)
        {
            this->x = other.x;
            this->y = other.y;
            this->symbol = other.symbol;
            this->color = other.color;
            this->lives = other.lives;
            this->score = other.score;
        }
        return *this;
    }

    Player& Player::operator=(Player&& other)
    {
        if(this != &other)
        {
            this->x = other.x;
            this->y = other.y;
            this->symbol = other.symbol;
            this->color = other.color;
            this->lives = other.lives;
            this->score = other.score;

            other.x = 0;
            other.y = 0;
            other.symbol = NULL;
            other.color = {0,0,0,0};
            other.lives = 0;
            other.score = 0;    
        }
        return *this;
    }
    
    void Player::moveRight() 
    {
        //primerno
        if (x != 500) //500 e random chislo, x ne trqbva da minava prez dqsnata stena, kato se razbere kolko e golqma duljinata na prozoreca sh se smeni
        x += 1;
    }

    void Player::moveLeft()
    {
        if (x != 0)
        x -=1;
    }

    void Player::shoot() {}

    int Player::getLives() const
    {
        return lives;
    }

    int Player::getScore() const 
    {
        return score;
    }

    void Player::setLives(int Lives) 
    {
        lives = Lives;
    }

    void Player::setScore(int Score)
    {
        score = Score;
    }

    void Player::update()
    {

    }

    void Player::render()
    {
        
    }

    void Player::operator+()
    {
        lives++;
    }

    void Player::operator-()
    {
        lives--;
    }