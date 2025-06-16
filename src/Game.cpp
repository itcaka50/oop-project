#include "Game.h"
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;


Game::Game() : score(0), level(1), running(true), lives(3), player(Player(40, 20, 'A', GREEN, 3, 0))
{
    srand(static_cast<unsigned>(time(0)));
    initializeEnemies();
}

void Game::drawBorder() 
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // Top border
    for (int i = 1; i < 79; i++) 
    {  
        COORD top = { (SHORT)i, 0 };
        SetConsoleCursorPosition(hConsole, top);
        cout << ".";
    }
    // Bottom border 
    for (int i = 1; i < 79; i++) 
    {
        COORD bottom = { (SHORT)i, 23 };
        SetConsoleCursorPosition(hConsole, bottom);
        cout << ".";
    }
    // Side borders
    for (int i = 1; i < 23; i++) 
    {  
        COORD left = { 0, (SHORT)i };
        COORD right = { 79, (SHORT)i };
        SetConsoleCursorPosition(hConsole, left);
        cout << ".";
        SetConsoleCursorPosition(hConsole, right);
        cout << ".";
    }
    // rubovete
    COORD corners[4] = { {0,0}, {79,0}, {0,23}, {79,23} };
    for (auto pos : corners) 
    {
        SetConsoleCursorPosition(hConsole, pos);
        cout << ".";
    }
}

// ------------------------------------------------------------ ENEMYTATA 
void Game::initializeEnemies()
{
    for (int i = 0; i < level * 7; i++) 
    {
        int x = rand() % 70 + 5;
        int y = rand() % 5 + 1;
        int type = rand() % 4; // izbira random mejdu 4 enemyta

        switch (type)
        {
        case 0: enemies.push_back(new Enemy1(max(1, min(x, 78)), y, 'o', PINK, 1)); break;
        case 1: enemies.push_back(new Enemy2(max(1, min(x, 78)), y, '0', LIGHT_RED, 1)); break;
        case 2: enemies.push_back(new Enemy3(max(1, min(x, 78)), y, 'O', RED, 1)); break;
        case 3: enemies.push_back(new Enemy4(max(1, min(x, 78)), y, 'Q', BROWN, 1)); break;
        }
        // kolkoto po tumen e cveta i po slojna ikonkata - tolkova po silno e enemyto 
    }
}
// ------------------------------------------------------------ KLAVISHI

void Game::input() // klavishi za igracha 
{
    // ako e natisnato A - se dviji nalqvom, VAJNO ako se izpolzva na bg klaviatura ne raboti
    if (GetAsyncKeyState('A') & 0x8000 || GetAsyncKeyState(VK_LEFT) & 0x8000)
    {
        player.moveLeft();
    }

    // dviji se nadqsno, VAJNO ako se izpolzva na bg klaviatura ne raboti
    if (GetAsyncKeyState('D') & 0x8000 || GetAsyncKeyState(VK_RIGHT) & 0x8000)
    {
        player.moveRight();
    }

    static bool spacePressedLastFrame = false;

    // ako natiska space suzdava nov bullet
    if ((GetAsyncKeyState(VK_SPACE) & 0x8000) && !spacePressedLastFrame)
    {
        bullets.push_back(new Bullet(player.getX(), player.getY() - 1, '|', YELLOW, 1, true));
        spacePressedLastFrame = true;
    }
    else if (!(GetAsyncKeyState(VK_SPACE) & 0x8000))
    {
        spacePressedLastFrame = false;
    }

    // s escape izliza ot igrata
    if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
    {
        running = false;
    }
}
// ------------------------------------------------------------ RENDER
void Game::render() 
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    system("cls");

    drawBorder();

    SetConsoleTextAttribute(hConsole, GREEN);
    player.render();

    SetConsoleTextAttribute(hConsole, RED);
    for (int i = 0; i < enemies.size(); i++) 
    {
        enemies[i]->render();
    }

    SetConsoleTextAttribute(hConsole, YELLOW);
    for (int i = 0; i < bullets.size(); i++) 
    {
        bullets[i]->render();
    }

    // Draw enemy bullets
    SetConsoleTextAttribute(hConsole, RED);
    for (int i = 0; i < enemyBullets.size(); i++) 
    {
        if (enemyBullets[i]->getY() < 24) 
        {  
            enemyBullets[i]->render();
        }
    }

    SetConsoleTextAttribute(hConsole, 15);
    COORD status = { 0, 24 };
    SetConsoleCursorPosition(hConsole, status);
    cout << "Score: " << score << "    Level: " << level << "    Lives: " << lives;
}

