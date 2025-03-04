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
            LIST_PENDDING,
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
        // list Pendding
        static void _ListPendding();

    public:
        // trans hustory screen
        static void TransHistoryMenuScreen();
};

#endif // !CLSTRANSHISTORYMENU_H
