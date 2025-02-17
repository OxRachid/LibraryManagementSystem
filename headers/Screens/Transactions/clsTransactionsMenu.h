#ifndef CLSTRANSACTIONSMENU_H
#define CLSTRANSACTIONSMENU_H

#include "../clsScreen.h"
class clsTransactionsMenu : protected clsScreen {
    private:
        // enum for Transactions menu options
        enum eTransOptions {
            BORROW_BOOK = 1,
            RETURN_BOOK = 2,
            BORROWING_HISTORY = 3,
            TRACK_MEMBER = 4,
            TRACK_BOOK = 5,
            EXIT = 6
        };
        // Print menu
        static void _PrintMenu();
        // get user choice
        static eTransOptions _GetUserChoice();
        // Perform Transactions options
        static void _PerformOption(eTransOptions option);
        // BORROW_BOOK
        static void _BorrowBook();
        // RETURN_BOOK
        static void _ReturnBook();
        // BORROWING_HISTORY
        static void _BorrowingHistory();
        // TRACK_MEMBER
        static void _TrackMemberActivity();
        // TRACK_BOOK
        static void _TrackBookActivity();

    public:
        // Transactions Menu screen
        static void TransMenuScreen();
};

#endif // !CLSTRANSACTIONSMENU_H
