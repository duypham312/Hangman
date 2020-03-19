//
//  process.cpp
//  Hangman
//
//  Created by Duy on 3/19/20.
//  Copyright © 2020 Duy. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

string lower(const string& s) {
    string s1 = s;
    for (int i = 0; i < s.size(); i++) {
        s1[i] = tolower(s[i]);
    }
    return s1;
}

string generateWord() {
    vector <string> list;
    ifstream file("Text.txt");
    string word;
    if (file.is_open()) {
        while (file >> word) {
            list.push_back(word);
        }
        file.close();
    }
    if (list.size() > 0) {
        return list[rand() % (list.size())];
    } else return "";
}

string GuessedWord(const string& secretWord) {
    string guessedWord;
    for (int i = 0; i < secretWord.length(); i++) {
        guessedWord.push_back('-');
    }
    return guessedWord;
}

bool check(char guess, const string& secretWord) {
    for (int i = 0; i < secretWord.length(); i++) {
        if (secretWord[i] == guess) return true;
    }
    return false;
}

char input() {
    cout << endl << endl << "Please enter a character " << endl << endl;
    char input;
    cout << "My choice is ";
    cin >> input;
    cout << endl << endl;
    return tolower(input);
}
