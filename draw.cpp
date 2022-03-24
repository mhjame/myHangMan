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

void renderGame(string guessedWord, int badGuessCount, string wrongGuess)
{
    system("cls");
    cout << FIGURE[badGuessCount] << endl;
    cout << "Some guess was wrong: " << wrongGuess << endl;
    cout << guessedWord << endl;
    cout << "Number of wrong guesses: " << badGuessCount << endl;
}

const string& getNextHangMan()
{
    const static string figure[] = {"fig1", "fig2", "fig3", "fig4"};

    const int numberOfFigures = sizeof(figure)/sizeof(string);
    static int currentFigure = 0; /// giữ currentFigure trong bộ nhớ
    return figure[(currentFigure++)%numberOfFigures]; /// chuẩn bị currentFigure cho lần sau
}

const string& getNextDancingMan()
{
    const static string figure[] = {"fig1", "fig2", "fig3", "fig4"};

    const int numberOfFigures = sizeof(figure)/sizeof(string);
    static int currentFigure = 0; /// giữ currentFigure trong bộ nhớ
    return figure[(currentFigure++)%numberOfFigures]; /// chuẩn bị currentFigure cho lần sau
}
void displayFinalResult(bool won, const string& secretWord)
{
    while(true)
    {
        for(int i = 0; i < 30; ++i) cout << endl;
        if(won)
        {
            cout << "Congratulation! you win!";
        }
        else
        {
            cout << "You lost. The correct word is " << secretWord;
        }
        cout << (won? getNextDancingMan(): getNextHangMan());
        Sleep(500);
    }
}
