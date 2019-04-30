#include "Player.h"

bool Are_All_Digits(std::string input)
{
	for (int i = 0; i < input.size(); ++i)
	{
		if (!isdigit(input[i]))
		{
			return false;
		}
	}

	return true;
}

Player::Player()
{

}

Player::~Player()
{

}

bool Player::Check_BCN_Input(std::string Player_Input, std::string Chain_Input)
{
	bool areEqual;
	
	if (Player_Input.length() != 4)
	{
		areEqual = false;
	}
	else
	{
		for (int i = 0; i < 4; ++i)
		{
			if (Chain_Input[i] == Player_Input[i])
			{
				areEqual = true;
			}
			else
			{
				areEqual = false;
				i = 4;
			}
		}
	}

	return areEqual;
}

void Player::SetChain()
{
	std::cout << "--> Let's get started. \n";
	std::cout << "--> You need to make a chain. So...\n";
	Validate_Input(my_chain);
}

void Player::Validate_Input(Chain &Which_Chain)
{
	std::string input;
	bool setInput = true;

	while (setInput)
	{
		std::cout << "--> Enter a 4 digit number: ";
		std::cin >> input;

		std::cout << "\n";
		if (std::cin.fail())
		{
			std::cout << "--> Sorry, I couldn't get that. Try again and only use numbers 0-9.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (input.size() != 4 || !Are_All_Digits(input))
		{
			std::cout << "--> Sorry, you need 4 numbers. Please try again.\n";
		}
		else
		{
			std::string value;
			for (int i = 0; i < 4; ++i)
			{
				value = input[i];
				Which_Chain.SetChain(i, std::stoi(value));
			}

			if (Which_Chain.CheckDuplicates() != 0)
			{
				std::cout << "--> Don't repeat the same numbers. Try again.\n";

			}
			else
			{
				setInput = false;
			}
		}
	}
}

void Player::My_Turn(std::string &message)
{
	std::cout << "\n\nYour turn!\n";
	std::cout << "--> Take a guess.\n";
	Validate_Input(my_guess);

	message = my_guess.Get_Numbers_As_String();
}

void Player::Respond(Chain &enemy_chain, std::string &message)
{
	std::cout << "--> Your chain is: " << my_chain.Get_Numbers_As_String() << "\n\n";

	std::string input;
	std::cout << "--> Enter Response: ";
	std::cin >> input;

	std::string Verify_BCN = my_chain.Compare_and_Answer(enemy_chain);

	while (!Check_BCN_Input(input, Verify_BCN))
	{
		std::cout << "--> Careful now. Enter a valid response. \n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "--> Enter Response: ";
		std::cin >> input;
		std::cout << "\n";
	}

	message = input;

	if (Check_BCN_Input(input, "BBBB"))
	{
		I_Lost = true;
	}
}

bool Player::Did_I_Lose()
{
	return I_Lost;
}