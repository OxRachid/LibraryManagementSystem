#ifndef CLSCANCELEDLIST_H
#define CLSCANCELEDLIST_H

#include "../../../../Core/clsTransaction.h"
#include "../../../clsScreen.h"
class clsCanceledList : protected clsScreen {
    private:
        // display trans details
        static void _DisplayTransDetails(clsTransaction trans);

    public:
        // list canceled transactions
        static void CanceledListScreen();
};

#endif // !CLSCANCELEDLIST_H
