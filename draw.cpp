#include <iostream>
#include <windows.h>
#include <thread>
#include <chrono>

using namespace std;

const string FIGURE[] = {"   -------------     \n"
                         "   |                 \n"
                         "   |                 \n"
                         "   |                 \n"
                         "   |                 \n"
                         "   |                 \n"
                         " -----               \n",

                         "   -------------     \n"
                         "   |           |     \n"
                         "   |                 \n"
                         "   |                 \n"
                         "   |                 \n"
                         "   |                 \n"
                         " -----               \n",

                         "   -------------     \n"
                         "   |           |     \n"
                         "   |           0     \n"
                         "   |                 \n"
                         "   |                 \n"
                         "   |                 \n"
                         " -----               \n",

                         "   -------------     \n"
                         "   |           |     \n"
                         "   |           0     \n"
                         "   |           |     \n"
                         "   |                 \n"
                         "   |                 \n"
                         " -----               \n",

                         "   -------------     \n"
                         "   |           |     \n"
                         "   |           0     \n"
                         "   |          /|     \n"
                         "   |                 \n"
                         "   |                 \n"
                         " -----               \n",

                         "   -------------     \n"
                         "   |           |     \n"
                         "   |           0     \n"
                         "   |          /|\\     \n"
                         "   |                 \n"
                         "   |                 \n"
                         " -----               \n",

                         "   -------------     \n"
                         "   |           |     \n"
                         "   |           0     \n"
                         "   |          /|\\     \n"
                         "   |          /      \n"
                         "   |                 \n"
                         " -----               \n",

                          "   -------------     \n"
                         "   |           |     \n"
                         "   |           0     \n"
                         "   |          /|\\     \n"
                         "   |          / \\     \n"
                         "   |                 \n"
                         " -----               \n"};

const string fiHangingMan[] = {
                         "   -------------     \n"
                         "   |         /     \n"
                         "   |         0     \n"
                         "   |        /|\\     \n"
                         "   |        / \\     \n"
                         "   |                 \n"
                         " -----               \n",

                         "   -------------     \n"
                         "   |         |     \n"
                         "   |         0     \n"
                         "   |        /|\\     \n"
                         "   |        / \\     \n"
                         "   |                 \n"
                         " -----               \n",

                         "   -------------     \n"
                         "   |         \\     \n"
                         "   |         0     \n"
                         "   |        /|\\     \n"
                         "   |        / \\     \n"
                         "   |                 \n"
                         " -----               \n",

                         "   -------------     \n"
                         "   |         |     \n"
                         "   |         0     \n"
                         "   |        /|\\     \n"
                         "   |        / \\     \n"
                         "   |                 \n"
                         " -----               \n"
};

const string fiDancingMan[]{

                         "      0       \n"
                         "     /|\\     \n"
                         "     | |     \n",

                         "      0       \n"
                         "     /|\\     \n"
                         "     / \\     \n",

                         "     _0_      \n"
                         "      |       \n"
                         "     / \\     \n",

                         "     \\0/     \n"
                         "      |       \n"
                         "     / \\     \n",

                         "     _0_      \n"
                         "      |       \n"
                         "     / \\     \n",

                         "      0       \n"
                         "     /|\\     \n"
                         "     / \\     \n",

                         "     0        \n"
                         "     /|\\     \n"
                         "     / \\     \n",

                         "      0       \n"
                         "     /|\\     \n"
                         "     / \\     \n",

                         "       0       \n"
                         "     /|\\     \n"
                         "     / \\     \n",

                         "      0       \n"
                         "     /|\\     \n"
                         "     / \\     \n",
};

const int countsFiDancingMan = sizeof(fiDancingMan)/sizeof(string);
const int countsFiHangingMan = sizeof(fiHangingMan)/sizeof(string);

void renderGame(string guessedWord, int badGuessCount, string wrongGuess)
{
    system("cls");
    cout << FIGURE[badGuessCount] << endl;
    cout << "Some guess was wrong: " << wrongGuess << endl;
    cout << guessedWord << endl;
    cout << "Number of wrong guesses: " << badGuessCount << endl;
}

const string& getNextImage(const string images[], const int imageCounts)
{
    static int currentFigure = 0; /// giữ currentFigure trong bộ nhớ
    return images[(currentFigure++)%imageCounts]; /// chuẩn bị currentFigure cho lần sau
}

void displayFinalResult(bool won, const string& secretWord)
{
    while(true)
    {
        system("cls");
        //for(int i = 0; i < 30; ++i) cout << endl;
        if(won)
        {
            cout << "Congratulation! you win!" << endl;
        }
        else
        {
            cout << "You lost. The correct word is " << secretWord << endl;
        }
        cout << (won? getNextImage(fiDancingMan, countsFiDancingMan): getNextImage(fiHangingMan, countsFiHangingMan));
        Sleep(500);
    }
}
