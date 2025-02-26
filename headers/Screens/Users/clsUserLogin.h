#ifndef CLSUSERLOGIN_H
#define CLSUSERLOGIN_H

#include "../clsScreen.h"
class clsUserLogin : protected clsScreen {
    private:
        // static bool for loading usrs list once time
        static bool dataleaded;

    public:
        // Login
        static void UserLogin();
};

#endif // !CLSUSERLOGIN_H
