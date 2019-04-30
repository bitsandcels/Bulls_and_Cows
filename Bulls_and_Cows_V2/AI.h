#pragma once

#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_cloc
#include "Entity.h"
#include "Bull_Cow_Handler.h"

class AI : public Entity
{
private:
	
	std::vector<int> valid_numbers;	//A list of numbers the AI can use when guessing

	void Reset_Numbers_Vector();
	int Get_Number_From_Vector(int);

	//For testing
	void PrintNumVector();

	//Remove_Number_From_Vector
	// Removes the number equivalent to PARAM (values 0-9)
	void Remove_Number_From_Vector(int);

	Bull_Cow_Handler Number_Cattle;		//Cause they are Bulls and Cows, yet numbers...

protected:

public:
	AI();
	~AI();

	void SetChain();
	void My_Turn(std::string&);
	void Respond(Chain&, std::string&);
	bool Did_I_Lose();

	void Analyze_Response(std::string);
};