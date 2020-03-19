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

#include "animation.hpp"
#include "render.hpp"
#include "process.hpp"

using namespace std;

void playHangman();
void Restart();

int main() {
    srand(static_cast<unsigned int>(time(0)));
    cout << "Please choose an option below!" << endl << endl
         << "1. Start - (S)" << endl
         << "2. Exit - (E)" << endl << endl
         << "My choice is ";
    string c;
    do {
        cin >> c;
        cout << endl << endl;
        if (c == "S" or c == "s") {
            playHangman();
            Restart();
            return 0;
        }
        else if (c == "E" or c == "e") {
            cout << "See you again!" << endl << endl;
            return 0;
        }
        else {
            cout << "Invalid! Please try again!" << endl << endl
                 << "My choice is ";
        }
    } while (c != "S" and c != "s" and c != "E" and c != "e");
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

void Restart() {
    string s;
    cout << "Good job! Please choose an option below!" << endl << endl
         << "1. New game - (N)" << endl
         << "2. Exit - (E)" << endl << endl
         << "My choice is ";
    do {
        cin >> s;
        cout << endl << endl;
        if (s == "N" or s == "n") {
            playHangman();
            Restart();
        } else if (s == "E" or s == "e") {
            cout << "See you again. <3" << endl << endl;
            return;
        }
        else {
            cout << "Invalid! Please try again!" << endl << endl
                 << "My choice is ";
        }
    } while (s != "E" and s != "e" and s != "N" and s != "n");
    return;
}
