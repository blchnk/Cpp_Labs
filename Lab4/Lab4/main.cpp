#include <iostream>
#include <windows.h>
#include "Card.h"
#include "Deck.h"
#include "Game.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    Game* game = new Game(4, 25, 500);
    game->Play();
    system("pause");
    return 0;
}