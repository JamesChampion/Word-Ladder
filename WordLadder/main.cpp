#include "preCompilerHeader.h"
#include "WordLadder.h"

#pragma region Constants
unsigned int DICTIONARY_INDEX = 1;
unsigned int FIRST_WORD_LADDER_INDEX = 2;
unsigned int LAST_WORD_LADDER_INDEX = 3;
#pragma endregion

#pragma region ProtoTypes
bool isValidInput(int& numberOfArguments, char* argumentArray[]);
#pragma endregion


int main(int numberOfArguments, char* argumentArray[])
{
	if (isValidInput(numberOfArguments, argumentArray))
	{
		std::string firstWord = argumentArray[FIRST_WORD_LADDER_INDEX];
		auto wordLadder = new WordLadder(argumentArray[DICTIONARY_INDEX], firstWord.length());
		
	}
	else
	{
		// Invalid input. Return -1
		return -1;
	}
	return 0;
}

bool isValidInput(int& numberOfArguments, char* argumentArray[])
{

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

