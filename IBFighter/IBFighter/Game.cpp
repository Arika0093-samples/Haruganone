#include "Game.h"

Game::Game(SIZE data)
{
	status = G_INIT;
	screen = data;
}
int Game::GetStatus()
{
	return status;
}
void Game::SetStatus(int data)
{
	status = data;
}