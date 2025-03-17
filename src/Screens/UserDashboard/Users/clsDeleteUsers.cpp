#include "../../../../headers/Screens/UserDashboard/Users/clsDeleteUsers.h"
#include "../../../../headers/Core/clsUser.h"
#include "../../../../headers/Lib/clsInputValidate.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// print user data
void clsDeleteUsers::_PrintUserData(clsUser &user) {
    cout << endl;
    PrintHeaderScreen("[User Data]", "👤", Colors::Blue, false, 41);
    cout << Colors::GetBlue() << left << setw(20) << setfill(' ') << " Username" << " : " << user.GetUsername() << endl;
    cout << left << setw(20) << " Password" << " : " << user.GetPassword() << endl;
    cout << left << setw(20) << " Fullname" << " : " << user.GetFullName() << endl;
    cout << left << setw(20) << " Email" << " : " << user.GetEmail() << endl;
    cout << left << setw(20) << " Phone" << " : " << user.GetPhone() << endl;
    cout << left << setw(20) << " Total Trans Made" << " : " << user.GetTotalTransMade() << endl;
    cout << left << setw(20) << " Permissions" << " : " << user.GetPermissions() << endl;
    cout << left << setw(20) << " Account Created on " << " : " << clsDate::ConvertDateToString(user.GetAccountCreated_on()) << endl;
    cout << setw(41) << setfill('-') << "" << Colors::RESET() << endl;
}

// Read username for target user
string clsDeleteUsers::_ReadUsername() {
    string username;
    bool isExist = false;
    do {
        if (isExist) {
            cout << Colors::GetRed() << " [ The username not found ]" << Colors::RESET() << endl;
        }
        username = clsInputValidate::ReadString("\n * Enter username : ");
        isExist = !clsUser::isUserExist(username);
    } while (isExist);
    return username;
}
// Get User for Delete
clsUser clsDeleteUsers::_GetTargetUser() {
    string username = _ReadUsername();
    return clsUser::Find(username);
}

// delete user screen
void clsDeleteUsers::DeleteUserScreen() {
    PrintHeaderScreen("DELETE USER SCREEN", "-👤", Colors::Red);
    cout << "\n\n\n";

    // Get target user
    clsUser TargetUser = _GetTargetUser();
    // Print user data
    _PrintUserData(TargetUser);
    if (clsInputValidate::AskUser("\n ⊕ Are u sure wanna delete " + TargetUser.GetUsername())) {
        if (TargetUser.Delete()) {
            // print user
            _PrintUserData(TargetUser);
            cout << Colors::GetGreen() << " [ the user deleted succefully ]" << Colors::RESET() << endl;
        } else {
            cout << Colors::GetRed() << " [ delete Failed ]" << Colors::RESET() << endl;
        }
    } else {
        cout << Colors::GetRed() << " [ delete canceled ]" << Colors::RESET() << endl;
    }
}
