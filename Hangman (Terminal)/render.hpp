//
//  render.hpp
//  Hangman
//
//  Created by Duy on 3/19/20.
//  Copyright © 2020 Duy. All rights reserved.
//

#ifndef render_hpp
#define render_hpp

#include <iostream>
#include <string>

using namespace std;

void render(const int& wrongGuessWord, const string& guessedWord, const string& wrongCharacter);
void update(const string& secretWord, const char& guess, string& guessedWord);

#endif
