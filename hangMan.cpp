#include <bits/stdc++.h>
#include <cctype>
#include <fstream>

using namespace std;

//const string WORD_LIST[] = {"dog", "cat", "human"};
const char DATA_FILE[] = "data.txt";

//const int WORD_COUNT = sizeof(WORD_LIST)/sizeof(string);

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

string chooseWord(const char* filename)
{
    cout << 1 << endl;
    ifstream fileWord(filename);  /// mở tệp có đường dẫn như trong tham số
    if(fileWord.is_open())       /// kiểm tra mở tệp thành công
    {
        string word;
        while(fileWord >> word)    /// đọc từng từ đến khi không đọc được nữa
        {
            cout << word << endl;  /// ghi tạm ra màn hình
        }
        fileWord.close();
    } else cout << "Error opening" << filename;

    //int randomIndex = rand()%WORD_COUNT;
    return "book";
}

void renderGame(string guessedWord, int badGuessCount, string wrongGuess)
{
    system("cls");
    cout << FIGURE[badGuessCount] << endl;
    cout << "Some guess was wrong: " << wrongGuess << endl;
    cout << guessedWord << endl;
    cout << "Number of wrong guesses: " << badGuessCount << endl;
}

// add "const" before string & secretWord to forbid changing secretWord

void update(string& guessedWord, const string& secretWord, char guess)
{
    for(int i = secretWord.length() - 1; i >= 0; --i)
    {
        if(secretWord[i] == guess)
        {
            guessedWord[i] = guess;
        }
    }
}

char readAGuess()
{
    char guess;
    cin >> guess;
    return tolower(guess);
}

bool contains(string secretWord, char guess)
{
    if(secretWord.find_first_of(guess) != string::npos) return true;
    return false;
}

int badGuessCount = 0;
const int maxBadGuesses = 7;
string wrongGuess = "";

int main()
{
    string secretWord = chooseWord("data.txt");

    if(secretWord.length() < 1)
    {
        cout << "Erro reading vocabulary file" << DATA_FILE;
        return -1;
    }

    string guessedWord = string(secretWord.length(), '-');

    do
    {
        renderGame(guessedWord, badGuessCount, wrongGuess);
        char guess = readAGuess();
        if(contains(secretWord, guess))
        {
            update(guessedWord, secretWord, guess);
        }
        else{
            wrongGuess += guess;
            badGuessCount++;
        }
    }while(badGuessCount < maxBadGuesses && secretWord != guessedWord);

    renderGame(guessedWord, badGuessCount, wrongGuess);
    if(badGuessCount < maxBadGuesses) cout << "congratulation! You win!";
    else cout << "You lost. The correct word is " << secretWord;

    return 0;
}
