#ifndef CLSSCREEN_H
#define CLSSCREEN_H
#include "../Core/clsUser.h"
#include "../Lib/Colors.h"
#include <string>
using namespace std;

class clsScreen {
    protected:
        // Print header screen
        static void PrintHeaderScreen(string HeaderTitle = "", string value = "", Colors::enColors color = Colors::White, bool isMainHeader = true, short width = 66);
        // check permissions right
        static bool CheckPermissionRights(clsUser::ePermissionFunc permission);
};

#endif // !CLSSCREEN_H
