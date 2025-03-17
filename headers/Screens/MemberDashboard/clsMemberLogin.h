#ifndef CLSMEMBERLOGIN_H
#define CLSMEMBERLOGIN_H

#include "../clsScreen.h"
class clsMemberLogin : protected clsScreen {
    private:
        // static bool for loading members list one time
        static bool dataleaded;

        // func to lead data from file
        static void _LoadData();
        // print header Screen
        static void _HeaderScreen();
        // login helper
        static bool _login();

    public:
        // Login
        static bool MemberLogin();
};

#endif // !CLSMEMBERLOGIN_H
