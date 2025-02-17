
#ifndef COLORS_H
#define COLORS_H

#include <string>
using namespace std;

class Colors {
    public:
        enum enColors {
            Black = 0,
            Red = 1,
            Green = 2,
            Yellow = 3,
            Blue = 4,
            Magenta = 5,
            Cyan = 6,
            White = 7,
            BoldRed = 8,
            BoldGreen = 9,
            BoldYellow = 10,
            BoldBlue = 11,
            BoldMagenta = 12,
            BoldCyan = 13,
            BoldWhite = 14,
            Reset = 15
        };
        // Basic Colors
        static string GetBlack();
        static string GetRed();
        static string GetGreen();
        static string GetYellow();
        static string GetBlue();
        static string GetMagenta();
        static string GetCyan();
        static string GetWhite();

        // Bold Colors
        static string GetBoldBlack();
        static string GetBoldRed();
        static string GetBoldGreen();
        static string GetBoldYellow();
        static string GetBoldBlue();
        static string GetBoldMagenta();
        static string GetBoldCyan();
        static string GetBoldWhite();

        // Reset Color
        static string RESET();
        // Func to get Color
        static string GetColor(enColors color);
};

#endif // COLORS_H
