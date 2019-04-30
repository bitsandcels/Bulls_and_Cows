#include "Bull_Cow_Handler.h"

Bull_Cow_Handler::Bull_Cow_Handler()
{
	for (int i = 0; i < 4; ++i)
	{
		Known_Bulls[i] = 10; //10 is an invalid-error number
	}

	Known_Cows.clear();
}

Bull_Cow_Handler::~Bull_Cow_Handler()
{
	Bull_Cow_Handler();
}

int Bull_Cow_Handler::Does_Cow_Exist(int value)
{
	if (Known_Cows.empty())
	{
		return 10;
	}

	for (auto i = begin(Known_Cows); i != end(Known_Cows); ++i)
	{
		if (i->digit == value)
		{
			return (std::distance(Known_Cows.begin(), i));
		}
	}

	return 10;
}

int Bull_Cow_Handler::Find_Cow(int place)
{
	if (Known_Cows.empty())
	{
		return 10;
	}

	for (auto i = begin(Known_Cows); i != end(Known_Cows); ++i)
	{
		if (i->places_been[place] == false && i->just_used == false)
		{
			i->just_used = true;
			return (std::distance(Known_Cows.begin(), i));
		}
	}

	return 10;
}

int Bull_Cow_Handler::Get_Num_At(int place)
{
	if (Known_Bulls[place] != 10)
	{
		return Known_Bulls[place];
	}
	
	int i = Find_Cow(place);
	if (i != 10)
	{
		Known_Cows[i].places_been[place] = true;
		return Known_Cows[i].digit;
	}

	return 10;
}

void Bull_Cow_Handler::Set_Value(std::string type, int place, int value)
{
	if (type == "B")
	{
		if (Known_Bulls[place] == 10)	//if there is no number at place, set it
		{
			if (!Can_Promote_Cow_To_Bull(place, value))		//If the value was already a cow, then move it to Known_Bulls and remove it
			{												//but if it wasn't, then just put it as cow
				Known_Bulls[place] = value;
			}
		}
	}
	if (type == "C")
	{
		int i = Does_Cow_Exist(value); //First, check to make sure the value is or isnt a cow
		if (i == 10)
		{
			Known_Cows.push_back(Cow_Control(value, place));
		}
		else
		{
			Known_Cows[i].places_been[place] = true;
		}
	}
}

bool Bull_Cow_Handler::Can_Promote_Cow_To_Bull(int place, int value)
{
	//First verify that the inserted value is a cow
	int i = Does_Cow_Exist(value);

	if (i != 10 && Known_Bulls[place] == 10)	//if it does exist and doesnt conflict with Known_Bulls, remove it and move it over to Known_Bulls
	{
		Known_Cows.erase(Known_Cows.begin() + i);
		Known_Bulls[place] = value;
		return true;
	}

	return false;
}

void Bull_Cow_Handler::PrintValues()
{
	std::cout << "**BULLS**\n";
	for (int i = 0; i < 4; ++i)
	{
		std::cout << "- " << Known_Bulls[i] << "\n";
	}

	std::cout << "\n\n**COWS**\n";

	if (Known_Cows.empty())
	{
		std::cout << "There are No Cows\n";
	}
	else
	{
		for (auto i = begin(Known_Cows); i != end(Known_Cows); ++i)
		{
			std::cout << "- " << i->digit << " and has been at: " << i->places_been[0] << i->places_been[1] <<
				i->places_been[2] << i->places_been[3] << "\n";
		}
	}

	std::cout << "\n\n";
}

void Bull_Cow_Handler::Reset_Cows()
{
	for (auto i = begin(Known_Cows); i != end(Known_Cows); ++i)
	{
		i->just_used = false;
	}
}