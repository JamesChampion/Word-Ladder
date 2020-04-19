#include "preCompilerHeader.h"
#include "WordLadder.h"


#pragma region PublicMethods

WordLadder::WordLadder(const string& dictionaryFilePath, const int& lengthOfWord)
{
	// Read File and only add the words of the same length.
	intializeDictionary(dictionaryFilePath, lengthOfWord);

}

vector<string> WordLadder::getMinimumLadder(const string& start, const string& end)
{
	// Returns the Vector with the minimum ladder, or an empty vector
	return vector<string>();
}

int WordLadder::getWordCount()
{
	return 0;
}

void WordLadder::displayResult(const vector<string>& sequence)
{
	// Displays the word ladder in format
	// Ex. A Shortest Word Ladder (6 Steps) is: word1 word2 word3
	// Or
	// Word Ladder is empty - No Solution
	// This must be exact.
}


#pragma endregion



#pragma region PrivateMethods

void WordLadder::intializeDictionary(const string& dictionaryFilePath, const int& lengthOfWord)
{
	ifstream dictionaryFile(dictionaryFilePath);
	string word;
	if (dictionaryFile)
	{
		while (dictionaryFile >> word)
		{
			if (word.length() == lengthOfWord)
			{
				this->dictionary.insert(word);
			}
		}
	}
	else
	{
		cout << "File path not found.\nExiting Program";
		exit(-1);
	}
}

int WordLadder::findInVector(const vector<string>& vector, const string& inputString)
{
	// Returns the postion in the vector that the string is found
	// Returns -1 if not found
	return 0;
}

bool WordLadder::isWord(const string& inputString)
{
	// Validates if the inputString is a validWord
	return false;
}

bool WordLadder::isWordLadder(const vector<string>& sequence)
{
	// Checks to see if the given sequence is a valid word ladder
	return false;
}

set<string> WordLadder::getNeighbors(const string& word)
{

	return set<string>();
}

int WordLadder::getHammingDistance(const string& string1, const string& string2)
{
	// Returns the hamming difference.
	// If for some reason the strings are different length (which they wont be)
	// this returns -1
	return 0;
}

#pragma endregion

