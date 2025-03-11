#include "../../../headers/Screens/MemberDashboard/clsMemberChangePass.h"
#include "../../../headers/Core/global.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include <iostream>
#include <string>
using namespace std;

// Get new password
string clsMemberChangePass::_GetNewPassword(string CurrPass) {
    string NewPass = "";
    bool isMatches = false;
    do {
        if (isMatches) {
            cout << Colors::GetRed() << " [  Password is used currently ]" << Colors::RESET() << endl;
        }

        NewPass = clsInputValidate::ReadStringGreaterThan(5, " * Enter new password : ");
        isMatches = (NewPass == CurrPass);
    } while (isMatches);

    return NewPass;
}

// Get Confirmed Password
string clsMemberChangePass::_GetConfirmedPassword(string CurrPass) {
    string newPass = "", confirmPass = "";
    bool isMatches = false;
    do {
        if (isMatches) {
            cout << Colors::GetRed() << " [ password not matches ]\n" << Colors::RESET() << endl;
        }
        newPass = _GetNewPassword(CurrPass);
        confirmPass = clsInputValidate::ReadString(" * Confirm new password : ");
        isMatches = (newPass != confirmPass);
    } while (isMatches);

    return confirmPass;
}

// change password
void clsMemberChangePass::MemberChangePassScreen() {
    PrintHeaderScreen("CHANGE PASSWORD", "🔑", Colors::Cyan);
    cout << "\n\n";

    // read the Current password from user
    string CurrPass = clsInputValidate::ReadString(" * Enter current password : ");
    // chech if its match with CurrUser's Current password
    if (CurrPass != CurrMember.GetPassword()) {
        cout << Colors::GetRed() << " [ password is incorrect ]" << Colors::RESET() << endl;
        return;
    }

    // if they are matches then ask for new password
    string NewPassword = _GetConfirmedPassword(CurrPass);

    // update CurrUser password
    CurrMember.SetPassword(NewPassword);

    // after the password changed succesfully we update the CurrUser data
    clsMember::enSaveMode Result = CurrMember.save();
    switch (Result) {
        case clsMember::enSaveMode::SAVE_SUCCESS: {
            cout << Colors::GetGreen() << " [ password changed succesfully  ]" << Colors::RESET() << endl;
            break;
        }
        case clsMember::enSaveMode::SAVE_FAILED: {
            cout << Colors::GetRed() << " [ process failed ]" << Colors::RESET() << endl;
            break;
        }
    }
}
