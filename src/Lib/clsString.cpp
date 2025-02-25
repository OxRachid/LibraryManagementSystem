#include "../../headers/Lib/clsString.h"
#include <__config>
#include <cctype>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// constructor definition
clsString::clsString()
    : _Value(" ") {}

// parameter constructor
clsString::clsString(string value)
    : _Value(value) {}

// setter
void clsString::SetValue(string value) {
    _Value = value;
}

// getter
string clsString::GetValue() {
    return _Value;
}

// Split string func (static)
vector<string> clsString::Split(string text, string delim) {
    vector<string> Vstring;
    size_t pos = 0;
    string Word = "";
    while ((pos = text.find(delim)) != string::npos) {
        Word = text.substr(0, pos);
        if (Word != "")
            Vstring.push_back(Word);

        text.erase(0, pos + delim.length());
    }
    if (text != "")
        Vstring.push_back(text);

    return Vstring;
}

// Split string func (object)
vector<string> clsString::Split(string delim) {
    return clsString::Split(_Value, delim);
}

// replace word in string func (static)
string clsString::ReplaceWord(string text, string OldWord, string NewWord) {
    size_t pos = 0;
    while ((pos = text.find(OldWord, pos)) != string::npos) {
        text.replace(pos, OldWord.length(), NewWord);
        pos += NewWord.length(); // Ensure to search from next NewWord
    }
    return text;
}

// replace word in string func (object)
void clsString::ReplaceWord(string OldWord, string NewWord) {
    _Value = clsString::ReplaceWord(_Value, OldWord, NewWord);
}

// Print first letter of each word (static)
void clsString::PrintFirstLetterOfEachWord(string text) {
    bool isFirstLetter = true;
    for (size_t i = 0; i < text.length(); i++) {
        if (text.at(i) != ' ' && isFirstLetter)
            cout << text.at(i) << endl;
        // Print first letter of each word (static)
        isFirstLetter = (text.at(i) == ' ') ? true : false;
    }
}

// Print first letter of each word (object)
void clsString::PrintFirstLetterOfEachWord() {
    return clsString::PrintFirstLetterOfEachWord(_Value);
}
// Upper First Letter Of Each Word (static)
string clsString::UpperFirstLetterOfEachWord(string text) {
    bool isFirstLetter = true;
    for (size_t i = 0; i < text.length(); i++) {
        if (text.at(i) != ' ' && isFirstLetter)
            text.at(i) = toupper(text.at(i));
        isFirstLetter = (text.at(i) == ' ') ? true : false;
    }
    return text;
}
// Upper First Letter Of Each Word (object)
void clsString::UpperFirstLetterOfEachWord() {
    _Value = clsString::UpperFirstLetterOfEachWord(_Value);
}
// Lower First Letter Of Each Word (static)
string clsString::LowerFirstLetterOfEachWord(string text) {
    bool isFirstLetter = true;
    for (size_t i = 0; i < text.length(); i++) {
        if (text.at(i) != ' ' && isFirstLetter)
            text.at(i) = tolower(text.at(i));
        isFirstLetter = (text.at(i) == ' ') ? true : false;
    }
    return text;
}
// Lower First Letter Of Each Word (object)
void clsString::LowerFirstLetterOfEachWord() {
    _Value = clsString::LowerFirstLetterOfEachWord(_Value);
}

// Upper All string (static)
string clsString::UpperAllString(string text) {
    for (size_t i = 0; i < text.length(); i++) {
        text.at(i) = toupper(text.at(i));
    }
    return text;
}
// Upper All string (object)
void clsString::UpperAllString() {
    _Value = clsString::UpperAllString(_Value);
}
// Lower All string (static)
string clsString::LowerAllString(string text) {
    for (size_t i = 0; i < text.length(); i++) {
        text.at(i) = tolower(text.at(i));
    }
    return text;
}
// Lower All string (object)
void clsString::LowerAllString() {
    _Value = clsString::LowerAllString(_Value);
}

// invert letter case
char clsString::InvertLetterCase(char c) {
    return (isupper(c)) ? tolower(c) : toupper(c);
}

// invert all letters case (static)
string clsString::InvertAllLettersCase(string text) {
    for (size_t i = 0; i < text.length(); i++) {
        text.at(i) = clsString::InvertLetterCase(text.at(i));
    }
    return text;
}
// invert all letters case (object)
void clsString::InvertAllLettersCase() {
    _Value = clsString::InvertAllLettersCase(_Value);
}

// Count capital letters (static)
int clsString::CountCapitalLetters(string text) {
    int CapitalCount = 0;
    for (size_t i = 0; i < text.length(); i++) {
        if (isupper(text.at(i)))
            CapitalCount++;
    }
    return CapitalCount;
}
// Count capital letters (object)
int clsString::CountCapitalLetters() {
    return clsString::CountCapitalLetters(_Value);
}

// Count small letters (static)
int clsString::CountSmallLetters(string text) {
    int SmallCount = 0;
    for (size_t i = 0; i < text.length(); i++) {
        if (islower(text.at(i)))
            SmallCount++;
    }
    return SmallCount;
}
// Count small letters (object)
int clsString::CountSmallLetters() {
    return clsString::CountSmallLetters(_Value);
}

