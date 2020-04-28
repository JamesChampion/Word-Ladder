#include "preCompilerHeader.h"
#pragma once

//
// WordLadder.h Defines an interface for games that construct word ladders.
// See https://en.wikipedia.org/wiki/Word_ladder for a definition and history.
// 
// Word ladders are constructed in the context of some predefined list of valid words. We will refer to
// this word list as the lexicon. An implementing class of this header must provide a way to explicitly
// set the lexicon. This will typically be done in the constructor.
// 
// For the purposes of this interface and all implementing classes, a string is a word if and only if it 
// appears in the current lexicon. In the documentation of each instance method, the use of 'string' means 
// that the referenced string does not have to be a word, while the use of 'word' implies that the
// referenced string must be a word.
// 
// Originally written as a Java project by Dean Hentrix (dh@auburn.edu)
// 
// Converted to a C++ project by Larry Thomas, University of Toledo (Larry.Thomas@UToledo.edu) 4/18/2020
// 

using namespace std;

class WordLadder
{
public:

	//---------------------------------------------------------------------------------------------
	// Constructor to set up the game -- basically consists of just loading the lexicon (dictionary)
	// 
	// In order to help with efficiency, we keep only the words with the specified length
	// 
	WordLadder(const string& dictionaryFilePath, const int& lengthOfWord);

	//---------------------------------------------------------------------------------------------
	// Returns a minimum-length word ladder from start to end. If multiple minimum-length
	// word ladders exist, no guarantee is made regarding which one is returned. If no word
	// ladder exists, this method returns an empty list.
	//
	// Breadth-first search must be used to implement this method.
	//
	// start    the starting word
	// end      the ending word
	// returns  a minimum length word ladder from start to end
	//

	vector<string> getMinLadder(string& startingWord, string& endingWord);

	//---------------------------------------------------------------------------------------------
	// Returns the total number of words in the current lexicon.
	//
	// returns number of words in the lexicon
	//
	int getWordCount();


	//---------------------------------------------------------------------------------------------
	//  Used to display the result, whether empty, or a valid WordLadder
	//
	void displayResult(const vector<string>& sequence);


private:

	set<string> dictionary; 


	// Description: Initalizes the dictionary used to look up valid words.  This dictionary only stores words of the same length as input parameters
	// Parameters: dictionaryFilePath <string&> lengthOfWord <int&>
	// Returns: void
	void intializeDictionary(const string& dictionaryFilePath, const int& lengthOfWord);

	//---------------------------------------------------------------------------------------------
	// Returns the location within the vector of the given string; returns -1 if not found
	//
	//
	int findInVector(const vector<string>& vector, const string& word);


	//---------------------------------------------------------------------------------------------
	// Checks to see if the given string is a word.
	// 
	// inputString      the string to check
	// returns  true if inputString is in the dictionary, false otherwise
	// 
	bool isWord(const string& inputString);

	//---------------------------------------------------------------------------------------------
	// Checks to see if the given sequence of strings is a valid word ladder.
	//
	// sequence   the given sequence of strings
	// returns    true if the given sequence is a valid word ladder, false otherwise
	//
	bool isWordLadder(const vector<string>& sequence);


	//---------------------------------------------------------------------------------------------
	// Returns all the words that have a Hamming distance of one relative to the given word.
	//
	// word:     the given word
	// returns:  the neighbors of the given word
	//
	set<string> getNeighbors(const string& word);


	//---------------------------------------------------------------------------------------------
	// Returns the Hamming distance between two strings, str1 and str2. The Hamming distance between two
	// strings of equal length is defined as the number of positions at which the corresponding symbols
	// are different. The Hamming distance is undefined if the strings have different lengths, and this
	// method must return -1 in that case. See https://en.wikipedia.org/wiki/Hamming_distance for more
	//
	// string1    the first string
	// string2    the second string
	// returns the Hamming distance between str1 and str2 if they are the same length, -1 otherwise
	//
	int getHammingDistance(const string& string1, const string& string2);

	// Description: Converts a word to upper case
	// Parameters: inputString<string&>
	// Returns: Uppercase string <string&>
	string convertToUpperCase(string& inputString);

};
