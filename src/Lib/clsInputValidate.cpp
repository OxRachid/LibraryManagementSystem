#include "../../headers/Lib/clsInputValidate.h"
#include "../../headers/Lib/Colors.h"
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

// Read string from a user
string clsInputValidate::ReadString(string text) {
    string input;
    cout << Colors::GetMagenta() << text << Colors::RESET();
    getline(cin >> ws, input);
    return input;
}

// Read Char
char clsInputValidate::ReadChar() {
    char c;
    cin >> c;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return c;
}

// warning message befor taking any  action
bool clsInputValidate::AskUser(string action) {
    char answer = 'Y';
    cout << Colors::GetYellow() << action << " ? y/n : " << Colors::RESET();
    answer = clsInputValidate::ReadChar();
    return (toupper(answer) == 'Y');
}
