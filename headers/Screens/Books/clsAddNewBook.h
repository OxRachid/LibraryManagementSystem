#ifndef CLSADDNEWBOOK_H
#define CLSADDNEWBOOK_H

#include "../../Core/clsBook.h"
#include "../clsScreen.h"
#include <string>

class clsAddNewBook : protected clsScreen {
    private:
        // Read publication date
        static clsDate _ReadPublicationDate();
        // Read ISBN
        static string _ReadISBN();
        // Read book data
        static bool _ReadBookData(clsBook &book);
        // print new book data
        static void _PrintBookData(clsBook book);

    public:
        // Add new book screen
        static void AddNewBookScreen();
};

#endif // !CLSADDNEWBOOK_H
