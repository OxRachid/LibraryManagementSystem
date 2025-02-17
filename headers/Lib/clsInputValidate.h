#ifndef CLSINPUTVALDATE_H
#define CLSINPUTVALDATE_H
#include "../Lib/Colors.h"
#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>
using namespace std;

class clsInputValidate {

    public:
        clsInputValidate() {}

        // warning message befor taking any  action
        static bool AskUser(string action);

        // Read string from a user
        static string ReadString(string text);

        // Read Char
        static char ReadChar();

        // Read positive number
        template <typename T> static T ReadPositiveNumber(string prompt = "") {
            T Number = ReadNumber<T>(prompt);
            while (Number < 1) {
                cout << Colors::GetRed() << "\n [Please Enter a Positive Number]" << Colors::RESET() << endl;
                Number = ReadNumber<T>(prompt);
            }
            return Number;
        }

        // Read  Number  and check validation
        template <typename T> static T ReadNumber(string prompt = "") {
            // Write first message
            if (prompt != "") {
                cout << Colors::GetMagenta() << prompt << Colors::RESET();
            }

            // check number validate
            T number = 0;
            while (!(cin >> number)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << Colors::GetRed() << "\n ^ Please Enter a Number : " << Colors::RESET();
            }
            return number;
        }
        // check if specific number is between two other numbers
        template <typename T> static bool isNumberBetween(T value, T from, T to) {
            return (value >= from && value <= to);
        }

        // check validation of  input and if its between two numbers
        template <typename T> static T Readnumberbetween(T from, T to, string prompt) {
            T number = ReadNumber<T>(prompt);
            while (!isNumberBetween(number, from, to)) {
                cout << Colors::GetYellow() << "\n ^ Error.. Enter Number Between [" << from << "-" << to << "] : " << Colors::RESET();
                number = ReadNumber<T>();
            }
            return number;
        }
};

#endif // !CLSINPUTVALDATE_H
