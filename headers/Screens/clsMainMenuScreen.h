#ifndef CLSMAINMENUSCREEN_H
#define CLSMAINMENUSCREEN_H

#include "clsScreen.h"
class clsMainMenuScreen : protected clsScreen {
    private:
        // Declare static variable
        static bool dataLoaded;

        // enum for menu menu Options
        enum enMainMenuOptions {
            eBooksManage = 1,
            eMemberManage = 2,
            eTransactions = 3,
            eUserManage = 4,
            eLogout = 5
        };

        // print main menu
        static void _PrintMainMenu();
        // Read user choice
        static enMainMenuOptions _GetUserChoice();
        // Perform main menu Options
        static void _PerformMainMenuOptions(enMainMenuOptions Options);
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
        static void MainMenuScreen();
};

#endif // !CLSMAINMENUSCREEN_H
