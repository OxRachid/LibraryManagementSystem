#include "../../../headers/Screens/System/clsChangePassword.h"
#include "../../../headers/Core/global.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include <iostream>
#include <string>
using namespace std;

// change password
void clsChangePassword::ChangePasswordScreen() {
    PrintHeaderScreen("CHANGE PASSWORD", "🔑", Colors::Cyan);
    cout << "\n\n";

    // read the Current password from user
    string CurrPassword = clsInputValidate::ReadString(" * Enter current password : ");
    // chech if its match with CurrUser's Current password
    if (CurrPassword != CurrUser.GetPassword()) {
        cout << Colors::GetRed() << " [ password is incorrect ]" << Colors::RESET() << endl;
        return;
    }

    // if they are matches then ask for new password
    string NewPassword = clsInputValidate::ReadString(" * Enter new password : ");
    if (NewPassword == CurrPassword) {
        cout << Colors::GetRed() << " [  Password is used currently ]" << Colors::RESET() << endl;
        NewPassword = clsInputValidate::ReadString(" * Please Enter new password : ");
    }
    // ask again to confirm the new password
    string ConfirmPassword = clsInputValidate::ReadString(" * Confirm new password : ");
    while (NewPassword != ConfirmPassword) {
        cout << Colors::GetRed() << " [ password not matches ]" << Colors::RESET() << endl;
        NewPassword = clsInputValidate::ReadString(" * Enter new password : ");
        ConfirmPassword = clsInputValidate::ReadString(" * Confirm new password : ");
    }

    // if they are matches then update CurrUser password
    CurrUser.SetPassword(ConfirmPassword);

    // after the password changed succesfully we update the CurrUser data
    clsUser::eSaveResult Result = CurrUser.save();
    switch (Result) {
        case clsUser::eSaveResult::SAVE_SUCCESS: {
            cout << Colors::GetGreen() << " [ password changed succesfully  ]" << Colors::RESET() << endl;
            break;
        }
        case clsUser::eSaveResult::SAVE_FAILED: {
            cout << Colors::GetRed() << " [ process failed ]" << Colors::RESET() << endl;
            break;
        }
    }
}
