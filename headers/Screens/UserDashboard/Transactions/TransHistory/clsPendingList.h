#ifndef CLSPENDDINGLIST_H
#define CLSPENDDINGLIST_H

#include "../../../../Core/clsTransaction.h"
#include "../../../clsScreen.h"
class clsPendingList : protected clsScreen {
    private:
        // display trans details
        static void _DisplayTransDetails(clsTransaction trans);

    public:
        // list pendding transactions
        static void PendingListScreen();
};

#endif // !CLSPENDDINGLIST_H
