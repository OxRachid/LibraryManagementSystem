#include "../../headers/Screens/clsMemberDashboard.h"
#include "../../headers/Core/clsBook.h"
#include "../../headers/Core/clsMember.h"
#include "../../headers/Core/clsTransaction.h"
#include "../../headers/Lib/clsInputValidate.h"
#include "../../headers/Screens/MemberDashboard/clsProfile.h"
#include <asm-generic/errno.h>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <system_error>
using namespace std;

// Define static variable
bool clsMemberDashboard::dataLoaded = false;

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
    cout << "soon";
}
// FIND_BOOKS screen
void clsMemberDashboard::_FindBooks() {

    system("clear");
    cout << "soon";
}
// BORROW_BOOK screen
void clsMemberDashboard::_BorrowBook() {

    system("clear");
    cout << "soon";
}
// RETURN_BOOK screen
void clsMemberDashboard::_ReturnBook() {

    system("clear");
    cout << "soon";
}
// HISTORY
void clsMemberDashboard::_MemberHistory() {

    system("clear");
    cout << "soon";
}

// member dashboard Screen
void clsMemberDashboard::MemberDashboardScreen() {
    eMenuOptions option;
    do {
        _PrintMenu();
        option = _GetUserChoice();
        _PerformOption(option);
    } while (option != eMenuOptions::LOGOUT);
}
