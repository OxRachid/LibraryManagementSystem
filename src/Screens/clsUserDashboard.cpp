#include "../../headers/Screens/clsUserDashboard.h"
#include "../../headers/Core/clsBook.h"
#include "../../headers/Core/clsMember.h"
#include "../../headers/Core/clsTransaction.h"
#include "../../headers/Lib/clsInputValidate.h"
#include "../../headers/Screens/Books/clsBooksManage.h"
#include "../../headers/Screens/Members/clsMemberManage.h"
#include "../../headers/Screens/Transactions/clsTransactionsMenu.h"
#include "../../headers/Screens/Users/clsUsersManage.h"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// Define static variable
bool clsUserDashboard::dataLoaded = false;

// Read user choice
clsUserDashboard::eUserDashboardOptions clsUserDashboard::_GetUserChoice() {
    return (eUserDashboardOptions)clsInputValidate::Readnumberbetween(1, 5, "\n * Select Your Option : ");
}

// print main menu
void clsUserDashboard::_PrintMenu() {
    system("clear");
    PrintHeaderScreen("MAIN MENU SCREEN", "📚", Colors::Yellow);
    cout << Colors::GetGreen() << "                             ϟ\n" << Colors::RESET();
    PrintHeaderScreen("Main Menue ", "📋", Colors::Yellow, false);
    const short width = 24;
    cout << setw(width) << setfill(' ') << " " << left << "[1] Books Manage" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[2] Member Manage" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[3] Transactions" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[4] User Manage" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[5] Logout" << endl;
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
        case eUserDashboardOptions::LOGOUT: {
            break;
        }
    }

    // pause screen after each func finished
    if (Options != eUserDashboardOptions::LOGOUT) {
        // this trick just to pause termux screen until the user Contenu
        cout << " \n\n\n\n\n\nEnter any Key to Contenu ... " << endl;
        char Contenue = clsInputValidate::ReadChar();
        Contenue = ' ';
        cout << Contenue << endl;
    }
}

// Show Main Menu Screen
void clsUserDashboard::UserDashboardScreen() {
    // ensur to lead data from file just one time
    if (!dataLoaded) {
        // load books from file
        clsBook::LoadBooksFromFile();
        // load Members from file
        clsMember::LoadMembersFromFile();
        // load clsTransactions history
        clsTransaction::LoadBorrowRecords();
        dataLoaded = true;
    }

    eUserDashboardOptions Option;
    do {
        _PrintMenu();
        Option = _GetUserChoice();
        _PerformOption(Option);
    } while (Option != eUserDashboardOptions::LOGOUT);
}
