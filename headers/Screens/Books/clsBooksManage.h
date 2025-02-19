#ifndef CLSBOOKSMANAGE_H
#define CLSBOOKSMANAGE_H

#include "../clsScreen.h"
class clsBooksManage : protected clsScreen {
    private:
        // enum for books manage options
        enum enBooksManageOptions {
            eListBooks = 1,
            eAddBook = 2,
            eRemoveBook = 3,
            eUpdateBook = 4,
            eFindBook = 5,
            eMainMenu = 6
        };
        // get user choice
        static enBooksManageOptions _GetUserChoice();
        // print books menu
        static void _PrintBooksManageMenu();
        // Perform Books manage options
        static void _PerformBooksManageOptions(enBooksManageOptions options);
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

    public:
        // books manage screen
        static void BooksManageScreen();
};

#endif // !CLSBOOKSMANAGE_H
