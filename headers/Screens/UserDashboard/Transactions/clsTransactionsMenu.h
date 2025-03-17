#ifndef CLSTRANSACTIONSMENU_H
#define CLSTRANSACTIONSMENU_H

#include "../../clsScreen.h"
class clsTransactionsMenu : protected clsScreen {
    private:
        // enum for Transactions menu options
        enum eTransOptions {
            BORROW_BOOK = 1,
            CHECK_REQUESTS,
            RETURN_BOOK,
            TRANS_HISTORY,
            TRACK_MEMBER,
            TRACK_BOOK,
            EXIT
        };
        // Print menu
        static void _PrintMenu();
        // get user choice
        static eTransOptions _GetUserChoice();
        // Perform Transactions options
        static void _PerformOption(eTransOptions option);
        // BORROW_BOOK
        static void _BorrowBook();
        // CHECK_REQUESTS
        static void _CheckRequests();
        // RETURN_BOOK
        static void _ReturnBook();
        // TRANS_HISTORY
        static void _TransactionsHistory();
        // TRACK_MEMBER
        static void _TrackMemberActivity();
        // TRACK_BOOK
        static void _TrackBookActivity();

    public:
        // Transactions Menu screen
        static void TransMenuScreen();
};

#endif // !CLSTRANSACTIONSMENU_H
