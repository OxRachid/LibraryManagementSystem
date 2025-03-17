#ifndef CLSUSERLOGIN_H
#define CLSUSERLOGIN_H

#include "../clsScreen.h"
class clsUserLogin : protected clsScreen {
    private:
        // static bool for loading usrs list one time
        static bool dataleaded;

        // func to lead data from file
        static void _LoadData();
        // print header Screen
        static void _HeaderScreen();
        // login helper
        static bool _login();

    public:
        // Login
        static bool UserLogin();
};

#endif // !CLSUSERLOGIN_H
