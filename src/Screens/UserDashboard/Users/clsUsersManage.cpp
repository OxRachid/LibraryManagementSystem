#include "../../../../headers/Screens/UserDashboard/Users/clsUsersManage.h"
#include "../../../../headers/Lib/clsInputValidate.h"
#include "../../../../headers/Screens/UserDashboard/Users/clsAddUsers.h"
#include "../../../../headers/Screens/UserDashboard/Users/clsDeleteUsers.h"
#include "../../../../headers/Screens/UserDashboard/Users/clsFindUsers.h"
#include "../../../../headers/Screens/UserDashboard/Users/clsListLoginRecord.h"
#include "../../../../headers/Screens/UserDashboard/Users/clsListUsers.h"
#include "../../../../headers/Screens/UserDashboard/Users/clsUpdateUsers.h"
#include <iomanip>
#include <iostream>
using namespace std;

// get user choice
clsUsersManage::enMenuOptions clsUsersManage::_GetUserChoice() {
    return (enMenuOptions)clsInputValidate::Readnumberbetween(1, 7, "\n * select your option : ");
}
// Print User manage menu
void clsUsersManage::_DisplayMenu() {
    system("clear");
    PrintHeaderScreen("USERS MANAGE MENU SCREEN", "👥", Colors::Cyan);
    cout << Colors::GetGreen() << "                             ϟ\n" << Colors::RESET();
    PrintHeaderScreen("Members Manage Menu", "👥", Colors::Cyan, false);
    const short width = 24;
    cout << setw(width) << setfill(' ') << " " << left << "[1] List Users" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[2] Add Users" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[3] Delete Users" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[4] Update Users" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[5] Find Users" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[6] Login Record" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[7] Exit" << endl;
    cout << Colors::GetCyan() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
}
// perform member manage options
void clsUsersManage::_PerformOption(enMenuOptions option) {
    switch (option) {
        case enMenuOptions::LIST_USERS: {
            _ListUsers();
            break;
        }
        case enMenuOptions::ADD_USER: {
            _AddNewUser();
            break;
        }
        case enMenuOptions::DELETE_USER: {
            _DeleteUser();
            break;
        }
        case enMenuOptions::UPDATE_USER: {
            _UpdateUser();
            break;
        }
        case enMenuOptions::FIND_USER: {
            _FindUser();
            break;
        }
        case enMenuOptions::LOGIN_RECORD: {
            _LoginRecord();
            break;
        }
        case enMenuOptions::EXIT: {
            break;
        }
        default:
            break;
    }
    // pause screen after each func finished
    if (option != enMenuOptions::EXIT) {
        // this trick just to pause termux screen until the user Contenu
        cout << " \n\n\n\n\n\nEnter any Key to Contenu ... " << endl;
        char Contenue = clsInputValidate::ReadChar();
        Contenue = ' ';
        cout << Contenue << endl;
    }
}
// List Users screen
void clsUsersManage::_ListUsers() {
    system("clear");
    clsListUsers::ListUsersScreen();
}
// Add Users screen
void clsUsersManage::_AddNewUser() {
    system("clear");
    clsAddUser::AddUserScreen();
}
// Delete Users screen
void clsUsersManage::_DeleteUser() {
    system("clear");
    clsDeleteUsers::DeleteUserScreen();
}
// update user screen
void clsUsersManage::_UpdateUser() {
    system("clear");
    clsUpdateUsers::UpdateUsersScreen();
}
// Find Users screen
void clsUsersManage::_FindUser() {
    system("clear");
    clsFindUsers::FindUsersScreen();
}
// login Record screen
void clsUsersManage::_LoginRecord() {
    system("clear");
    clsListLoginRecord::ListLoginRecordScreen();
}

// User manage screen
void clsUsersManage::UsersManageScreen() {
    // check permisdions
    if (!CheckPermissionRights(clsUser::ePermissionFunc::USERS_MANAGE)) {
        return;
    }

    enMenuOptions option;
    do {
        _DisplayMenu();
        option = _GetUserChoice();
        _PerformOption(option);
    } while (option != enMenuOptions::EXIT);
}
