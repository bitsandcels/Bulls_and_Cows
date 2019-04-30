#pragma once
#include "AI.h"
#include "Player.h"

class Game_Manager
{
private:
	Game_Manager(const Game_Manager&);
	Game_Manager operator=(const Game_Manager&);

	AI ai;
	Player player;

public:
	Game_Manager();
	~Game_Manager();

	void RunGame();
};