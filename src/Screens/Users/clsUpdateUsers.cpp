#include "../../../headers/Screens/Users/clsUpdateUsers.h"
#include "../../../headers/Core/clsUser.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

// Print member data
void clsUpdateUsers::_PrintUserData(clsUser &user) {
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
string clsUpdateUsers::_ReadUsername() {
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
clsUser clsUpdateUsers::_GetTargetUser() {
    string username = _ReadUsername();
    return clsUser::Find(username);
}

// Get permissions
short clsUpdateUsers::_GetPermissions() {
    PrintHeaderScreen("Read Pemissions", "🔑", Colors::Magenta, false, 41);

    short permissions = 0;
    if (clsInputValidate::AskUser(" * Give Access to all functions")) {
        return static_cast<short>(clsUser::ePermissionFunc::ALL);
    }

    cout << Colors::GetBlue() << " Give Access to : " << Colors::RESET() << endl;

    const vector<pair<string, clsUser::ePermissionFunc>> vPermissionOptions = {
        {"Book Manage", clsUser::ePermissionFunc::BOOK_MANAGE},
        {"Member Manage", clsUser::ePermissionFunc::MEMBER_MANAGE},
        {"Transactions", clsUser::ePermissionFunc::TRANSACTIONS},
        {"Users Manage", clsUser::ePermissionFunc::USERS_MANAGE},
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

// Read new data
void clsUpdateUsers::_ReadNewData(clsUser &user) {
    PrintHeaderScreen("Read New Data", "👤", Colors::Magenta, false, 54);

    if (clsInputValidate::AskUser("\n □ Rename firstname ")) {
        user.SetFirstName(clsInputValidate::ReadString("\n ⊙ Enter new firstname : "));
        cout << Colors::GetGreen() << " [ firstname Renamed Succesfully ]" << endl;
    }
    if (clsInputValidate::AskUser("\n □ Rename lastname ")) {
        user.SetLastName(clsInputValidate::ReadString("\n ⊙ Enter new lastname : "));
        cout << Colors::GetGreen() << " [ lastname Renamed Succesfully ]" << endl;
    }
    if (clsInputValidate::AskUser("\n □ Update Email ")) {
        user.SetEmail(clsInputValidate::ReadString("\n ⊙ Enter new Email : "));
        cout << Colors::GetGreen() << " [ Email updated Succesfully ]" << endl;
    }
    if (clsInputValidate::AskUser("\n □ Update Phone ")) {
        user.SetPhone(clsInputValidate::ReadString("\n ⊙ Enter new Phone : "));
        cout << Colors::GetGreen() << " [ Phone updated Succesfully ]" << endl;
    }
    if (clsInputValidate::AskUser("\n □ Change Password ")) {
        user.SetPassword(clsInputValidate::ReadStringGreaterThan(5, "\n ⊙ Enter new Password : "));
        cout << Colors::GetGreen() << " [ Password changed Succesfully ]" << endl;
    }
    if (clsInputValidate::AskUser("\n □ Update Permissions ")) {
        user.SetPermissions(_GetPermissions());
        cout << Colors::GetGreen() << "\n [ Permissions updated Succesfully ]" << endl;
    }
}

// update user
void clsUpdateUsers::UpdateUsersScreen() {
    PrintHeaderScreen("UPDATE USER SCREEN", "♻️👤", Colors::Cyan);
    cout << "\n\n\n";

    // Get the target user
    clsUser TargetUser = _GetTargetUser();
    // Print user data
    _PrintUserData(TargetUser);
    // Ask user befor taking action
    if (clsInputValidate::AskUser("\n ⊕ Ara u sure wanna update " + TargetUser.GetUsername())) {
        // read new user data
        _ReadNewData(TargetUser);
        // save the new data to file
        clsUser::eSaveResult Result = TargetUser.save();
        switch (Result) {
            case clsUser::eSaveResult::SAVE_SUCCESS: {
                _PrintUserData(TargetUser);
                cout << Colors::GetGreen() << " [ User Data Updated Succesfully ]" << Colors::RESET() << endl;
                break;
            }
            case clsUser::eSaveResult::SAVE_FAILED: {
                cout << Colors::GetRed() << " [ Update Failed ]" << Colors::RESET() << endl;
                break;
            }
        }

    } else {
        cout << Colors::GetRed() << " [ Update Canceled ]" << Colors::RESET() << endl;
    }
}
