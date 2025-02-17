#ifndef CLSBORROWBOOK_H
#define CLSBORROWBOOK_H

#include "../../Core/clsBook.h"
#include "../../Core/clsMember.h"
#include "../clsScreen.h"
class clsBorrowBook : protected clsScreen {
    private:
        // Get targetmember
        static clsMember _GetTargetMember();
        // Get targetbook
        static clsBook _GetTargetBook();
        // Print member data
        static void _PrintMemberData(clsMember member);
        // Print Book data
        static void _PrintBookData(clsBook book);

    public:
        // Borrow Book Screen
        static void BorrowBookScreen();
};

#endif // !CLSBORROWBOOK_H
