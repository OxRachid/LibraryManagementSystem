#ifndef CLSLISTMENU_H
#define CLSLISTMENU_H

#include "../../clsScreen.h"
class clsListMenu : protected clsScreen {
    private:
        // enum for list ListBooksMenu
        enum eListOptions {
            LIST_ALL = 1,
            LIST_AVAILABLE,
            EXIT
        };

        // Get user choice
        static eListOptions _GetUserChoice();
        // print menu
        static void _PrintMenu();
        // perform option
        static void _PerformOption(eListOptions option);
        // List All
        static void _ListAllBooks();
        // List available
        static void _ListAvailableBooks();

    public:
        // List books menu
        static void ListMenuScreen();
};

#endif // !CLSLISTMENU_H
