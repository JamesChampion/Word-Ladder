// File Name: WordLadder.cpp
// Date: April 26,2020
// Course: EECS 2510-001
// Author: James Champion
// Description: Implementation of WordLadder.h
//				Given a starting word and ending word, a word ladder is 
//				a sequence of valid words that have a hamming distance of 1 
//				Example (ape,man): ape-ale-all-aal-mal-man

#include "preCompilerHeader.h"
#include "WordLadder.h"

#pragma region PublicMethods

WordLadder::WordLadder(const string& dictionaryFilePath, const int& lengthOfWord)
{
	// Read File and only add the words of the same length.
	intializeDictionary(dictionaryFilePath, lengthOfWord);
}


vector<string> WordLadder::getMinLadder(string& startingWord, string& endingWord)
{

	struct WordLadderNode
	{
		// Local Struct used to easily map predecessors with words.
		string key;
		WordLadderNode* predecessor;
		inline WordLadderNode()
		{
			key = string();
			predecessor = nullptr;
		}
		inline WordLadderNode(string k, WordLadderNode* predecessorNode)
		{
			key = k;
			predecessor = predecessorNode;
		}

	};

	startingWord = convertToUpperCase(startingWord); // The words need to be upper case because the dictionaries are all in upper case
	endingWord = convertToUpperCase(endingWord);

	if (!isWord(startingWord) || !isWord(endingWord)) // If the words are not valid
	{
		return vector<string>(); // return an empty set
	}

	vector<string> minimumLadder, wordsSeenList;
	list<string> queue;
	vector<WordLadderNode*> wordLadderMap;
	queue.push_front(startingWord); // Push the starting word in the queue
	wordsSeenList.push_back(startingWord); // Flag as 'We've seen it'
	wordLadderMap.push_back(new WordLadderNode(startingWord, new WordLadderNode())); // Push that word on the map.
	while (!queue.empty())
	{
		string QFront = queue.front();
		queue.pop_front();
		int wordSeenIndex = this->findInVector(wordsSeenList, QFront); // Need the index for the map to get the predecessor pointer
		auto QFrontNode = wordLadderMap[wordSeenIndex];
		set<string> neighborList = this->getNeighbors(QFront);

		for (auto neighbor : neighborList) // for each neighbor
		{
			if (findInVector(wordsSeenList, neighbor) == -1) // If we havent seen the word before
			{
				wordLadderMap.push_back(new WordLadderNode(neighbor, QFrontNode)); // Map it's predecessor
				wordsSeenList.push_back(neighbor); // Mark as seen
				queue.push_back(neighbor); // Push on to the queue
				if (neighbor == endingWord) // We found it
				{
					auto node = wordLadderMap.back();
					while (node->predecessor != nullptr) // Grab all the words and their predecessors
					{
						minimumLadder.push_back(node->key);
						node = node->predecessor;
					}
					return minimumLadder;
				}
			}
		}
	}
	return vector<string>(); // The queue is empty and we've exahusted our options.  Return an empty vector
}

int WordLadder::getWordCount()
{
	return (int)this->dictionary.size();
}

void WordLadder::displayResult(const vector<string>& sequence)
{

	if (sequence.size() == 0) // if the parameter is empty, there is no word ladder
	{
		cout << "Word Ladder is empty - No Solution";
		return;
	}

	int numberOfSteps = (int)sequence.size() - 1;
	cout << "A Shortest Word Ladder (" << numberOfSteps << " steps) is: ";
	for (int i = (int)sequence.size() - 1; i >= 0; i--)
	{
		cout << sequence[i] << (i == 0 ? "" : " ");
	}

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
		cout << "File path not found.\nExiting Program"; // This should really throw an exception
		exit(-1);
	}
}

int WordLadder::findInVector(const vector<string>& vector, const string& inputString)
{
	unsigned int i = 0;
	for (auto word : vector)
	{
		if (word == inputString)
		{
			return i;
		}
		i++;
	}

	return -1;
}


bool WordLadder::isWord(const string& inputString)
{
	// Validates if the inputString is a validWord
	return this->dictionary.find(inputString) != this->dictionary.end();
}


bool WordLadder::isWordLadder(const vector<string>& sequence)
{
	// May want to iterate through each of these words, and make sure that 
	// Checks to see if the given sequence is a valid word ladder
	for (size_t i = 0; i < sequence.size(); i++) // Using a size_t variable here because of the sequece.. sequence{type size_t]
	{
		if (i == sequence.size() - 1) // If it's the last index of the sequence, only check to see if its a word
		{
			if (!isWord(sequence[i]))
			{
				return false;
			}
			break;
		}
		if (!isWord(sequence[i]) || (getHammingDistance(sequence[i], sequence[i + 1]) != 1)) // If its not a word, or the hamming distance is not 1, it can't be a word ladder
		{
			return false;
		}
	}
	return true;
}

set<string> WordLadder::getNeighbors(const string& word)
{
	// Go through the dictionary and grab all the neighors (Hamming distance = 1)
	auto neighborSet = set<string>();
	for (auto dictionaryWord : this->dictionary)
	{
		int hammingDistance = getHammingDistance(word, dictionaryWord);
		if (hammingDistance == 1)
		{
			neighborSet.insert(dictionaryWord);
		}
	}
	return neighborSet;
}

int WordLadder::getHammingDistance(const string& string1, const string& string2)
{
	if (string1.length() != string2.length()) // If the strings are not the same lenght, hamming distance is -1
	{
		return -1;
	}

	unsigned int hammingDistance = 0;

	for (unsigned int i = 0; i < string1.length(); i++)
	{
		if (string1[i] != string2[i])
		{
			hammingDistance++; // Increase hamming distance everytime a letter at the same index differs
		}
	}
	return hammingDistance;
}

string WordLadder::convertToUpperCase(string& inputString)
{
	for (auto& character : inputString) // foreach character in the inputstring
	{
		character = toupper(character);
	}
	return inputString;
}


#pragma endregion

