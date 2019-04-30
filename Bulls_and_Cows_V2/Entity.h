#pragma once

#include "Chain.h"
#include <iostream>

class Entity
{
protected:
	Chain my_chain;
	Chain my_guess;
	bool isMyTurn, I_Lost = false;

public:
	virtual void SetChain() = 0;
	virtual void My_Turn(std::string&) = 0;	//Take a guess at the sequence
	virtual void Respond(Chain&, std::string&) = 0; //Answers to guess
	virtual bool Did_I_Lose() = 0;
	Chain& Tell_My_Guess()
	{
		return my_guess;
	}
};