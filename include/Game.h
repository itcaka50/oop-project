#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include <vector>

class Game
{
private:
Player player;

std::vector<GameObject*> enemies;
std::vector<GameObject*> bullets;
std::vector<GameObject*> enemyBullets;


int score;
int level;
bool running;
int lives;
public:
Game();

void initializeEnemies();
void input(); 
void render();
void update();
void checkCollisions(); 
void nextLevel(); 
void run(); 
void drawBorder(); 
void startGameSound();
void gameOverSound(); 
void resetLevel(); 
};