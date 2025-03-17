#include "../../headers/Lib/clsUtil.h"
#include "../../headers/Lib/clsDate.h"
#include <cstddef>
#include <ctime>
#include <iostream>
using namespace std;

void clsUtil::sRand() {
    srand(time(nullptr));
}

// Static function to seed the random number generator
void clsUtil::InitializeRandom() {
    static bool initialized = false; // Ensure srand() is called only once
    if (!initialized) {
        sRand();
        initialized = true;
    }
}

// get Random Number from Specific Rang
int clsUtil::RandomNumber(int from, int to) {
    InitializeRandom(); // Ensure the random number generator is seeded
    return (rand() % (to - from + 1) + from);
}

// get Random char
char clsUtil::GetRandomChar(enCharType CharType) {
    InitializeRandom(); // Ensure the random number generator is seeded

    if (CharType == MixChars) {
        CharType = (enCharType)RandomNumber(1, 3);
    }

    switch (CharType) {
        case enCharType::CapitalLetters: {
            return char(RandomNumber(65, 90));
            break;
        }
        case enCharType::SmallLetters: {
            return char(RandomNumber(97, 122));
            break;
        }
        case enCharType::Dijit: {
            return char(RandomNumber(48, 57));
            break;
        }
        default: {
            return char(RandomNumber(65, 90));
            break;
        }
    }
    // if something wrong happend it will return "0"
    return char(RandomNumber(65, 90));
}

string clsUtil::GenerateWord(enCharType CharType, short lenght) {
    string Word = "";
    for (short i = 0; i < lenght; i++) {
        Word += GetRandomChar(CharType);
    }
    return Word;
}

int clsUtil::GenerateNumber(short lenght) {
    int Numbers = 0;
    for (short i = 0; i < lenght; i++) {
        Numbers = Numbers * 10 + RandomNumber(1, 9);
    }
    return Numbers;
}

string clsUtil::GenerateKey(enCharType CharType) {
    string Key;
    Key += GenerateWord(CharType, 4);
    Key += '-';
    Key += GenerateWord(CharType, 4);
    Key += '-';
    Key += GenerateWord(CharType, 4);
    return Key;
}

void clsUtil::PrintGenerateKeys(int NumberOfKeys, enCharType CharType) {
    for (short s = 0; s < NumberOfKeys; s++) {
        cout << " Key [" << s + 1 << "] : " << GenerateKey(CharType) << endl;
    }
}

void clsUtil::swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void clsUtil::swap(double &x, double &y) {
    double temp = x;
    x = y;
    y = temp;
}

void clsUtil::swap(char &x, char &y) {
    char temp = x;
    x = y;
    y = temp;
}

void clsUtil::swap(bool &x, bool &y) {
    bool temp = x;
    x = y;
    y = temp;
}

void clsUtil::swap(string &x, string &y) {
    string t = x;
    x = y;
    y = t;
}

void clsUtil::swap(clsDate &Date1, clsDate &Date2) {
    clsDate TempDate = Date1;
    Date1 = Date2;
    Date2 = TempDate;
}

void clsUtil::ShuffleArray(int arr[], short ArrSize) {
    for (short i = 0; i < ArrSize; i++) {
        swap(arr[rand() % ArrSize], arr[rand() % ArrSize]);
    }
}

void clsUtil::ShuffleArray(string arr[], short ArrSize) {
    for (short i = 0; i < ArrSize; i++) {
        swap(arr[rand() % ArrSize], arr[rand() % ArrSize]);
    }
}
void clsUtil::ShuffleString(string &Text) {
    size_t size = Text.length();
    for (size_t i = 0; i < size; i++) {
        swap(Text[rand() % size], Text[rand() % size]);
    }
}

void clsUtil::FillArraywithRandomNumbers(int arr[], int ArrSize, int from, int to) {
    for (int i = 0; i < ArrSize; i++) {
        arr[i] = RandomNumber(from, to);
    }
}

void clsUtil::FillArraywithrandomWords(string arr[], int ArrSize, enCharType x, int length) {
    for (int i = 0; i < ArrSize; i++) {
        arr[i] = GenerateWord(x, length);
    }
}

void clsUtil::FillArrayWithRandomKeys(string arr[], int ArrSize, enCharType CharType) {
    for (int i = 0; i < ArrSize; i++)
        arr[i] = GenerateKey(CharType);
}

string clsUtil::EncryptText(string text, short key) {
    const string RandomChars = "N+pyEBdHfJWLzk(Z{K<TD2gXeF!sxQct5V$v@j*q&91ua}%)6?-mUYMn:RO#4iIS8l73=rbCGwohAP;^>,[]_`";
    string Encrypted = "";
    for (size_t i = 0; i < text.length(); i++) {
        for (size_t j = 0; j < RandomChars.length(); j++) {
            if (text[i] == RandomChars[j]) {
                Encrypted += RandomChars[j + key];
                break;
            }
        }
        if (text[i] == ' ') {
            char c = '.';
            Encrypted += c;
        }
        Encrypted += GenerateWord(MixChars, 2);
    }
    return Encrypted;
}

string clsUtil::DecryptText(string text, short key) {
    const string RandomChars = "N+pyEBdHfJWLzk(Z{K<TD2gXeF!sxQct5V$v@j*q&91ua}%)6?-mUYMn:RO#4iIS8l73=rbCGwohAP;^>,[]_`";
    string Decrypted = "";
    for (size_t i = 0; i < text.length(); i += 3) {
        for (size_t j = 0; j < RandomChars.length(); j++) {
            if (text[i] == RandomChars[j]) {
                Decrypted += RandomChars[j - key];
                break;
            }
        }
        if (text[i] == '.') {
            char c = ' ';
            Decrypted += c;
        }
    }
    return Decrypted;
}

bool clsUtil::isDateBetween(clsDate date1, clsDate date2, clsDate date3) {
    if ((clsDate::isDate1AfterDate2(date1, date2)) && (clsDate::isDate1BeforDate2(date1, date3)))
        return true;
    if ((clsDate::isDate1BeforDate2(date1, date2)) && (clsDate::isDate1AfterDate2(date1, date3)))
        return true;

    return false;
}

bool clsUtil::isValidDate(clsDate date) {
    return clsDate::isValid(date.GetYear(), date.GetMonth(), date.GetDay());
}

string clsUtil::Tabs(short NumberOfTabs) {
    string tabs = "";

    for (short i = 0; i < NumberOfTabs; i++) {
        tabs = tabs + "\t";
    }
    return tabs;
}

// Convert Number to text
string clsUtil::NumberToText(int Number) {

    if (Number == 0) {
        return "";
    }

    if (Number >= 1 && Number <= 19) {
        string arr[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

        return arr[Number] + " ";
    }

    if (Number >= 20 && Number <= 99) {
        string arr[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        return arr[Number / 10] + " " + NumberToText(Number % 10);
    }

    if (Number >= 100 && Number <= 199) {
        return "One Hundred " + NumberToText(Number % 100);
    }

    if (Number >= 200 && Number <= 999) {
        return NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
    }

    if (Number >= 1000 && Number <= 1999) {
        return "One Thousand " + NumberToText(Number % 1000);
    }

    if (Number >= 2000 && Number <= 999999) {
        return NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
    }

    if (Number >= 1000000 && Number <= 1999999) {
        return "One Million " + NumberToText(Number % 1000000);
    }

    if (Number >= 2000000 && Number <= 999999999) {
        return NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
    }

    if (Number >= 1000000000 && Number <= 1999999999) {
        return "One Billion " + NumberToText(Number % 1000000000);
    } else {
        return NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
    }
}
