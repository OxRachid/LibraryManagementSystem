#ifndef CLSUTIL_H
#define CLSUTIL_H

#include "clsDate.h"
#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>
using namespace std;

class clsUtil {
    public:
        clsUtil() {}
        enum enCharType {
            SmallLetters = 1,
            CapitalLetters = 2,
            Dijit = 3,
            MixChars = 4
        };

        static void sRand();

        // Static function to seed the random number generator
        static void InitializeRandom();

        // get Random Number from Specific Rang
        static int RandomNumber(int from, int to);

        // get Random char
        static char GetRandomChar(enCharType LetterType);

        static string GenerateWord(enCharType LetterType, short lenght);

        static string GenerateKey(enCharType LetterType);

        static int GenerateNumber(short lenght);

        static void PrintGenerateKeys(int NumberOfKeys, enCharType LetterType);

        static void swap(int &x, int &y);

        static void swap(double &x, double &y);

        static void swap(char &x, char &y);

        static void swap(bool &x, bool &y);

        static void swap(string &x, string &y);

        static void swap(clsDate &Date1, clsDate &Date2);

        static void ShuffleArray(int arr[], short ArrSize);

        static void ShuffleArray(string arr[], short ArrSize);
        static void ShuffleString(string &Text);

        static void FillArraywithRandomNumbers(int arr[], int ArrSize, int from, int to);

        static void FillArraywithrandomWords(string arr[], int ArrSize, enCharType x, int length);

        static void FillArrayWithRandomKeys(string arr[], int ArrSize, enCharType CharType);

        static string EncryptText(string text, short key = 4);

        static string DecryptText(string text, short key = 4);

        static bool isDateBetween(clsDate date1, clsDate date2, clsDate date3);

        static bool isValidDate(clsDate date);

        static string Tabs(short NumberOfTabs);

        // Convert Number to text
        static string NumberToText(int Number);
};

#endif // !CLSUTIL_H
