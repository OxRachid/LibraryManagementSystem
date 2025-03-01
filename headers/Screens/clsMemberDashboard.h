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
            LIST_BOOKS = 2,
            FIND_BOOKS = 3,
            BORROW_BOOK = 4,
            RETURN_BOOK = 5,
            MEMBER_HISTORY = 6,
            LOGOUT = 7
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
        static void _BorrowBook();
        // RETURN_BOOK screen
        static void _ReturnBook();
        // HISTORY
        static void _MemberHistory();

    public:
        // member dashboard Screen
        static void MemberDashboardScreen();
};

#endif // !CLSMEMBERDASHBOARD_H
