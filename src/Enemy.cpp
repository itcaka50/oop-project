#include "Enemy.h"
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

Enemy::Enemy(Enemy&& other) : GameObject(other), direction(other.direction)
{
	other.x = 0;
	other.y = 0;
	other.symbol = NULL;
	other.color = BLACK; //defaulten cvqt
	other.direction = 0;
}
Enemy& Enemy::operator=(const Enemy& other)
{
	if (this != &other)
	{
		this->x = other.x;
		this->y = other.y;
		this->symbol = other.symbol;
		this->color = other.color;
		this->direction = other.direction;
	}
	return *this;
}
Enemy& Enemy::operator=(Enemy&& other)
{
	if (this != &other)
	{
		this->x = other.x;
		this->y = other.y;
		this->symbol = other.symbol;
		this->color = other.color;
		this->direction = other.direction;

		other.x = 0;
		other.y = 0;
		other.symbol = NULL;
		other.color = BLACK;
		other.direction = 0;
	}
	return *this;
}

void Enemy::update() 
{
	if (rand() % (100 / speed) == 0)
	{
		y += 1; // dviji se bavno nadolu
	}

	if (y > 24) // slagam mu limit za ekrana
	{
		y = 24; 
	}

	if (rand() % 1000 == 0) { } // strelq rqdko
}

void Enemy::render()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	SetConsoleCursorPosition(hConsole, pos);
	cout << static_cast<char>(symbol);
}

void Enemy1::render() 
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color); // za da izpolzva cveta podaden v game.cpp
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) }; 
	SetConsoleCursorPosition(hConsole, pos);
	std::cout << static_cast<char>(symbol); // za da izpolzva simvola podaden v game
}
void Enemy1::update()
{
	Enemy::update(); // samo se dviji nadolu bavno
}
void Enemy2::render()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	SetConsoleCursorPosition(hConsole, pos);
	std::cout << static_cast<char>(symbol);
}
void Enemy2::update()
{
	static int frameCount = 0;
	frameCount++;
	if (frameCount % 3 != 0) return;

	x += direction;
	if (x <= 1 || x >= 78) 
	{
		direction *= -1;
		y++;
	}
}
void Enemy3::render()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	SetConsoleCursorPosition(hConsole, pos);
	std::cout << static_cast<char>(symbol);
}
void Enemy3::update() 
{
	static int frameCount = 0;
	frameCount++;
	if (frameCount % 3 != 0) return;

	if (y % 2 == 0) {
		x += 1;
	}
	else {
		x -= 1;
	}

	if (x <= 1 || x >= 78) {
		direction *= -1;
	}

	x = max(1, min(x, 78));

	// zabavq slizaneto nadolu
	if (rand() % 150 == 0) {
		y++;
	}
}
void Enemy4::render()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	SetConsoleCursorPosition(hConsole, pos);
	std::cout << static_cast<char>(symbol);
}
void Enemy4::update() 
{
	if (rand() % 50 == 0) 
	{
		x = rand() % 77 + 1;
		y++;
	}
	else if (rand() % 100 == 0) 
	{
		y++;
	}
}

int Enemy1::getPoints() const 
{
	return 10;
}
int Enemy2::getPoints() const
{
	return 20;
}
int Enemy3::getPoints() const
{
	return 30;
}
int Enemy4::getPoints() const
{
	return 40;
}