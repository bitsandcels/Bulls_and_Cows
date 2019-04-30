#include "Chain.h"

Chain::Chain()
{
	num1 = num2 = num3 = num4 = 10;	//invalid input, error numbers
}

Chain::Chain(int IN_num1, int IN_num2, int IN_num3, int IN_num4)
{
	num1 = IN_num1;
	num2 = IN_num2;
	num3 = IN_num3;
	num4 = IN_num4;
}

Chain::Chain(int IN_array[4])
{
	num1 = IN_array[0];
	num2 = IN_array[1];
	num3 = IN_array[2];
	num4 = IN_array[3];
}

Chain::Chain(const Chain &other)
{
	num1 = other.num1;
	num2 = other.num2;
	num3 = other.num3;
	num4 = other.num4;
}

Chain Chain::operator=(const Chain &other)
{
	num1 = other.num1;
	num2 = other.num2;
	num3 = other.num3;
	num4 = other.num4;
	
	return *this;
}

Chain::~Chain()
{

}

std::string Chain::Is_Num_BCN(int num, int place)
{
	// Check if number is Bull
	//For a number to be Bull, num must have the same value as num1-4 and be in the correct spot
	if (num == num1 && place == 1) return "B";
	if (num == num2 && place == 2) return "B";
	if (num == num3 && place == 3) return "B";
	if (num == num4 && place == 4) return "B";

	// ------------------------------------------------------------

	//Check if number is Cow
	//For a number to be Bull, num must have the same value as num1-4 and be in the wrong spot
	if (num == num1 && place != 1) return "C";
	if (num == num2 && place != 2) return "C";
	if (num == num3 && place != 3) return "C";
	if (num == num4 && place != 4) return "C";


	//Return neither if no condition is met
	return "N";
}

int Chain::Get_Num(int i)
{
	switch (i)
	{
	case 0:
		return num1;
		break;
	case 1:
		return num2;
		break;
	case 2:
		return num3;
		break;
	case 3:
		return num4;
		break;
	default:
		return 100; //ERROR or INVALID OPTION
		break;
	}
}

std::string Chain::Get_Numbers_As_String()
{
	std::string temp;
	temp += ((num1 == 10) ? "*" : std::to_string(num1));
	temp += ((num2 == 10) ? "*" : std::to_string(num2));
	temp += ((num3 == 10) ? "*" : std::to_string(num3));
	temp += ((num4 == 10) ? "*" : std::to_string(num4));
	return temp;
}

//-----------CheckDuplicates------------------------------
// Goes through all the numbers to check for a duplicate number and returns the place of the duplicate number
// Since it returns the last number that is a duplicate, check the chain starting the from end and work up.
// By the time it's done checking num2, there is no need to check num1 since the others have checked it.

// until there are no duplicates.
// Returns invalid number 0 if there are no duplicates, otherwise it returns the place where there is a duplicate number.
// It should never return 1 because it is the first number in the chain.
int Chain::CheckDuplicates()
{
	//Check if any match num4
	if (num4 == num3 || num4 == num2 || num4 == num1)
	{
		return 4;
	}

	//Check if any match num3
	if (num3 == num2 || num3 == num1)
	{
		return 4;
	}
	
	//Check if any match num2
	if (num2 == num1)
	{
		return 2;
	}

	//If all goes well, there should be no duplicates
	else
	{
		return 0;
	}
}

void Chain::SetChain(int place, int value)
{
	switch (place)
	{
	case 0:
		num1 = value;
		break;
	case 1:
		num2 = value;
		break;
	case 2:
		num3 = value;
		break;
	case 3:
		num4 = value;
		break;
	default:
		break;
	}
}

std::string Chain::Compare_and_Answer(Chain const &other)
{
	std::string Answer;

	//Check each number in other and determine if its B, C or N
	Answer += Is_Num_BCN(other.num1, 1);
	Answer += Is_Num_BCN(other.num2, 2);
	Answer += Is_Num_BCN(other.num3, 3);
	Answer += Is_Num_BCN(other.num4, 4);

	return Answer;
}