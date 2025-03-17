#ifndef CLSDELETEBOOK_H
#define CLSDELETEBOOK_H

#include "../../../Core/clsBook.h"
#include "../../clsScreen.h"

class clsDeleteBook : protected clsScreen {
    private:
        // Read Book ID
        static int _ReadBookID();
        // Get Book for Delete
        static clsBook _GetBook();
        // print new book data
        static void _PrintBook(clsBook book);

    public:
        // Delete Book screen
        static void DeleteBookScreen();
};

#endif // !CLSDELETEBOOK_H
