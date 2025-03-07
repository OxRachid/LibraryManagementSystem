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
            MEMBER_MANAGE,
            TRANSACTIONS,
            USER_MANAGE,
            SYSYEM_MANAGE,
            LOGOUT
        };

        // func to lead data from file
        static void _LoadData();
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
        // system Manage screen
        static void _SystemManageScreen();

    public:
        // Show Main Menu Screen
        static void UserDashboardScreen();
};

#endif // !CLSUSERDASHBOARD_H
