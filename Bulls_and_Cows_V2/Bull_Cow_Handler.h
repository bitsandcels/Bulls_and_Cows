#pragma once

#include <vector>
#include <iostream>

struct Cow_Control
{
	int digit;
	bool places_been[4];
	bool just_used;

	Cow_Control(int num, int was_at)
	{
		//set all places_been to false
		for (int i = 0; i < 4; ++i)
		{
			places_been[i] = false;
		}

		//Now set digit to num and places_been to true at was_at
		digit = num;
		places_been[was_at] = true;
		just_used = false;
	}
};

class Bull_Cow_Handler
{
private:
	int Known_Bulls[4]; //Contains all known bulls and are saved in their corresponding places
	std::vector<Cow_Control> Known_Cows;

	//Does_Cow_Exist
	// Takes in a VALUE and checks through Known_Cows to determine if that value already exists
	// if it does, it returns its position in the list, else returns 10 and value does not exist
	int Does_Cow_Exist(int);

	//Find_Cow
	// Takes in an PLACE(int, base 0) and looks through all the elements in Known_Cows and returns the first cow
	// has not been at that PLACE
	int Find_Cow(int);

	//Promote_Cow_To_Bull
	// Takes a VALUE(int) that is a cow and removes it from Known_Cows and moves it to Known_Bulls
	// at PLACE(int, base 0)
	bool Can_Promote_Cow_To_Bull(int, int);

	//For testing purposes
	void PrintValues();

public:
	Bull_Cow_Handler();
	~Bull_Cow_Handler();

	int Get_Num_At(int);	//Return a bull or cow at a given place from 1-4

	//Set_Value
	// Takes in a (string) TYPE, where the passed values must be "B" or "C"
	// Takes in a PLACE (base 0) where the number should be located (for BULL) or was at (for COW)
	// with int VALUE
	void Set_Value(std::string, int, int);

	void Reset_Cows();
};