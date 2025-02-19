#ifndef CLSTRANSHISTORYMENU_H
#define CLSTRANSHISTORYMENU_H

#include "../../clsScreen.h"
class clsTransHistoryMenu : protected clsScreen {
    private:
        // enum for list options
        enum enTransMenuOptions {
            LIST_ALL = 1,
            LIST_BORROWED,
            LIST_RETURNED,
            EXIT
        };
        // print main menu
        static void _PrintNenu();
        // Get User Choice
        static enTransMenuOptions _GetUserChoice();
        // perform options
        static void _PerformOption(enTransMenuOptions option);
        // List all
        static void _ListAll();
        // list borrowed
        static void _ListBorrowed();
        // list returned
        static void _ListReturned();

    public:
        // trans hustory screen
        static void TransHistoryMenu();
};

#endif // !CLSTRANSHISTORYMENU_H
