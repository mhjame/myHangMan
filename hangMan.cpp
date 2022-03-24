#include <bits/stdc++.h>
#include <cctype>
#include <fstream>
#include <thread>
#include <chrono>
#include <atomic>
#include <windows.h>

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


string toLowerCase(const string& s)
{
    string res = s;
    /*
    int sz = s.size();
    for(int i = 0; i < sz; ++i)
        res[i] = tolower(s[i]);*/
    transform(s.begin(), s.end(), res.begin(), ::tolower);
    /// nghĩa câu lệnh trên: duyệt từ đầu đến cuối s, biến đổi bằng
    /// hàm tolower(), đặt kết quả lần lượt vào các ký tự từ đầu
    /// của res
    return res;
}
string chooseWord(const char* filename)
{
    vector <string> wordList; /// khai báo vector chứa các từ sẽ đọc
    ifstream fileWord(filename);  /// mở tệp có đường dẫn như trong tham số
    if(fileWord.is_open())       /// kiểm tra mở tệp thành công
    {
        string word;
        while(fileWord >> word)    /// đọc từng từ đến khi không đọc được nữa
        {
            wordList.push_back(word);  /// ghi tạm ra màn hình
        }
        fileWord.close();
    } else cout << "Error opening" << filename;

    int WORD_COUNT = wordList.size();

    if(WORD_COUNT > 0)
    {
        int randomIndex = rand()%WORD_COUNT;
        return toLowerCase(wordList[randomIndex]);
    }
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

void displayFinalResult(bool won, const string& secretWord)
{
    if(won)
    {
        cout << "Congratulation! you win!";
    }
    else
    {
        cout << "You lost. The correct word is " << secretWord;
    }
}

void testRunAnimation()
{
    int i = 0;
    while(i < 10)
    {
        for(int j = 0; j < 2; ++j) cout << endl; // xóa màn hình
        cout << i; ++i; // vẽ hình kế tiếp

        Sleep(500);
        //std::chrono::milliseconds timespan(6000);
        //std::this_thread::sleep_for(std::chrono::milliseconds(500)); // đợi 500miligiay
        //std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

int badGuessCount = 0;
const int maxBadGuesses = 7;
string wrongGuess = "";

int main()
{
    //testRunAnimation();

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

    //renderGame(guessedWord, badGuessCount, wrongGuess);
    displayFinalResult(badGuessCount < maxBadGuesses, secretWord);
    if(badGuessCount < maxBadGuesses) cout << "congratulation! You win!";
    else cout << "You lost. The correct word is " << secretWord;

    return 0;
}
