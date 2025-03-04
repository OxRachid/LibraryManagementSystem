#ifndef CLSPENDDINGLIST_H
#define CLSPENDDINGLIST_H

#include "../../../Core/clsTransaction.h"
#include "../../clsScreen.h"
class clsPenddingList : protected clsScreen {
    private:
        // display trans details
        static void _DisplayTransDetails(clsTransaction trans);

    public:
        // list pendding transactions
        static void PenddingListScreen();
};

#endif // !CLSPENDDINGLIST_H
