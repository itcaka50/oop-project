#include "Bullet.h"


Bullet::Bullet(const Bullet& other) : GameObject(other), speed(other.speed), isPlayerBullet(isPlayerBullet) {}

Bullet::Bullet(Bullet&& other) : GameObject(other), speed(other.speed), isPlayerBullet(other.isPlayerBullet)
{
    other.speed = 0;
    isPlayerBullet = false;
}

void Bullet::update() {
    if (isPlayerBullet) {
        y--;  
    }
    else {
        y++;  
    }
}

bool Bullet::isOffScreen() const {
    return y < 0;
}

int Bullet::getSpeed() const {
    return speed;
}

void Bullet::setSpeed(int newSpeed) {
    if (newSpeed >= 0) 
    { 
        speed = newSpeed;
    }
}

void Bullet::render()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    SetConsoleCursorPosition(hConsole, pos);
    cout << static_cast<char>(symbol);
}