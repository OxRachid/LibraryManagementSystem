#ifndef CLSRETURNEDLIST_H
#define CLSRETURNEDLIST_H

#include "../../../../Core/clsTransaction.h"
#include "../../../clsScreen.h"
class clsReturnedList : protected clsScreen {
    private:
        // display trans details
        static void _DisplayTransDetails(clsTransaction trans);

    public:
        // list all returned
        static void ReturnedListScreen();
};

#endif // !CLSRETURNEDLIST_H
