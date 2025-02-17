#ifndef CLSRETURNBOOK_H
#define CLSRETURNBOOK_H

#include "../../Core/clsBook.h"
#include "../../Core/clsBorrowRecord.h"
#include "../../Core/clsMember.h"
#include "../clsScreen.h"
class clsReturnBook : protected clsScreen {
    private:
        // Get target Transaction
        static clsBorrowRecord _GetTargetTransaction(string &accountnumber, int &bookID);
        // Print member data
        static void _PrintMemberData(clsMember member);
        // Print Book data
        static void _PrintBookData(clsBook book);
        // Print Transaction data
        static void _PrintTransData(clsBorrowRecord record);

    public:
        // Borrow Book Screen
        static void ReturnBookScreen();
};

#endif // !CLSRETURNBOOK_H