void hideCursor()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

// ------------------------------------------------------------ UPDATE
void Game::update() 
{
    player.update();

    for (int i = 0; i < enemies.size(); i++) 
    {
        enemies[i]->update();
        if (rand() % 100 == 0) 
        {
            enemyBullets.push_back(new Bullet(enemies[i]->getX(), enemies[i]->getY() + 1, 'v', RED, 1, false));
        }
    }

    for (int i = 0; i < bullets.size(); i++) 
    {
        bullets[i]->update();
        if (bullets[i]->getY() <= 0) 
        {
            delete bullets[i];
            bullets[i] = nullptr;
        }
    }

    vector<GameObject*> newBullets;
    for (int i = 0; i < bullets.size(); i++) 
    {
        if (bullets[i] != nullptr) 
        {
            newBullets.push_back(bullets[i]);
        }
    }
    bullets = newBullets;

    for (int i = 0; i < enemyBullets.size(); i++) 
    {
        enemyBullets[i]->update();
        if (enemyBullets[i]->getY() >= 24) 
        {
            delete enemyBullets[i];
            enemyBullets[i] = nullptr;
        }
    }

    vector<GameObject*> newEnemyBullets;
    for (int i = 0; i < enemyBullets.size(); i++) 
    {
        if (enemyBullets[i] != nullptr) 
        {
            newEnemyBullets.push_back(enemyBullets[i]);
        }
    }
    enemyBullets = newEnemyBullets;

    checkCollisions();
}
// ------------------------------------------------------------ SBLUSUK

void Game::checkCollisions() 
{
    // Player bullets vs enemies
    for (int i = 0; i < bullets.size(); i++) 
    {
        for (int j = 0; j < enemies.size(); j++) 
        {
            if (bullets[i] && enemies[j] &&
                bullets[i]->getX() == enemies[j]->getX() &&
                bullets[i]->getY() == enemies[j]->getY()) 
            {

                Enemy* enemy = dynamic_cast<Enemy*>(enemies[j]);
                if (enemy) 
                {
                    score += enemy->getPoints();  
                }
                
                delete bullets[i];
                bullets[i] = nullptr;
                delete enemies[j];
                enemies[j] = nullptr;

                break;
            }
        }
    }

    // chisti enemyta
    vector<GameObject*> newEnemies;
    for (int i = 0; i < enemies.size(); i++) 
    {
        if (enemies[i] != nullptr) 
        {
            newEnemies.push_back(enemies[i]);
        }
    }
    enemies = newEnemies;

    // chisti kurshumi
    vector<GameObject*> newBullets;
    for (int i = 0; i < bullets.size(); i++) 
    {
        if (bullets[i] != nullptr) 
        {
            newBullets.push_back(bullets[i]);
        }
    }
    bullets = newBullets;

    // Enemy vs player collision
    for (int i = 0; i < enemies.size(); i++) 
    {
        if (enemies[i]->getX() == player.getX() &&
            enemies[i]->getY() == player.getY()) 
        {

            lives--;
            if (lives <= 0) 
            {
                for (int i = 0; i < bullets.size(); i++)
                {
                    delete bullets[i];
                }
                for (int i = 0; i < enemies.size(); i++)
                {
                    delete enemies[i];
                }
                for (int i = 0; i < enemyBullets.size(); i++)
                {
                    delete enemyBullets[i];
                }
                bullets.clear();
                enemies.clear();
                enemyBullets.clear();

                running = false;
                return;
            }

            // restartira nivoto ako si ocelen
            resetLevel();
            return;
        }
    }

    // Enemy bullets vs player
    for (int i = 0; i < enemyBullets.size(); i++) 
    {
        if (enemyBullets[i] &&
            enemyBullets[i]->getX() == player.getX() &&
            enemyBullets[i]->getY() == player.getY()) 
        {

            lives--;
            delete enemyBullets[i];
            enemyBullets[i] = nullptr;

            if (lives <= 0) 
            {
                for (int i = 0; i < bullets.size(); i++)
                {
                    delete bullets[i];
                }
                for (int i = 0; i < enemies.size(); i++)
                {
                    delete enemies[i];
                }
                for (int i = 0; i < enemyBullets.size(); i++)
                {
                    delete enemyBullets[i];
                }
                bullets.clear();
                enemies.clear();
                enemyBullets.clear();

                running = false;
                return;
            }

            // ako si ocelen restartira nivoto
            resetLevel();
            return;
        }
    }

    // kachva nivata
    if (score >= 100 && level == 1) 
    {
        nextLevel();
    }
    else if (score >= 200 && level == 2) 
    {
        nextLevel();
    }
    else if (score >= 500 && level == 3) 
    {
        for (auto& bullet : bullets) delete bullet;
        for (auto& enemy : enemies) delete enemy;
        for (auto& ebullet : enemyBullets) delete ebullet;
        bullets.clear();
        enemies.clear();
        enemyBullets.clear();

        // pri pobeda 
        system("cls");
        cout << "You've won! Final score: " << player.getScore() << endl;
        running = false;
    }
}


