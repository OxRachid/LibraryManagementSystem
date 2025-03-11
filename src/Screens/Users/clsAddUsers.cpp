#include "../../../headers/Screens/Users/clsAddUsers.h"
#include "../../../headers/Core/clsUser.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

// print user data
void clsAddUser::_PrintUserData(clsUser &user) {
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
// Get Unique username of user
string clsAddUser::_GetUniqueUsername() {
    PrintHeaderScreen("Read newUser data", "🔻", Colors::Magenta, false, 41);
    string username;
    bool isExist = false;
    do {
        if (isExist) {
            cout << Colors::GetRed() << " [ The username is already Exist ]" << Colors::RESET() << endl;
        }
        username = clsInputValidate::ReadString(" ⊙ Enter username : ");
        isExist = clsUser::isUserExist(username);
    } while (isExist);
    return username;
}

// Read permissions
short clsAddUser::_GetPermissions() {
    PrintHeaderScreen("Read Pemissions", "🔑", Colors::Magenta, false, 41);

    short permissions = 0;
    if (clsInputValidate::AskUser(" * Give Access to all functions")) {
        return static_cast<short>(clsUser::ePermissionFunc::ALL);
    }

    cout << Colors::GetBlue() << " Give Access to : " << Colors::RESET() << endl;

    const vector<pair<string, clsUser::ePermissionFunc>> vPermissionOptions = {
        {"(Book Manage)", clsUser::ePermissionFunc::BOOK_MANAGE},
        {"(Member Manage)", clsUser::ePermissionFunc::MEMBER_MANAGE},
        {"(Transactions)", clsUser::ePermissionFunc::TRANSACTIONS},
        {"(Users Manage)", clsUser::ePermissionFunc::USERS_MANAGE},
    };

    for (const auto &option : vPermissionOptions) {
        if (clsInputValidate::AskUser(" * " + option.first)) {
            permissions |= option.second;
            cout << Colors::GetGreen() << " Accepted " << Colors::RESET() << endl;
        } else {
            cout << Colors::GetRed() << " Rejected " << Colors::RESET() << endl;
        }
    }

    return permissions;
}

// Read user obj data
void clsAddUser::_ReadUserData(clsUser &user) {
    user.SetFirstName(clsInputValidate::ReadString(" ⊙ Enter firstname : "));
    user.SetLastName(clsInputValidate::ReadString(" ⊙ Enter lastname : "));
    user.SetEmail(clsInputValidate::ReadString(" ⊙ Enter Email : "));
    user.SetPhone(clsInputValidate::ReadString(" ⊙ Enter Phone : "));
    user.SetPassword(clsInputValidate::ReadStringGreaterThan(5, " ⊙ Enter Password : "));
    user.SetPermissions(_GetPermissions());
}
// Get user obj to Add
clsUser clsAddUser::_GetAddObjMode() {
    string username = _GetUniqueUsername();
    return clsUser::GetAddUserObjMode(username);
}

// Add new User screen
void clsAddUser::AddUserScreen() {
    PrintHeaderScreen("ADD USER SCREEN", "+👤", Colors::Yellow);
    cout << "\n\n\n";

    // Get new user obj
    clsUser newUser = _GetAddObjMode();
    // Read User data
    _ReadUserData(newUser);
    // save new user to file
    clsUser::eSaveResult Result = newUser.save();
    switch (Result) {
        case clsUser::eSaveResult::SAVE_SUCCESS: {
            // print user data
            _PrintUserData(newUser);
            cout << Colors::GetGreen() << " [ Adding newUser succesfully ]" << Colors::RESET() << endl;
            break;
        }
        case clsUser::eSaveResult::SAVE_FAILED: {
            cout << Colors::GetRed() << " [ Adding Failed ]" << Colors::RESET() << endl;
            break;
        }
    }
}
