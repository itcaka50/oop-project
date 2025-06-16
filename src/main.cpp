#include "Game.h"
#include <Windows.h> // za beep

int main()
{
    Game game;
    game.startGameSound();
    game.run();
    game.gameOverSound();
    return 0;
}