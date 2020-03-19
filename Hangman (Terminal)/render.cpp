//
//  render.cpp
//  Hangman
//
//  Created by Duy on 3/19/20.
//  Copyright © 2020 Duy. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

void render(int wrongGuessCount, string guessedWord, string wrongCharater) {
    const string figure[] = {
        "  ----------------  \n"
        "  |                 \n"
        "  |                 \n"
        "  |                 \n"
        "  |                 \n"
        "  |                 \n"
        "  |                 \n"
        "-----               \n",
        
        "  ----------------  \n"
        "  |           |     \n"
        "  |                 \n"
        "  |                 \n"
        "  |                 \n"
        "  |                 \n"
        "  |                 \n"
        "-----               \n",
        
        "  ----------------  \n"
        "  |           |     \n"
        "  |           O     \n"
        "  |                 \n"
        "  |                 \n"
        "  |                 \n"
        "  |                 \n"
        "-----               \n",

        "  ----------------  \n"
        "  |           |     \n"
        "  |           O     \n"
        "  |           |     \n"
        "  |                 \n"
        "  |                 \n"
        "  |                 \n"
        "-----               \n",

        "  ----------------  \n"
        "  |           |     \n"
        "  |           O     \n"
        "  |          /|     \n"
        "  |                 \n"
        "  |                 \n"
        "  |                 \n"
        "-----               \n",

        "  ----------------  \n"
        "  |           |     \n"
        "  |           O     \n"
        "  |          /|\\   \n"
        "  |                 \n"
        "  |                 \n"
        "  |                 \n"
        "-----               \n",

        "  ----------------  \n"
        "  |           |     \n"
        "  |           O     \n"
        "  |          /|\\   \n"
        "  |          /      \n"
        "  |                 \n"
        "  |                 \n"
        "-----               \n",

        "  ----------------  \n"
        "  |           |     \n"
        "  |           O     \n"
        "  |          /|\\   \n"
        "  |          / \\   \n"
        "  |                 \n"
        "  |                 \n"
        "-----               \n"};
    
    cout << endl << endl
         << "Unfortunately. Try again!" << endl << endl
         << "Number of wrong guesses: " << wrongGuessCount << endl << endl
         << "Wrong guess(es): " << wrongCharater << endl << endl
         << figure[wrongGuessCount] << endl << endl << guessedWord << endl << endl;
}

void update(const string& secretWord, char guess, string& guessedWord) {
    for (int i = 0; i < secretWord.length(); i++) {
        if (secretWord[i] == guess) {
            guessedWord[i] = guess;
        }
    }
}
