#pragma once
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"


class Game 
{
private:
    Player player;
    std::vector<GameObject*> enemies;
    std::vector<GameObject*> bullets;
    int score, level;
    bool running;

public:
    Game() {}
    Game(Player Player, std::vector<GameObject*> Enemies, std::vector<GameObject*> Bullets, 
        int Score, int Level, bool Running) : 
        player(Player), enemies(Enemies), bullets(Bullets), 
        score(Score), level(Level), running(Running) {}
    
    Game(const Game& other) : player(other.player), enemies(other.enemies), bullets(other.bullets), score(other.score),
        level(other.level), running(other.running) {}

    Game(Game&& other);

    void initializeEnemies();

    void input();

    void update();

    void checkCollisions();

    void render();

    void run();
    
};