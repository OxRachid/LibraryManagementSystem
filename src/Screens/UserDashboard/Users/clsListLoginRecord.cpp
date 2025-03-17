#include "../../../../headers/Screens/UserDashboard/Users/clsListLoginRecord.h"
#include "../../../../headers/Core/clsUser.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// display user details
void clsListLoginRecord::_DisplayLogData(clsUser::stUserLogin log) {
    short width = 18;
    cout << Colors::GetBlue() << setfill(' ') << left << setw(width - 4) << log._username << left << setw(width) << log._password << left << setw(width - 3) << log._permissions << left << setw(width) << log._loginTime << Colors::RESET() << endl;
}

// list all Users
void clsListLoginRecord::ListLoginRecordScreen() {
    system("clear");
    // get users list from static vector
    const vector<clsUser::stUserLogin> &vLoginRecord = clsUser::GetUsersLogin();
    PrintHeaderScreen("LOGIN RECORD", to_string(vLoginRecord.size()), Colors::Yellow, true);
    short width = 18;
    cout << Colors::GetYellow() << setfill(' ') << left << setw(width - 4) << "Username" << left << setw(width) << "Password" << left << setw(width - 3) << "Permissions" << left << setw(width) << "LoginTime" << Colors::RESET() << endl;
    cout << Colors::GetYellow() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
    if (vLoginRecord.empty()) {
        cout << Colors::GetRed() << "          No Data Found" << Colors::RESET() << endl;
    } else {
        for (const clsUser::stUserLogin &log : vLoginRecord) {
            _DisplayLogData(log);
        }
    }
    cout << Colors::GetYellow() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
}