// count specific letter (sratic)
int clsString::CountSpecificLetter(string text, char letter, bool MatchCase) {
    int Counter = 0;
    for (size_t i = 0; i < text.length(); i++) {
        if (MatchCase) {
            if (text.at(i) == letter)
                Counter++;
        } else {
            if (toupper(text.at(i)) == toupper(letter))
                Counter++;
        }
    }

    return Counter;
}
// count specific letter (object)
int clsString::CountSpecificLetter(char letter, bool MatchCase) {
    return clsString::CountSpecificLetter(_Value, letter, MatchCase);
}

// is vowel
bool clsString::isVowel(char c) {
    char Character = tolower(c);
    return (Character == 'a' || Character == 'e' || Character == 'i' || Character == 'o' || Character == 'u');
}
// count vowels (static)
int clsString::CountVowels(string text) {
    int Counter = 0;
    for (size_t i = 0; i < text.length(); i++) {
        if (clsString::isVowel(text.at(i)))
            Counter++;
    }
    return Counter;
}
// count vowels (object)
int clsString::CountVowels() {
    return clsString::CountVowels(_Value);
}
// print all vowels letters (static)
void clsString::PrintAllVowels(string text) {
    for (size_t i = 0; i < text.length(); i++) {
        if (isVowel(text.at(i)))
            cout << text.at(i) << ", ";
    }
}
// print all vowels letters (object)
void clsString::PrintAllVowels() {
    clsString::PrintAllVowels(_Value);
}

// print each word of string (static)
void clsString::PrintEachWordInString(string text) {
    string delim = " ";
    size_t pos = 0;
    string word = "";
    while ((pos = text.find(' ')) && pos != string::npos) {
        word = text.substr(0, pos);
        if (word != "")
            cout << word << " " << endl;

        text.erase(0, pos + delim.length());
    }
    if (text != "")
        cout << text << endl;
}
// print each word of string (object)
void clsString::PrintEachWordInString() {
    clsString::PrintEachWordInString(_Value);
}

// count words (static)
int clsString::CountWords(string text) {
    string delim = " ";
    size_t pos = 0;
    string word = "";
    int Counter = 0;
    while ((pos = text.find(' ')) && pos != string::npos) {
        word = text.substr(0, pos);
        if (word != "")
            Counter++;

        text.erase(0, pos + delim.length());
    }
    if (text != "")
        Counter++;

    return Counter;
}
// count words (object)
int clsString::CountWords() {
    return clsString::CountWords(_Value);
}

// trim left of string (static)
string clsString::TrimLeft(string text) {
    text.erase(0, text.find_first_not_of(' '));
    return text;
}
// trim left of string (object)
void clsString::TrimLeft() {
    _Value = clsString::TrimLeft(_Value);
}
// trim right of string (static)
string clsString::TrimRight(string text) {
    text.erase(text.find_last_not_of(' ') + 1);
    return text;
}
// trim right of string (object)
void clsString::TrimRight() {
    _Value = clsString::TrimRight(_Value);
}
// trim all of string (static)
string clsString::TrimAll(string text) {
    return clsString::TrimLeft(clsString::TrimRight(text));
}
// trim all of string (object)
void clsString::TrimAll() {
    _Value = clsString::TrimAll(_Value);
}

// joing string (static)
string clsString::JoinString(vector<string> &vString, string delim) {
    string str = "";
    for (string &s : vString) {
        str = str + s + delim;
    }
    return str.substr(0, str.length() - delim.length());
}
// joing string Array (static)
string clsString::JoinString(string arr[], int length, string delim) {
    string str = "";
    for (int i = 0; i < length; i++) {
        str = str + arr[i] + delim;
    }
    return str.substr(0, str.length() - delim.length());
}

// print array of string (static)
void clsString::PrintArrOfString(string arrStr[], int length) {
    for (int i = 0; i < length; i++) {
        cout << arrStr[i] << endl;
    }
}
// print vector of string (static)
void clsString::PrintVectorOfString(vector<string> &Vstr) {
    for (string &s : Vstr) {
        cout << s << endl;
    }
}

// revers string (static)
string clsString::ReversString(string text) {
    vector<string> vStr = clsString::Split(text, " ");
    string str = "";
    while (!vStr.empty()) {
        str = str + vStr.back() + " ";
        vStr.pop_back();
    }
    return str.substr(0, str.length() - 1);
}
// revers string (object)
void clsString::ReversString() {
    _Value = clsString::ReversString(_Value);
}

// remove Punctuations (static)
string clsString::RemovePunctuations(string text) {
    string newStr = "";
    for (size_t i = 0; i < text.length(); i++) {
        if (!ispunct(text.at(i))) {
            newStr += text.at(i);
        }
    }
    return newStr;
}
// remove Punctuations (object)
void clsString::RemovePunctuations() {
    _Value = RemovePunctuations(_Value);
}

// format text For Comparison (static)
string clsString::FormatForComparison(string text) {
    string FormatText = "";
    for (size_t i = 0; i < text.length(); i++) {
        if (!ispunct(text.at(i)) && text.at(i) != ' ') {
            FormatText += text.at(i);
        }
    }
    return LowerAllString(FormatText);
}
// format text For Comparison (obj)
void clsString::FormatForComparison() {
    _Value = FormatForComparison(_Value);
}
