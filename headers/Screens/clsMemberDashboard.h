#ifndef CLSMEMBERDASHBOARD_H
#define CLSMEMBERDASHBOARD_H

#include "clsScreen.h"
class clsMemberDashboard : protected clsScreen {
    private:
        // Declare static variable
        static bool dataLoaded;

        // enum for menu menu Options
        enum eMenuOptions {
            PROFILE = 1,
            LIST_BOOKS,
            FIND_BOOKS,
            BORROW_REQUEST,
            CANCEL_REQUEST,
            MEMBER_HISTORY,
            LOGOUT
        };

        // func to lead data from file
        static void _LoadData();
        // print main menu
        static void _PrintMenu();
        // Read user choice
        static eMenuOptions _GetUserChoice();
        // Perform main menu Options
        static void _PerformOption(eMenuOptions option);
        // PROFILE screen
        static void _Profile();
        // LIST_BOOKS screen
        static void _ListBooks();
        // FIND_BOOKS screen
        static void _FindBooks();
        // BORROW_BOOK screen
        static void _BorrowRequest();
        // CANCEL_REQUEST screen
        static void _CancelRequest();
        // HISTORY
        static void _MemberHistory();

    public:
        // member dashboard Screen
        static void MemberDashboardScreen();
};

#endif // !CLSMEMBERDASHBOARD_H
