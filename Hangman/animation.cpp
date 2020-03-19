//
//  animation.cpp
//  Hangman
//
//  Created by Duy on 3/18/20.
//  Copyright © 2020 Duy. All rights reserved.
//

#include <iostream>
#include <chrono>
#include <thread>
#include <string>

using namespace std;

void clear() {
    for (int i = 0; i < 10; i++) cout << endl;
}

void victory() {
    const string figure[] = {
    "                   \n"
    "                   \n"
    "         \\O/      \n"
    "          |        \n"
    "         / \\      \n"
    "                   \n"
    "                   \n"
    "                   \n",

    "                   \n"
    "                   \n"
    "          O/       \n"
    "         /|        \n"
    "         / \\      \n"
    "                   \n"
    "                   \n"
    "                   \n",

    "                   \n"
    "                   \n"
    "         \\O       \n"
    "          |\\      \n"
    "         / \\      \n"
    "                   \n"
    "                   \n"
    "                   \n",

    "                   \n"
    "                   \n"
    "          O/       \n"
    "         /|        \n"
    "         / \\      \n"
    "                   \n"
    "                   \n"
    "                   \n",
        
    "                   \n"
    "                   \n"
    "         \\O       \n"
    "          |\\      \n"
    "         / \\      \n"
    "                   \n"
    "                   \n"
    "                   \n",
        
    "                   \n"
    "                   \n"
    "          O        \n"
    "         /|\\      \n"
    "         | |       \n"
    "                   \n"
    "                   \n"
    "                   \n",
    
    "                   \n"
    "                   \n"
    "          O        \n"
    "         /|\\      \n"
    "         / \\      \n"
    "                   \n"
    "                   \n"
    "                   \n",
        
    "                   \n"
    "                   \n"
    "          O        \n"
    "         /|\\      \n"
    "         | |       \n"
    "                   \n"
    "                   \n"
    "                   \n",
        
    "                   \n"
    "                   \n"
    "         \\O/      \n"
    "          |        \n"
    "         / \\      \n"
    "                   \n"
    "                   \n"
    "                   \n"
    };
    clear();
    for (int i = 0; i < 9; i++) {
        cout << figure[i];
        clear();
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

void defeat() {
    const string figure[] = {
    "  ----------------  \n"
    "  |           /     \n"
    "  |          O      \n"
    "  |         /|\\    \n"
    "  |         / \\    \n"
    "  |                 \n"
    "  |                 \n"
    "-----               \n",

    "  ----------------  \n"
    "  |            \\   \n"
    "  |             O   \n"
    "  |            /|\\ \n"
    "  |            / \\ \n"
    "  |                 \n"
    "  |                 \n"
    "-----               \n",

    "  ----------------  \n"
    "  |           /     \n"
    "  |          O      \n"
    "  |         /|\\    \n"
    "  |         / \\    \n"
    "  |                 \n"
    "  |                 \n"
    "-----               \n",

    "  ----------------  \n"
    "  |            \\   \n"
    "  |             O   \n"
    "  |            /|\\ \n"
    "  |            / \\ \n"
    "  |                 \n"
    "  |                 \n"
    "-----               \n",
        
    "  ----------------  \n"
    "  |           /     \n"
    "  |          O      \n"
    "  |         /|\\    \n"
    "  |         / \\    \n"
    "  |                 \n"
    "  |                 \n"
    "-----               \n",
        
    "  ----------------  \n"
    "  |            \\   \n"
    "  |             O   \n"
    "  |            /|\\ \n"
    "  |            / \\ \n"
    "  |                 \n"
    "  |                 \n"
    "-----               \n",
    
    "  ----------------  \n"
    "  |           /     \n"
    "  |          O      \n"
    "  |         /|\\    \n"
    "  |         / \\    \n"
    "  |                 \n"
    "  |                 \n"
    "-----               \n",
        
    "  ----------------  \n"
    "  |            \\   \n"
    "  |             O   \n"
    "  |            /|\\ \n"
    "  |            / \\ \n"
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
    "-----               \n"
    };
    clear();
    for (int i = 0; i < 9; i++) {
        cout << figure[i];
        clear();
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}
