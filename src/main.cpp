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
#include <Vector>
#include <random>
#include <cstdlib>

using namespace std;

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
	int week = 0;
	cout << "English Voca Quiz for TOEIC\n";
	cout << "Version: 0.1\n";
	cout << "--------------------------------------------------------\n";
	cout << "Select Week: ";
	cin >> week;
	cout << "/wordset/day" + to_string(week) + ".txt";

	ifstream inp;
	inp.open("./wordset/day" + to_string(week) + ".txt", ios::in);

	WordSet* ws = new WordSet();
	string eng;
	string kor;
	for(int i = 0; i < 20; i++){
		getline(inp, eng);
		getline(inp, kor);

		ws->insertWords(eng, kor, i);
	}

	for(int i = 0; i < 20; i++){
		pair<string, string> _pair = ws->getWord(i);
		if(rand() % 2== 1)
			cout << _pair.first << endl;
		else
			 cout << _pair.second << endl;
	}
	return 0;
}
