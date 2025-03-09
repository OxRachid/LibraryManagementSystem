#ifndef CLSBORROWREQUEST_H
#define CLSBORROWREQUEST_H

#include "../../Core/clsBook.h"
#include "../../Core/clsMember.h"
#include "../../Core/clsTransaction.h"
#include "../clsScreen.h"
class clsBorrowRequest : protected clsScreen {
    private:
        // Get targetbook
        static clsBook _GetTargetBook();
        // Print targetTrans data
        static void _PrintTransData(clsTransaction &record);
        // Print Book data
        static void _PrintBookData(clsBook book);

    public:
        // Borrow Book Screen
        static void BorrowRequestScreen();
};

#endif // !CLSBORROWREQUEST_H
