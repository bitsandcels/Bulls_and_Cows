#pragma once
#include <iostream>
#include <string>

class Chain
{
private:
	//Chain Number variables
	int num1, num2, num3, num4;

	Chain(const Chain&);
	Chain operator= (const Chain&);

	//Is_Num_BCN
	// Determines whether an input number is Bull (B), Cow (C) or N (neither)
	// at a given place and returns the corresponding letter
	std::string Is_Num_BCN(int, int);

public:
	Chain();
	Chain(int, int, int, int);
	Chain(int[4]);

	~Chain();

	//Return_Single_Num
	//Returns a select number between 1 - 4
	int Get_Num(int);

	//Return numbers as a string
	std::string Get_Numbers_As_String();

	//CheckDuplicates ----------------
	// Checks self to see if there are any duplicated numbers
	// If there is a duplicate in the sequence, it will return
	// the 1st duplicate number. Valid numbers are 2-4 corresponding
	// with the num1-num4 varriables.
	// If there are no duplicates, it returns 0 (an invalid number)
	int CheckDuplicates();

	//SetChain --------------------
	// Set a number at place (0-3) with value (0-9)
	void SetChain(int, int);

	//Compare_and_Answer
	// Looks at a chain, compares values and responds with XXXX
	// where each X can be either B, C, or N
	// - B: Correct Number, correct place
	// - C: Correct Number, wrong place
	// - N: Number is not in sequence
	std::string Compare_and_Answer(const Chain&);
};