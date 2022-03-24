#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED

#include <string>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
void renderGame(string guessedWord, int badGuessCount, string wrongGuess);
void displayFinalResult(bool won, const string& secretWord);

#endif // DRAW_H_INCLUDED
