#pragma once
#include "Entity.h"
#include<stdio.h> 
#include<stdlib.h> 

class Player : public Entity
{
private:
	bool Check_BCN_Input(std::string, std::string);
	void Validate_Input(Chain&);

protected:

public:
	Player();
	~Player();

	void SetChain();
	void My_Turn(std::string&);
	void Respond(Chain&, std::string&);
	bool Did_I_Lose();
};