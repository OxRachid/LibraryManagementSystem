#include "../../headers/Screens/clsMainMenuScreen.h"
#include "../../headers/Core/clsBook.h"
#include "../../headers/Core/clsMember.h"
#include "../../headers/Core/clsTransaction.h"
#include "../../headers/Core/clsUser.h"
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
bool clsMainMenuScreen::dataLoaded = false;

// Read user choice
clsMainMenuScreen::enMainMenuOptions clsMainMenuScreen::_GetUserChoice() {
    return (enMainMenuOptions)clsInputValidate::Readnumberbetween(1, 5, "\n * Select Your Option : ");
}

// print main menu
void clsMainMenuScreen::_PrintMainMenu() {
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
void clsMainMenuScreen::_BooksManageScreen() {
    system("clear");
    clsBooksManage::BooksManageScreen();
}
// Member Manage screen
void clsMainMenuScreen::_MemberManageScreen() {
    system("clear");
    clsMemberManage::MemberManageScreen();
}
// users Manage screen
void clsMainMenuScreen::_UsersManageScreen() {
    system("clear");
    clsUsersManage::UsersManageScreen();
}
// Transactions screen
void clsMainMenuScreen::_TransactionScreen() {
    system("clear");
    clsTransactionsMenu::TransMenuScreen();
}

// Perform main menu Options
void clsMainMenuScreen::_PerformMainMenuOptions(enMainMenuOptions Options) {
    switch (Options) {
        case enMainMenuOptions::eBooksManage: {
            _BooksManageScreen();
            break;
        }
        case enMainMenuOptions::eMemberManage: {
            _MemberManageScreen();
            break;
        }
        case enMainMenuOptions::eTransactions: {
            _TransactionScreen();
            break;
        }
        case enMainMenuOptions::eUserManage: {
            _UsersManageScreen();
            break;
        }
        case enMainMenuOptions::eLogout: {
            break;
        }
    }

    // pause screen after each func finished
    if (Options != enMainMenuOptions::eLogout) {
        // this trick just to pause termux screen until the user Contenu
        cout << " \n\n\n\n\n\nEnter any Key to Contenu ... " << endl;
        char Contenue = clsInputValidate::ReadChar();
        Contenue = ' ';
        cout << Contenue << endl;
    }
}

// Show Main Menu Screen
void clsMainMenuScreen::MainMenuScreen() {
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

    enMainMenuOptions Option;
    do {
        _PrintMainMenu();
        Option = _GetUserChoice();
        _PerformMainMenuOptions(Option);
    } while (Option != enMainMenuOptions::eLogout);
}
