#include "../../../headers/Screens/Transactions/clsTransactionsMenu.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include "../../../headers/Screens/Transactions/TransHistory/clsTransHistoryMenu.h"
#include "../../../headers/Screens/Transactions/clsBorrowBook.h"
#include "../../../headers/Screens/Transactions/clsReturnBook.h"
#include "../../../headers/Screens/Transactions/clsTrackMembers.h"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// Read user choice
clsTransactionsMenu::eTransOptions clsTransactionsMenu::_GetUserChoice() {
    return (eTransOptions)clsInputValidate::Readnumberbetween(1, 6, "\n * Select Your Option : ");
}

// Print menu
void clsTransactionsMenu::_PrintMenu() {
    system("clear");
    PrintHeaderScreen("TRANSACTIONS MENU SCREEN", "📚", Colors::Cyan);
    cout << Colors::GetGreen() << "                             ϟ\n" << Colors::RESET();
    PrintHeaderScreen("Transactions Menu", "📋", Colors::Cyan, false);
    const short width = 24;
    cout << setw(width) << setfill(' ') << " " << left << "[1] Borrow Book" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[2] Return Book" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[3] Transactions History" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[4] Track Members" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[4] Track Books" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[6] Exit" << endl;
    cout << Colors::GetCyan() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
}
// Perform Transactions options
void clsTransactionsMenu::_PerformOption(eTransOptions option) {
    switch (option) {
        case eTransOptions::BORROW_BOOK: {
            _BorrowBook();
            break;
        }
        case eTransOptions::RETURN_BOOK: {
            _ReturnBook();
            break;
        }
        case eTransOptions::BORROWING_HISTORY: {
            _TransactionsHistory();
            break;
        }
        case eTransOptions::TRACK_MEMBER: {
            _TrackMemberActivity();
            break;
        }
        case eTransOptions::TRACK_BOOK: {
            _TrackBookActivity();
            break;
        }
        case eTransOptions::EXIT: {
            break;
        }
        default:
            break;
    }
    // pause screen after each func finished
    if (option != eTransOptions::EXIT) {
        // this trick just to pause termux screen until the user Contenu
        cout << " \n\n\n\n\n\nEnter any Key to Contenu ... " << endl;
        char Contenue = clsInputValidate::ReadChar();
        Contenue = ' ';
        cout << Contenue << endl;
    }
}
// BORROW_BOOK
void clsTransactionsMenu::_BorrowBook() {
    system("clear");
    clsBorrowBook::BorrowBookScreen();
}
// RETURN_BOOK
void clsTransactionsMenu::_ReturnBook() {
    system("clear");
    clsReturnBook::ReturnBookScreen();
}
// BORROWING_HISTORY
void clsTransactionsMenu::_TransactionsHistory() {
    system("clear");
    clsTransHistoryMenu::TransHistoryMenuScreen();
}
// TRACK_MEMBER
void clsTransactionsMenu::_TrackMemberActivity() {
    system("clear");
    clsTrackMembers::TrackMembersScreen();
}

// TRACK_BOOK
void clsTransactionsMenu::_TrackBookActivity() {
    system("clear");
    cout << "sooon";
}

// Transactions Menu screen
void clsTransactionsMenu::TransMenuScreen() {
    eTransOptions option;
    do {
        _PrintMenu();
        option = _GetUserChoice();
        _PerformOption(option);
    } while (option != eTransOptions::EXIT);
}
