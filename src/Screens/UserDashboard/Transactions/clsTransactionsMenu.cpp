#include "../../../../headers/Screens/UserDashboard/Transactions/clsTransactionsMenu.h"
#include "../../../../headers/Lib/clsInputValidate.h"
#include "../../../../headers/Screens/UserDashboard/Transactions/TransHistory/clsTransHistoryMenu.h"
#include "../../../../headers/Screens/UserDashboard/Transactions/clsBorrowBook.h"
#include "../../../../headers/Screens/UserDashboard/Transactions/clsCheckRequests.h"
#include "../../../../headers/Screens/UserDashboard/Transactions/clsReturnBook.h"
#include "../../../../headers/Screens/UserDashboard/Transactions/clsTrackBooks.h"
#include "../../../../headers/Screens/UserDashboard/Transactions/clsTrackMembers.h"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// Read user choice
clsTransactionsMenu::eTransOptions clsTransactionsMenu::_GetUserChoice() {
    return (eTransOptions)clsInputValidate::Readnumberbetween(1, 7, "\n * Select Your Option : ");
}

// Print menu
void clsTransactionsMenu::_PrintMenu() {
    system("clear");
    PrintHeaderScreen("TRANSACTIONS MENU SCREEN", "📚", Colors::Cyan);
    cout << Colors::GetGreen() << "                             ϟ\n" << Colors::RESET();
    PrintHeaderScreen("Transactions Menu", "📋", Colors::Cyan, false);
    const short width = 24;
    cout << setw(width) << setfill(' ') << " " << left << "[1] Borrow Book" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[2] Check requests" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[3] Return Book" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[4] Transactions History" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[5] Track Members" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[6] Track Books" << endl;
    cout << setw(width) << setfill(' ') << " " << left << "[7] Exit" << endl;
    cout << Colors::GetCyan() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
}
// Perform Transactions options
void clsTransactionsMenu::_PerformOption(eTransOptions option) {
    switch (option) {
        case eTransOptions::BORROW_BOOK: {
            _BorrowBook();
            break;
        }
        case eTransOptions::CHECK_REQUESTS: {
            _CheckRequests();
            break;
        }
        case eTransOptions::RETURN_BOOK: {
            _ReturnBook();
            break;
        }
        case eTransOptions::TRANS_HISTORY: {
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
    if (option != eTransOptions::EXIT && option != eTransOptions::TRANS_HISTORY) {
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

// CHECK_REQUESTS
void clsTransactionsMenu::_CheckRequests() {
    system("clear");
    clsCheckRequests::CheckRequestsScreen();
}

// RETURN_BOOK
void clsTransactionsMenu::_ReturnBook() {
    system("clear");
    clsReturnBook::ReturnBookScreen();
}
// TRANS_HISTORY
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
    clsTrackBooks::TrackBooksScreen();
}

// Transactions Menu screen
void clsTransactionsMenu::TransMenuScreen() {
    // check permisdions
    if (!CheckPermissionRights(clsUser::ePermissionFunc::TRANSACTIONS)) {
        return;
    }

    eTransOptions option;
    do {
        _PrintMenu();
        option = _GetUserChoice();
        _PerformOption(option);
    } while (option != eTransOptions::EXIT);
}
