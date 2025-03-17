#ifndef CLSCANCELREQUEST_H
#define CLSCANCELREQUEST_H

#include "../../../Core/clsTransaction.h"
#include "../../clsScreen.h"
#include <type_traits>
class clsCancelRequest : protected clsScreen {
    private:
        // get target trans
        static clsTransaction _GetTargetTrans();
        // Print targetTrans data
        static void _PrintTransData(clsTransaction &record);
        // request canceled
        static void _RequestCanceled(clsTransaction &TargetTrans);

    public:
        // Cancel Request
        static void CancelRequestScreen();
};

#endif // !clsCancelRequest_h
