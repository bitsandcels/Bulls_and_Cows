#include "AI.h"
bool Is_BBBB(std::string message)
{
	bool areEqual;
	std::string BBBB = "BBBB";
	for (int i = 0; i < 4; ++i)
	{
		if (message[i] == BBBB[i])
		{
			areEqual = true;
		}
		else
		{
			areEqual = false;
			i = 4;
		}
	}

	return areEqual;
}

AI::AI()
{
	srand(time(0));

	Reset_Numbers_Vector();
}

AI::~AI()
{

}

void AI::Reset_Numbers_Vector()
{
	valid_numbers.clear();
	for (int i = 0; i < 10; ++i)
	{
		valid_numbers.push_back(i);
	}
}

int AI::Get_Number_From_Vector(int place)
{
	return valid_numbers[place];
}

void AI::Remove_Number_From_Vector(int num)
{
	for (int i = 0; i < valid_numbers.size(); ++i)
	{
		if (valid_numbers[i] == num)
		{
			valid_numbers.erase(valid_numbers.begin() + i);
			i = 10;
		}
	}
}

void AI::SetChain()
{
	for (int i = 0; i < 4; ++i)
	{
		int randPlace = rand() % valid_numbers.size();
		int randNum = Get_Number_From_Vector(randPlace);
		my_chain.SetChain(i, randNum);
		Remove_Number_From_Vector(randNum);
	}

}

void AI::Analyze_Response(std::string message)
{
	std::string type;

	for (int i = 0; i < 4; ++i)
	{
		type = message[i];
		Number_Cattle.Set_Value(type, i, my_guess.Get_Num(i));
	}
}

void AI::My_Turn(std::string &message)
{
	std::cout << "\n\nComputer's Turn.\n";
	Reset_Numbers_Vector();

	int number = 10;
	for (int i = 0; i < 4; ++i)
	{
		number = Number_Cattle.Get_Num_At(i);
		if (number == 10)
		{
			int randPlace = rand() % valid_numbers.size();
			number = Get_Number_From_Vector(randPlace);
			my_guess.SetChain(i, number);
			Remove_Number_From_Vector(number);
		}
		else
		{			
			my_guess.SetChain(i, number);
			Remove_Number_From_Vector(number);
		}

		number = 10;
	}

	Number_Cattle.Reset_Cows();

	message = my_guess.Get_Numbers_As_String();
	std::cout << "--> Computer guesses: " << message << "\n";
}

void AI::Respond(Chain &enemy_chain, std::string &message)
{
	message = my_chain.Compare_and_Answer(enemy_chain);
	std::cout << "--> Computer says: " << message << "\n";

	if (Is_BBBB(message))
	{
		I_Lost = true;
	}
}

bool AI::Did_I_Lose()
{
	return I_Lost;
}

void AI::PrintNumVector()
{
	for (int i = 0; i < valid_numbers.size(); ++i)
	{
		std::cout << valid_numbers[i] << " ";
	}
	std::cout << "\n\n";
}