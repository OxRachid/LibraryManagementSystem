#ifndef CLSDELETEMEMBER_H
#define CLSDELETEMEMBER_H

#include "../../Core/clsMember.h"
#include "../clsScreen.h"
class clsDeleteMember : protected clsScreen {
    private:
        // Print member data
        static void _PrintMemberData(clsMember member);
        // Get Member for Delete
        static clsMember _GetTargetMember();
        // Read AccountNumber for exist member
        static string _ReadAccountNumber();

    public:
        // delete member screen
        static void DeleteMemberScreen();
};

#endif // !CLSDELETEMEMBER_H
