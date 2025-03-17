#ifndef CLSUSERCHANGEPASS_H
#define CLSUSERCHANGEPASS_H

#include "../../clsScreen.h"
class clsUserChangePass : protected clsScreen {
    private:
        // Get new password
        static string _GetNewPassword(string CurrPass);
        // Get Confirmed Password
        static string _GetConfirmedPassword(string CurrPass);

    public:
        // change password
        static void UserChangePassScreen();
};

#endif // !CLSUSERCHANGEPASS_H
