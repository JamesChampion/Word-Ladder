// File Name: main.cpp
// Date: April 25,2020
// Course: EECS 2510-001
// Author: James Champion
// Description: Driver program to solve a word ladder.  Given a starting word and ending word, a word ladder is 
//				a sequence of valid words that have a hamming distance of 1 
//				Example (ape,man): ape-ale-all-aal-mal-man

#include "preCompilerHeader.h"
#include "WordLadder.h"

#pragma region Constants
unsigned int DICTIONARY_INDEX = 1;
unsigned int FIRST_WORD_LADDER_INDEX = 2;
unsigned int LAST_WORD_LADDER_INDEX = 3;
#pragma endregion

#pragma region ProtoTypes
bool isValidInput(const int& numberOfArguments, char* argumentArray[]);
#pragma endregion


int main(int numberOfArguments, char* argumentArray[])
{
	if (isValidInput(numberOfArguments, argumentArray))
	{
		std::string firstWord = argumentArray[FIRST_WORD_LADDER_INDEX];
		std::string lastWord = argumentArray[LAST_WORD_LADDER_INDEX];
		auto wordLadder = new WordLadder(argumentArray[DICTIONARY_INDEX], (int)firstWord.length());
		wordLadder->displayResult(wordLadder->getMinLadder(firstWord, lastWord));

	}
	else
	{
		// Invalid input. Return -1
		return -1;
	}
	return 0;
}

bool isValidInput(const int& numberOfArguments, char* argumentArray[])
{
	// Description: Validates user input.
	//				There needs to be 4 arguments, and words must be the same length.
	// Parameters: numberOfArguments <&int>, argumentArray <char*[]>
	// Returns:
	
	if (numberOfArguments != 4)
	{
		std::cout << "Invalid parameters \nExiting Program";
		return false;
	}

	std::string startingWord = argumentArray[FIRST_WORD_LADDER_INDEX];
	std::string endingWord = argumentArray[LAST_WORD_LADDER_INDEX];
	if (startingWord.length() != endingWord.length())
	{
		std::cout << "Words must be the same length \nExiting Program";
		return false;
	}

	return true;
}

