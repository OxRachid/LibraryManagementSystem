#ifndef CLSSYSTEMMANAGE_H
#define CLSSYSTEMMANAGE_H

#include "../clsScreen.h"
class clsSystemManage : protected clsScreen {
    private:
        // enum for menu options
        enum eMenuOptions {
            UPDATE_SYSTEM = 1,
            EXIT,
        };
        // print menu
        static void _PrintMenu();
        // get user choice
        static eMenuOptions _GetUserChoice();
        // Perform option
        static void _PerformOption(eMenuOptions option);
        // UPDATE_SYSTEM
        static void _UpdateSystem();

    public:
        // system manage
        static void SystemManageScreen();
};

#endif // !clsSystemManage_h
