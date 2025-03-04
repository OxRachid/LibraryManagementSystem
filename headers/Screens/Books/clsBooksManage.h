#ifndef CLSBOOKSMANAGE_H
#define CLSBOOKSMANAGE_H

#include "../clsScreen.h"
class clsBooksManage : protected clsScreen {
    private:
        // enum for books manage options
        enum eMenuOptions {
            LIST_BOOKS = 1,
            ADD_BOOK = 2,
            REMOVE_BOOK = 3,
            UPDATE_BOOK = 4,
            FIND_BOOK = 5,
            RESET = 6,
            MAINMENU = 7
        };
        // get user choice
        static eMenuOptions _GetUserChoice();
        // print books menu
        static void _PrintBooksManageMenu();
        // Perform Books manage options
        static void _PerformBooksManageOptions(eMenuOptions options);
        // list all Books
        static void _ListBooksScreen();
        // Add book screen
        static void _AddBookScreen();
        // remove book screen
        static void _RemoveBookScreen();
        // update books
        static void _UpdateBookScreen();
        // find book
        static void _FindBookScreen();
        // RESET
        static void _ResetBookScreen();

    public:
        // books manage screen
        static void BooksManageScreen();
};

#endif // !CLSBOOKSMANAGE_H
