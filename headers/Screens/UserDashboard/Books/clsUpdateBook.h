#ifndef CLSUPDATEBOOK_H
#define CLSUPDATEBOOK_H

#include "../../../Core/clsBook.h"
#include "../../../Lib/clsDate.h"
#include "../../clsScreen.h"

class clsUpdateBook : protected clsScreen {
    private:
        // Get date from user
        static clsDate _GetDateFromUser();
        // Read publication date
        static clsDate _ReadPublicationDate();
        // Read ISBN
        static string _ReadISBN();
        // Read Book ID
        static int _ReadBookID();
        // Get Book for Delete
        static clsBook _GetBook();
        // print book data
        static void _PrintBook(clsBook Book);
        // Read New book data
        static void _ReadNewBookData(clsBook &book);

    public:
        // Update book
        static void UpdateBookScreen();
};

#endif // !CLSUPDATEBOOK_H
