//
//  process.hpp
//  Hangman
//
//  Created by Duy on 3/19/20.
//  Copyright © 2020 Duy. All rights reserved.
//

#ifndef process_hpp
#define process_hpp

#include <iostream>
#include <string>

using namespace std;

string generateWord(const string& file_path);
string lower(const string& s);
string GuessedWord(const string& secretWord);
bool check(char guess, const string& secretWord);
char input();

#endif
