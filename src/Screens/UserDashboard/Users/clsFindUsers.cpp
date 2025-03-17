#include "../../../../headers/Screens/UserDashboard/Users/clsFindUsers.h"
#include "../../../../headers/Core/clsUser.h"
#include "../../../../headers/Lib/clsInputValidate.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// print user data
void clsFindUsers::_PrintUserData(clsUser &user) {
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

// Get Target User
clsUser clsFindUsers::_GetTargetUser() {
    string username = clsInputValidate::ReadString("\n * Enter username : ");
    return clsUser::Find(username);
}

// Find Users screen
void clsFindUsers::FindUsersScreen() {
    PrintHeaderScreen("FIND USER SCREEN", "🔍👤", Colors::Magenta);
    cout << "\n\n\n";

    // Get Target user
    clsUser TargetUser = _GetTargetUser();

    if (!TargetUser.isEmpty()) {
        _PrintUserData(TargetUser);
        cout << Colors::GetGreen() << " [ user found  ]" << Colors::RESET() << endl;
    } else {
        cout << Colors::GetRed() << " [ user not found ]" << Colors::RESET() << endl;
    }
}
