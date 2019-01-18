/*
 * main.cpp
 *
 *  Created on: 2019. 1. 18.
 *      Author: Max Shin
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <random>
#include <cstdlib>
#include <cctype>

using namespace std;

char isdigit_loop();

class WordSet{
private:
	pair<string, string>* words;
public:
	WordSet(){
		words = new pair<string, string>[40];
	}

	void insertWords(string eng, string kor, int idx){
		words[idx] = make_pair(eng, kor);
	}

	pair<string, string> getWord(int idx){
		return words[idx];
	}

	~WordSet(){
		free(words);
	}
};

int main(){
	char day = 0;
	cout << "English Voca Quiz for TOEIC\n";
	cout << "Version: 0.1\n";
	cout << "--------------------------------------------------------\n";
	cout << "Select day: ";
	day = isdigit_loop();


	int day_i = (int)day-48;
	cout << "/wordset/day" + to_string(day_i) + ".txt" << endl;

	ifstream inp;
	inp.open("./wordset/day" + to_string(day_i) + ".txt", ios::in);

	WordSet* ws = new WordSet();
	string eng;
	string kor;
	for(int i = 0; i < 40; i++){
		getline(inp, eng);
		getline(inp, kor);

		ws->insertWords(eng, kor, i);
	}

	for(int i = 0; i < 40; i++){
		pair<string, string> _pair = ws->getWord(i);
		if(rand() % 2== 1)
			cout << _pair.first << endl;
		else
			 cout << _pair.second << endl;
	}
	return 0;
}

char isdigit_loop(){
	char day = 0;
	cout << "Select day: ";
	cin >> day;

	if(!isdigit(day)){
		cout << "Only Number" << endl;
		return isdigit_loop();
	}

	return day;
}
