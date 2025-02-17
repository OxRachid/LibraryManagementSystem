#ifndef CLSSCREEN_H
#define CLSSCREEN_H
#include "../Lib/Colors.h"
#include <string>
using namespace std;

class clsScreen {
    protected:
        // Print header screen
        static void PrintHeaderScreen(string HeaderTitle = "", string value = "", Colors::enColors color = Colors::White, bool isMainHeader = true, short width = 66);
};

#endif // !CLSSCREEN_H
