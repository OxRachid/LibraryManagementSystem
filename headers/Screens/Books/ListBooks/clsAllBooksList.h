#ifndef CLSALLBOOKSLIST_H
#define CLSALLBOOKSLIST_H

#include "../../../Core/clsBook.h"
#include "../../clsScreen.h"

class clsAllBooksList : protected clsScreen {
    private:
        // print book data
        static void _PrintBook(clsBook book);

    public:
        // Books list screen
        static void AllBooksListScreen();
};

#endif // ! CLSALLBOOKSLIST_H
