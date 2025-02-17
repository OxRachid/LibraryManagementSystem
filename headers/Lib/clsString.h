#ifndef CLSSTRING_H
#define CLSSTRING_H

#include <string>
using namespace std;

class clsString {
    private:
        string _Value;

    public:
        //  constructor definition
        clsString();
        // parameter constructor
        clsString(string value);
        // setter
        void SetValue(string value);
        // getter
        string GetValue();
        // Split string func (static)
        static vector<string> Split(string text, string delim = "#-#");
        // Split string func (object)
        vector<string> Split(string delim);
        // replace word in string func (static)
        static string ReplaceWord(string text, string OldWord, string NewWord);
        // replace word in string func (object)
        void ReplaceWord(string OldWord, string NewWord);
        // Print first letter of each word (static)
        static void PrintFirstLetterOfEachWord(string text);
        // Print first letter of each word (object)
        void PrintFirstLetterOfEachWord();
        // Upper First Letter Of Each Word (static)
        static string UpperFirstLetterOfEachWord(string text);
        // Upper First Letter Of Each Word (object)
        void UpperFirstLetterOfEachWord();
        // Lower First Letter Of Each Word (static)
        static string LowerFirstLetterOfEachWord(string text);
        // Lower First Letter Of Each Word (object)
        void LowerFirstLetterOfEachWord();
        // Upper All string (static)
        static string UpperAllString(string text);
        // Upper All string (object)
        void UpperAllString();
        // Lower All string (static)
        static string LowerAllString(string text);
        // Lower All string (object)
        void LowerAllString();
        // invert letter case
        static char InvertLetterCase(char c);
        // invert all letters case (static)
        static string InvertAllLettersCase(string text);
        // invert all letters case (object)
        void InvertAllLettersCase();
        // Count capital letters (static)
        static int CountCapitalLetters(string text);
        // Count capital letters (object)
        int CountCapitalLetters();
        // Count small letters (static)
        static int CountSmallLetters(string text);
        // Count small letters (object)
        int CountSmallLetters();
        // count specific letter (sratic)
        static int CountSpecificLetter(string text, char letter, bool MatchCase = true);
        // count specific letter (object)
        int CountSpecificLetter(char letter, bool MatchCase = true);
        // is vowel func
        static bool isVowel(char c);
        // count vowels (static)
        static int CountVowels(string text);
        // count vowels (object)
        int CountVowels();
        // print all vowels letters (static)
        static void PrintAllVowels(string text);
        // print all vowels letters (object)
        void PrintAllVowels();
        // print each word of string (static)
        static void PrintEachWordInString(string text);
        // print each word of string (object)
        void PrintEachWordInString();
        // count words (static)
        static int CountWords(string text);
        // count words (object)
        int CountWords();
        // trim left of string (static)
        static string TrimLeft(string text);
        // trim left of string (object)
        void TrimLeft();
        // trim right of string (static)
        static string TrimRight(string text);
        // trim right of string (object)
        void TrimRight();
        // trim all of string (static)
        static string TrimAll(string text);
        // trim all of string (object)
        void TrimAll();
        // joing string vector (static)
        static string JoinString(vector<string> &vString, string delim = " ");
        // joing string Array (static)
        static string JoinString(string arr[], int length, string delim = " ");
        // print vector of string (static)
        static void PrintVectorOfString(vector<string> &Vstr);
        // print array of string (static)
        static void PrintArrOfString(string arrStr[], int length);
        // revers string (static)
        static string ReversString(string text);
        // revers string (object)
        void ReversString();
        // remove Punctuations (static)
        static string RemovePunctuations(string text);
        // remove Punctuations (object)
        void RemovePunctuations();
        // format text For Comparison (static)
        static string FormatForComparison(string text);
        // format text For Comparison (obj)
        void FormatForComparison();
};

#endif // !CLSSTRING_H
