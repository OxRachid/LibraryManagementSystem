#ifndef CLSCHECKREQUESTS_H
#define CLSCHECKREQUESTS_H

#include "../../Core/clsBook.h"
#include "../../Core/clsMember.h"
#include "../../Core/clsTransaction.h"
#include "../clsScreen.h"
class clsCheckRequests : protected clsScreen {
    private:
        // get target trans
        static clsTransaction _GetTargetTrans();
        // Print targetTrans data
        static void _PrintTransData(clsTransaction &record);
        // update transaction data
        static void _updateTransData(clsTransaction &TargetTrans);

    public:
        // check requests
        static void CheckRequestsScreen();
};

#endif // !clsCheckRequests_h
