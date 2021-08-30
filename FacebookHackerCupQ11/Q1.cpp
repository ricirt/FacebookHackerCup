/*
 * @project Facebook Hacker Cup 2021
 * @file	Q1.cpp
 * @Author	Osman Baki ALTIOK 
 * @email:	osmanbakialtiok@gmail.com
 * @date	29th August 2021
 * @brief	Problem A1: Consistency - Chapter 1
 */
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#define SIZE 26

using namespace std;

vector<int>times(SIZE, 0);
vector<string>rules;

//Fills the times vector with given text (0,1,0,0,2 ....)
void fill(string);

//Prints times vector (just for testing).
void printVector();

//Fills times vector with 0's.
void resetVector();

//Calculates how many seconds would be needed to if we replace by vowels.
int replaceWithVowels(int, int, int);

//Calculates how many seconds would be needed to if we replace by consonant.
int replaceWithConsonants(int, int, int);

//The function that runs the algoritmh.
int primaryFunction();

//Reads from "consistency_chapter_1_validation_input.txt".
vector<string> read(vector<string>);

//Prints the "output.txt".
void print(vector<int>);

void generalPurposeUsing(vector<string>, vector<int>);

int main() {

	vector<string>words;
	vector<int>answers;
	words = read(words);
	int x = 1;
	
	if (x == 1) {
		for (unsigned int i = 0; i < words.size(); i++) {
			fill(words[i]);
			answers.push_back(primaryFunction());
		}
		print(answers);
	}
	else
		generalPurposeUsing(words, answers);
	
		
	return 0;
}
void resetVector() {
	for (unsigned int i = 0; i < SIZE; i++) {
		times[i] = 0;
	}
}
void fill(string input) {
	for (unsigned int i = 0; i < input.size(); i++) {
		switch (input[i]) {
		case 'A':
			times[0]++;
			break;
		case 'B':
			times[1]++;
			break;
		case 'C':
			times[2]++;
			break;
		case 'D':
			times[3]++;
			break;
		case 'E':
			times[4]++;
			break;
		case 'F':
			times[5]++;
			break;
		case 'G':
			times[6]++;
			break;
		case 'H':
			times[7]++;
			break;
		case 'I':
			times[8]++;
			break;
		case 'J':
			times[9]++;
			break;
		case 'K':
			times[10]++;
			break;
		case 'L':
			times[11]++;
			break;
		case 'M':
			times[12]++;
			break;
		case 'N':
			times[13]++;
			break;
		case 'O':
			times[14]++;
			break;
		case 'P':
			times[15]++;
			break;
		case 'Q':
			times[16]++;
			break;
		case 'R':
			times[17]++;
			break;
		case 'S':
			times[18]++;
			break;
		case 'T':
			times[19]++;
			break;
		case 'U':
			times[20]++;
			break;
		case 'V':
			times[21]++;
			break;
		case 'W':
			times[22]++;
			break;
		case 'X':
			times[23]++;
			break;
		case 'Y':
			times[24]++;
			break;
		case 'Z':
			times[25]++;
			break;
		default:
			std::cout << "Wrong input, try again!!" << endl;
			break;
		}
	}
}
void printVector() {
	for (int counter = 0; counter < SIZE; counter++) {
		std::cout << times[counter] << endl;
	}
}
int replaceWithVowels(int _consonantSum, int _vowelSum, int _mostRepVowel) {
	int result = 0;
	result = _consonantSum + 2 * (_vowelSum - _mostRepVowel);
	resetVector();
	return result;
}
int replaceWithConsonants(int _vowelSum, int _consonantSum, int _mostRepConsonant) {
	int result = 0;
	result = _vowelSum + 2 * (_consonantSum - _mostRepConsonant);
	resetVector();
	return result;
}
int primaryFunction() {
	//Finding sum of vowels , sum of consonants.
	int vowelSum = 0, consonantSum = 0;

	//Every unique vowel and consonant letter number,
	int uniqueVowel = 0, uniqueConsonant = 0;

	//Most repeated vovel and consonant number.
	int mostRepVowel = 0, mostRepConsonant = 0;

	for (unsigned int counter = 0; counter < times.size(); counter++) {

		if (times[counter] != 0) {

			if (counter == 0 || counter == 4 || counter == 8 || counter == 14 || counter == 20) {

				vowelSum += times[counter];
				uniqueVowel++;

				if (times[counter] > mostRepVowel)
					mostRepVowel = times[counter];
			}
			else {

				consonantSum += times[counter];
				uniqueConsonant++;

				if (times[counter] > mostRepConsonant)
					mostRepConsonant = times[counter];
			}
		}

	}
	int result = 0;
	/*
	* We just replace the word with Vowels and Consonants and compare them.
	* Then print the least value to the screen.
	*/
	if (replaceWithVowels(consonantSum, vowelSum, mostRepVowel) < replaceWithConsonants(vowelSum, consonantSum, mostRepConsonant))
	{
		return replaceWithVowels(consonantSum, vowelSum, mostRepVowel);
	}
	else {
		return replaceWithConsonants(vowelSum, consonantSum, mostRepConsonant);
	}
	
}
vector<string> read(vector<string>_words) {
	fstream inputFile;
	inputFile.open("consistency_chapter_1_input.txt", ios::in);
	if (inputFile.is_open()) {

		string inputNumber = "";
		getline(inputFile, inputNumber);
		stringstream ss(inputNumber);
		int number = 0;
		ss >> number;
		string word;
		while (getline(inputFile, word)) {
			_words.push_back(word);
		}
		return _words;
		inputFile.close();
	}
	else {
		std::cout << "Couldn't read from file" << endl;
		return _words;
	}
}
void print(vector<int>_answers) {
	fstream outputFile;
	outputFile.open("output.txt", ios::out);

	if (outputFile.is_open()) {
		for (unsigned int i = 0; i < _answers.size(); i++) {
			outputFile << "Case #"<<i+1<<": "<<_answers[i] << endl;
		}
	}
	else
		std::cout << "Couldnt write to file" << endl;
}
void generalPurposeUsing(vector<string>_words, vector<int>_answers) {
	unsigned int number = 0;
	cin >> number;
	for (unsigned int i = 0; i < number; i++) {
		string word;
		cin >> word;
		_words.push_back(word);
	}
	for (unsigned int i = 0; i < _words.size(); i++) {
		fill(_words[i]);
		_answers.push_back(primaryFunction());
	}
	for (unsigned int i = 0; i < _answers.size(); i++) {
		cout << _answers[i] << endl;
	}
}
void chapteroneTwo(string x) {
	rules.push_back(x);
}