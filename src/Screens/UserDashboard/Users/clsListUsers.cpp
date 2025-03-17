#include "../../../../headers/Screens/UserDashboard/Users/clsListUsers.h"
#include "../../../../headers/Core/clsUser.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// display user details
void clsListUsers::_DisplsyUserDetails(clsUser user) {
    short width = 15;
    cout << Colors::GetYellow() << setfill(' ') << left << setw(width - 5) << user.GetUsername() << left << setw(width) << user.GetFullName() << left << setw(width - 2) << user.GetPassword() << left << setw(width - 5) << user.GetTotalTransMade() << left << setw(width - 3) << clsDate::ConvertDateToString(user.GetAccountCreated_on()) << left << setw(width - 11) << user.GetPermissions() << Colors::RESET() << endl;
}

// list all Users
void clsListUsers::ListUsersScreen() {
    system("clear");
    // get users list from static vector
    const vector<clsUser> &vUsers = clsUser::GetUsersList();
    PrintHeaderScreen("USERS", to_string(vUsers.size()), Colors::Cyan, true);
    short width = 15;
    cout << Colors::GetCyan() << setfill(' ') << left << setw(width - 5) << "Username" << left << setw(width) << "Fullname" << left << setw(width - 2) << "Password" << left << setw(width - 5) << "TranMade" << left << setw(width - 3) << "Ac-Created" << left << setw(width - 11) << "Perm" << Colors::RESET() << endl;
    cout << Colors::GetCyan() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
    if (vUsers.empty()) {
        cout << Colors::GetRed() << "          No Data Found" << Colors::RESET() << endl;
    } else {
        for (const clsUser &U : vUsers) {
            _DisplsyUserDetails(U);
        }
    }
    cout << Colors::GetCyan() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
}
