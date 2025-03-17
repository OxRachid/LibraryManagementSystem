#ifndef CLSWHOAREYOU_H
#define CLSWHOAREYOU_H

#include "clsScreen.h"
#include <algorithm>
#include <memory>
class clsWhoAreYou : protected clsScreen {
    private:
        // enum for login options
        enum eLoginOptions {
            USER_LOGIN = 1,
            MEMBER_AUTH = 2,
            EXIT = 3
        };
        // print menu
        static void _PrintMenu();
        // Get user choice
        static eLoginOptions _GetUserChoice();
        // perform option
        static void _PerformOption(eLoginOptions option);
        // user login screen
        static void _UserLogin();
        // member login screen
        static void _MemberAuth();

    public:
        // Who are you screen
        static void WhoAreYouScreen();
};

#endif // !CLSWHOAREYOU_H
