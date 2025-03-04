#include "../../headers/Screens/clsMemberDashboard.h"
#include "../../headers/Core/clsBook.h"
#include "../../headers/Core/clsTransaction.h"
#include "../../headers/Lib/clsInputValidate.h"
#include "../../headers/Screens/Books/ListBooks/clsListMenu.h"
#include "../../headers/Screens/Books/clsFindBook.h"
#include "../../headers/Screens/MemberDashboard/clsProfile.h"
#include "../../headers/Screens/Transactions/clsTrackMembers.h"
#include <asm-generic/errno.h>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// Define static variable
bool clsMemberDashboard::dataLoaded = false;

// func to lead data from file
void clsMemberDashboard::_LoadData() {
    // ensur to lead data from file just one time
    if (!dataLoaded) {
        // load books from file
        clsBook::LoadBooksFromFile();
        // load clsTransactions history
        clsTransaction::LoadTransactions();
        dataLoaded = true;
    }
}

// print main menu
void clsMemberDashboard::_PrintMenu() {
    system("clear");
    PrintHeaderScreen("MEMBER DASHBOARD", "📚", Colors::Cyan);
    cout << Colors::GetGreen() << "                             ϟ\n" << Colors::RESET();
    PrintHeaderScreen("Menu", "📋", Colors::Cyan, false);
    const short width = 24;
    cout << setw(width) << setfill(' ') << " " << left << "[1] Profile" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[2] List Books" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[3] Find Book" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[4] Borrow Book" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[5] Return Book" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[6] History" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[7] Logout" << endl;
    cout << Colors::GetCyan() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
}
// Read user choice
clsMemberDashboard::eMenuOptions clsMemberDashboard::_GetUserChoice() {
    return static_cast<eMenuOptions>(clsInputValidate::Readnumberbetween(1, 7, "\n * select your option : "));
}
// Perform main menu Options
void clsMemberDashboard::_PerformOption(eMenuOptions option) {
    switch (option) {
        case eMenuOptions::PROFILE: {
            _Profile();
            break;
        }
        case eMenuOptions::LIST_BOOKS: {
            _ListBooks();
            break;
        }
        case eMenuOptions::FIND_BOOKS: {
            _FindBooks();
            break;
        }
        case eMenuOptions::BORROW_BOOK: {
            _BorrowBook();
            break;
        }
        case eMenuOptions::RETURN_BOOK: {
            _ReturnBook();
            break;
        }
        case eMenuOptions::MEMBER_HISTORY: {
            _MemberHistory();
            break;
        }
        case eMenuOptions::LOGOUT: {
            break;
        }
    }
    // pause screen after each func finished
    if (option != eMenuOptions::LOGOUT) {
        // this trick just to pause termux screen until the user Contenu
        cout << " \n\n\n\n\n\nEnter any Key to Contenu ... " << endl;
        char Contenue = clsInputValidate::ReadChar();
        Contenue = ' ';
        cout << Contenue << endl;
    }
}
// PROFILE screen
void clsMemberDashboard::_Profile() {
    system("clear");
    clsProfile::ProfileScreen();
}
// LIST_BOOKS screen
void clsMemberDashboard::_ListBooks() {
    system("clear");
    clsListMenu::ListMenuScreen();
}
// FIND_BOOKS screen
void clsMemberDashboard::_FindBooks() {
    system("clear");
    clsFindBook::FindBookScreen();
}
// BORROW_BOOK screen
void clsMemberDashboard::_BorrowBook() {
    system("clear");
}
// RETURN_BOOK screen
void clsMemberDashboard::_ReturnBook() {
    system("clear");
}
// HISTORY
void clsMemberDashboard::_MemberHistory() {
    system("clear");
    clsTrackMembers::TrackMembersScreen();
}

// member dashboard Screen
void clsMemberDashboard::MemberDashboardScreen() {
    // func to lead data from file
    _LoadData();

    eMenuOptions option;
    do {
        _PrintMenu();
        option = _GetUserChoice();
        _PerformOption(option);
    } while (option != eMenuOptions::LOGOUT);
}
