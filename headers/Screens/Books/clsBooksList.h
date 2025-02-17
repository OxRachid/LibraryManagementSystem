#ifndef CLSBOOKSLIST_H
#define CLSBOOKSLIST_H

#include "../../Core/clsBook.h"
#include "../clsScreen.h"

class clsBooksList : protected clsScreen {
    private:
        // print book data
        static void _PrintBook(clsBook book);

    public:
        // Books list screen
        static void BooksListScreen();
};

#endif // ! CLSBOOKSLIST_H
