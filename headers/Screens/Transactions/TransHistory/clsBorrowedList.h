#ifndef CLSBORROWEDLIST_H
#define CLSBORROWEDLIST_H

#include "../../../Core/clsTransaction.h"
#include "../../clsScreen.h"
class clsBorrowedList : protected clsScreen {
    private:
        // display trans details
        static void _DisplayTransDetails(clsTransaction trans);

    public:
        // list borrowed transactions
        static void BorrowedListScreen();
};

#endif // !CLSBORROWEDLIST_H