void Game::resetLevel() 
{
    for (int i = 0; i < bullets.size(); i++) 
    {
        delete bullets[i];
    }
    bullets.clear();

    for (int i = 0; i < enemies.size(); i++) 
    {
        delete enemies[i];
    }
    enemies.clear();

    for (int i = 0; i < enemyBullets.size(); i++) 
    {
        delete enemyBullets[i];
    }
    enemyBullets.clear();

    player = Player(40, 20, 'A', GREEN, player.getLives(), score);

    initializeEnemies();
}

// ------------------------------------------------------------ OTIVA NA SLEDVASHTO NIVO
void Game::nextLevel() 
{
    ++level;
    // pochistva pametta 
    for (auto bullet : bullets)
    {
        delete bullet;
    }
    for (auto enemy : enemies)
    {
        delete enemy;
    }
    for (auto eb : enemyBullets)
    {
        delete eb;
    }
    
    enemyBullets.clear();
    bullets.clear();
    enemies.clear();


    initializeEnemies(); // zadeystva funkciqta za slagane na novi enemyta za sledvashtoto nivo

    for (GameObject* obj : enemies) // uvelichava skorostta na enemytata s vsqko nivo
    {
        Enemy* enemy = dynamic_cast<Enemy*>(obj);
        if (enemy) 
        {
            enemy->setSpeed(enemy->getSpeed() + 1);
        }
    }

    system("cls"); // vizualizaciq za igracha che minava na next level
    cout << "Level " << level << "! Get ready..." << endl;
    Sleep(1500);
}

// ------------------------------------------------------------ RUNVANE NA IGRATA
void Game::run()
{
    startGameSound();
    hideCursor(); // dobavq skrivaneto na kursora
    drawBorder(); // risuva ramkata 

    while (running)
    {
        input();
        update();
        render();
        Sleep(100);
    }

    if (lives <= 0)
    {
        system("cls");
        cout << "Game Over! Final score: " << score << endl;
    }

    gameOverSound();

    for (auto bullet : bullets)
    {
        delete bullet;
    }
    for (auto enemy : enemies)
    {
        delete enemy;
    }
    for (auto eb : enemyBullets)
    {
        delete eb;
    }
    enemyBullets.clear();
    bullets.clear();
    enemies.clear();
}

void Game::startGameSound()
{
    Beep(880, 100);
    Beep(988, 100);
}

void Game::gameOverSound()
{
    Beep(600, 150);
    Beep(500, 150);
    Beep(400, 300);
}