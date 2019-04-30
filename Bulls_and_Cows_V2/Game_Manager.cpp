#include "Game_Manager.h"

Game_Manager::Game_Manager()
{

}

Game_Manager::Game_Manager(const Game_Manager &other)
{

}

Game_Manager Game_Manager::operator=(const Game_Manager &other)
{
	return *this;
}

Game_Manager::~Game_Manager()
{

}

void Game_Manager::RunGame()
{
	/*
	----------------------------------------------------------------------------------
	--								GAME LOOP										--
	----------------------------------------------------------------------------------
		SETUP
	i. Player enters chain (4 numbers, non-repeats, 0-9 only
	ii. Computer says they are ready
		START LOOP
	1. Player inputs 4 number chain
	2. Computer responds with Bulls, Cows, Neither (B, C, N)
		2a. Determine if guess was successful (end game if it did)
	3. Computer guesses 4 number chain
	4. Player responds with Bulls, Cows, Neither (B, C, N)
		4a. Determine if guess was successful (end game if it did)
		4b. Computer stores BCN and Computer's guess
	
	Repeat 1-4 until one responds "BBBB" response to end loop

	*/

	
	//SETUP
	player.SetChain();		// -- i
	ai.SetChain();			// -- ii

	std::string message;
	bool playGame = true;

	//GAME LOOP
	while (playGame)
	{
		player.My_Turn(message);						// -- 1

		ai.Respond(player.Tell_My_Guess(), message);	// -- 2
		if (ai.Did_I_Lose())							// -- 2a
		{
			std::cout << "\n\n*****************************************\n"
				<< "                 YOU WIN                  \n"
				<< "*****************************************\n";
			playGame = false;
			break;
		}

		ai.My_Turn(message);							// -- 3

		player.Respond(ai.Tell_My_Guess(), message);	// -- 4
		if (player.Did_I_Lose())							// -- 4a
		{
			std::cout << "\n\n--------------------------------------------\n"
				<< "                 you lose..                  \n"
				<< "--------------------------------------------\n";
			playGame = false;
			break;
		}
		ai.Analyze_Response(message);					// -- 4b
	}
}