#ifndef CLSMEMBERAUTH_H
#define CLSMEMBERAUTH_H

#include "../clsScreen.h"
class clsMemberAuth : protected clsScreen {
    private:
        // enum for auth options
        enum eAuthOptions {
            LOGIN = 1,
            REGISTER,
            EXIT
        };
        // Get user choice
        static eAuthOptions _GetUserChoice();
        // print menu
        static void _PrintMenu();
        // perform option
        static void _PerformOption(eAuthOptions option);
        // login screen
        static void _LoginScreen();
        // register screen
        static void _RegisterScreen();

    public:
        // handles login or register account functionality
        static void MemberAuthScreen();
};

#endif // !CLSMEMBERAUTH_H
