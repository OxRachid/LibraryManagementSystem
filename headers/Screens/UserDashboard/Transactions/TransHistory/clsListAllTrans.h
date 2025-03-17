#ifndef CLSLISTALLTRANS_H
#define CLSLISTALLTRANS_H

#include "../../../../Core/clsTransaction.h"
#include "../../../clsScreen.h"
class clsListAllTrans : protected clsScreen {
    private:
        // display trans details
        static void _DisplayTransDetails(clsTransaction trans);

    public:
        // list all transactions
        static void ListAllTransScreen();
};

#endif // !CLSLISTALLTRANS_H
