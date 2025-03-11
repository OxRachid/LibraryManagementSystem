#include "../../headers/Lib/clsInputValidate.h"
#include "../../headers/Lib/Colors.h"
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

// Read string from a user
string clsInputValidate::ReadString(string prompt) {
    string input;
    cout << Colors::GetMagenta() << prompt << Colors::RESET();
    getline(cin >> ws, input);
    return input;
}

// Read string that is greater than specific length
string clsInputValidate::ReadStringGreaterThan(short length, string prompt) {
    string input = "";
    bool isValid = false;
    do {
        if (isValid) {
            cout << Colors::GetRed() << " the key must be greater than " << length << " charachters." << Colors::RESET() << endl;
        }
        input = ReadString(prompt);
        isValid = (input.length() < 5);
    } while (isValid);

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
