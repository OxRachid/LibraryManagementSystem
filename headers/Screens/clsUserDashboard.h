#ifndef CLSUSERDASHBOARD_H
#define CLSUSERDASHBOARD_H

#include "clsScreen.h"
class clsUserDashboard : protected clsScreen {
    private:
        // Declare static variable
        static bool dataLoaded;

        // enum for menu menu Options
        enum eUserDashboardOptions {
            BOOKS_MANAGE = 1,
            MEMBER_MANAGE = 2,
            TRANSACTIONS = 3,
            USER_MANAGE = 4,
            LOGOUT = 5
        };

        // print main menu
        static void _PrintMenu();
        // Read user choice
        static eUserDashboardOptions _GetUserChoice();
        // Perform main menu Options
        static void _PerformOption(eUserDashboardOptions Options);
        // Books Manage screen
        static void _BooksManageScreen();
        // Member Manage screen
        static void _MemberManageScreen();
        // users Manage screen
        static void _UsersManageScreen();
        // Transactions screen
        static void _TransactionScreen();

    public:
        // Show Main Menu Screen
        static void UserDashboardScreen();
};

#endif // !CLSUSERDASHBOARD_H
