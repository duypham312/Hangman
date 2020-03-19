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

void render(int wrongGuessWord, string guessedWord, string wrongCharacter);
void update(const string& secretWord, char guess, string& guessedWord);

#endif
