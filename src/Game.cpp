#include "Game.h"

Game::Game(Game&& other) : player(other.player), enemies(other.enemies), bullets(other.bullets), score(other.score),level(other.level), running(other.running)
{
    other.player = Player();
    other.enemies = std::vector<GameObject*>();
    other.bullets = std::vector<GameObject*>();
    other.score = 0;
    other.level = 0;
    other.running = false;
}

void Game::initializeEnemies()
{

}

void input()
{

}

void update()
{

}

void checkCollisions()
{

}

void render()
{

}

void run()
{

}