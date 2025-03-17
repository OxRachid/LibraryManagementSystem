#include "../../../headers/Screens/UserDashboard/clsUserDashboard.h"
#include "../../../headers/Core/clsBook.h"
#include "../../../headers/Core/clsMember.h"
#include "../../../headers/Core/clsTransaction.h"
#include "../../../headers/Core/global.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include "../../../headers/Screens/UserDashboard/Books/clsBooksManage.h"
#include "../../../headers/Screens/UserDashboard/Members/clsMemberManage.h"
#include "../../../headers/Screens/UserDashboard/System/clsSystemManage.h"
#include "../../../headers/Screens/UserDashboard/Transactions/clsTransactionsMenu.h"
#include "../../../headers/Screens/UserDashboard/Users/clsUsersManage.h"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// Define static variable
bool clsUserDashboard::dataLoaded = false;

// func to lead data from file
void clsUserDashboard::_LoadData() {
    // ensur to lead data from file just one time
    if (!dataLoaded) {
        // load books from file
        clsBook::LoadBooksFromFile();
        // load Members from file
        clsMember::LoadMembersFromFile();
        // load clsTransactions history
        clsTransaction::LoadTransactions();
        // lead UsersLogin list
        clsUser::LoadUsersLogin();
        dataLoaded = true;
    }
}

// Read user choice
clsUserDashboard::eUserDashboardOptions clsUserDashboard::_GetUserChoice() {
    return (eUserDashboardOptions)clsInputValidate::Readnumberbetween(1, 6, "\n * Select Your Option : ");
}

// print main menu
void clsUserDashboard::_PrintMenu() {
    system("clear");
    PrintHeaderScreen("USER DASHBOARD", "📚", Colors::Yellow);
    cout << Colors::GetGreen() << "                             ϟ\n" << Colors::RESET();
    PrintHeaderScreen("Menu", "📋", Colors::Yellow, false);
    const short width = 24;
    cout << setw(width) << setfill(' ') << " " << left << "[1] Books Manage" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[2] Member Manage" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[3] Transactions" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[4] User Manage" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[5] System Manage" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[6] Logout" << endl;
    cout << Colors::GetYellow() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
}

// Books Manage screen
void clsUserDashboard::_BooksManageScreen() {
    system("clear");
    clsBooksManage::BooksManageScreen();
}
// Member Manage screen
void clsUserDashboard::_MemberManageScreen() {
    system("clear");
    clsMemberManage::MemberManageScreen();
}
// users Manage screen
void clsUserDashboard::_UsersManageScreen() {
    system("clear");
    clsUsersManage::UsersManageScreen();
}
// Transactions screen
void clsUserDashboard::_TransactionScreen() {
    system("clear");
    clsTransactionsMenu::TransMenuScreen();
}

// system Manage screen
void clsUserDashboard::_SystemManageScreen() {
    system("clear");
    clsSystemManage::SystemManageScreen();
}

// Perform main menu Options
void clsUserDashboard::_PerformOption(eUserDashboardOptions Options) {
    switch (Options) {
        case eUserDashboardOptions::BOOKS_MANAGE: {
            _BooksManageScreen();
            break;
        }
        case eUserDashboardOptions::MEMBER_MANAGE: {
            _MemberManageScreen();
            break;
        }
        case eUserDashboardOptions::TRANSACTIONS: {
            _TransactionScreen();
            break;
        }
        case eUserDashboardOptions::USER_MANAGE: {
            _UsersManageScreen();
            break;
        }
        case eUserDashboardOptions::SYSYEM_MANAGE: {
            _SystemManageScreen();
            break;
        }
        case eUserDashboardOptions::LOGOUT: {
            break;
        }
    }
}

// Show Main Menu Screen
void clsUserDashboard::UserDashboardScreen() {
    // load data from file
    _LoadData();
    // create log for login activity
    CurrUser.LogUserLogin();

    eUserDashboardOptions Option;
    do {
        _PrintMenu();
        Option = _GetUserChoice();
        _PerformOption(Option);
    } while (Option != eUserDashboardOptions::LOGOUT);
}
