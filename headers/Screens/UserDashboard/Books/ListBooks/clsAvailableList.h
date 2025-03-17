#ifndef CLSAVAILABLELIST_H
#define CLSAVAILABLELIST_H

#include "../../../../Core/clsBook.h"
#include "../../../clsScreen.h"
class clsAvailableList : protected clsScreen {
    private:
        // print book data
        static void _PrintBook(clsBook book);

    public:
        // Books list screen
        static void AvailableListScreen();
};

#endif // !CLSAVAILABLELIST_H
