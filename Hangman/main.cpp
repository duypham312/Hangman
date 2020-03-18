//
//  main.cpp
//  Hangman
//
//  Created by Duy on 2/25/20.
//  Copyright © 2020 Duy. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include <cctype>
#include "animation.hpp"
using namespace std;

string generateWord();
string lower(const string& s);
string GuessedWord(const string& secretWord);
int Restart();
char input();
void playHangman();
void update(const string& secretWord, char guess, string& guessedWord);
void render(int wrongGuessWord, string guessedWord, string wrongCharacter);
bool check(char guess, const string& secretWord);

int main() {
    srand(static_cast<unsigned int>(time(0)));
    cout << "Please choose an option below!" << endl << endl
         << "1. Start - (S)" << endl
         << "2. Exit - (E)" << endl << endl
         << "My choice is ";
    char c;
    do {
        cin >> c;
        cout << endl << endl;
        if (c == 'S' or c == 's') {
            playHangman();
            Restart();
            return 0;
        }
        else if (c == 'E' or c == 'e') {
            cout << "See you again!" << endl << endl;
            return 0;
        }
        else {
            cout << "Invalid! Please try again!" << endl << endl
                 << "My choice is ";
        }
    } while (c != 'S' and c != 's' and c != 'E' and c != 'e');
    return 0;
}

void playHangman() {
    cout << "Welcome to Hangman! <3" << endl << endl
         << "I've picked a secret word." << endl << endl
         << "You need to guess each character to find the word I've picked." << endl << endl
         << "Alright. Let's start!" << endl;
    const int max = 7;
    string secretWord = lower(generateWord());
    char guess;
    string guessedWord = GuessedWord(secretWord);
    int wrongGuessCount = 0;
    string wrongCharacter = "";
    do {
        guess = input();
        if (check(guess, secretWord) == true) {
            cout << endl << endl << "Very good! Keep going!" << endl << endl;
            update(secretWord, guess, guessedWord);
            cout << endl << guessedWord << endl;
        } else {
            wrongCharacter += guess;
            wrongCharacter += " ";
            wrongGuessCount++;
            render(wrongGuessCount, guessedWord, wrongCharacter);
        }
    } while (wrongGuessCount < max and guessedWord != secretWord);
    if (wrongGuessCount == max) {
        cout << "What a pity! You lose." << endl << endl;
        defeat();
        cout << "Secret word is " << secretWord << "." << endl << endl << endl;
    }
    if (guessedWord == secretWord) {
        cout << endl << "Well done! You won!" << endl << endl;
        victory();
    }
}

int Restart() {
    char s;
    cout << "Good job! Please choose an option below!" << endl << endl
         << "1. New game - (N)" << endl
         << "2. Exit - (E)" << endl << endl
         << "My choice is ";
    do {
        cin >> s;
        cout << endl << endl;
        if (s == 'N' or s == 'n') {
            playHangman();
            Restart();
        } else if (s == 'E' or s == 'e') {
            cout << "See you again. <3" << endl << endl;
            return 0;
        }
        else {
            cout << "Invalid! Please try again!" << endl << endl
                 << "My choice is ";
        }
    } while (s != 'E' and s != 'e' and s != 'N' and s != 'n');
    return 0;
}

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

char input() {
    cout << endl << endl << "Please enter a character " << endl << endl;
    char input;
    cout << "My choice is ";
    cin >> input;
    cout << endl << endl;
    return tolower(input);
}

bool check(char guess, const string& secretWord) {
    for (int i = 0; i < secretWord.length(); i++) {
        if (secretWord[i] == guess) return true;
    }
    return false;
}

void update(const string& secretWord, char guess, string& guessedWord) {
    for (int i = 0; i < secretWord.length(); i++) {
        if (secretWord[i] == guess) {
            guessedWord[i] = guess;
        }
    }
}

void render(int wrongGuessCount, string guessedWord, string wrongCharater) {
    const string figure[] = {
        "  ----------------    \n"
        "  |                   \n"
        "  |                   \n"
        "  |                   \n"
        "  |                   \n"
        "  |                   \n"
        "  |                   \n"
        "-----                 \n",
        
        "  ----------------    \n"
        "  |             |     \n"
        "  |                   \n"
        "  |                   \n"
        "  |                   \n"
        "  |                   \n"
        "  |                   \n"
        "-----                 \n",
        
        "  ----------------    \n"
        "  |             |     \n"
        "  |             O     \n"
        "  |                   \n"
        "  |                   \n"
        "  |                   \n"
        "  |                   \n"
        "-----                 \n",

        "  ----------------    \n"
        "  |             |     \n"
        "  |             O     \n"
        "  |             |     \n"
        "  |                   \n"
        "  |                   \n"
        "  |                   \n"
        "-----                 \n",

        "  ----------------    \n"
        "  |             |     \n"
        "  |             O     \n"
        "  |            /|     \n"
        "  |                   \n"
        "  |                   \n"
        "  |                   \n"
        "-----                 \n",

        "  ----------------    \n"
        "  |             |     \n"
        "  |             O     \n"
        "  |            /|\\   \n"
        "  |                   \n"
        "  |                   \n"
        "  |                   \n"
        "-----                 \n",

        "  ----------------    \n"
        "  |             |     \n"
        "  |             O     \n"
        "  |            /|\\   \n"
        "  |            /      \n"
        "  |                   \n"
        "  |                   \n"
        "-----                 \n",

        "  ----------------    \n"
        "  |             |     \n"
        "  |             O     \n"
        "  |            /|\\   \n"
        "  |            / \\   \n"
        "  |                   \n"
        "  |                   \n"
        "-----                 \n"};
    
    cout << endl << endl
         << "Unfortunately. Try again!" << endl << endl
         << "Number of wrong guesses: " << wrongGuessCount << endl << endl
         << "Wrong guess(es): " << wrongCharater << endl << endl
         << figure[wrongGuessCount] << endl << endl << guessedWord << endl << endl;
}
