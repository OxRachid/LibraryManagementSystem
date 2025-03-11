#ifndef CLSMEMBERCHANGEPASS_H
#define CLSMEMBERCHANGEPASS_H

#include "../clsScreen.h"
class clsMemberChangePass : protected clsScreen {
    private:
        // Get new password
        static string _GetNewPassword(string CurrPass);
        // Get Confirmed Password
        static string _GetConfirmedPassword(string CurrPass);

    public:
        // change password
        static void MemberChangePassScreen();
};

#endif // !CLSMEMBERCHANGEPASS_H
