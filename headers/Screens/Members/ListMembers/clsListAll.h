#ifndef CLSLISTALL_H
#define CLSLISTALL_H

#include "../../../Core/clsMember.h"
#include "../../clsScreen.h"
class clsListAll : protected clsScreen {
    private:
        // Display Member data
        static void _DisplayMemberData(clsMember member);

    public:
        // List All members
        static void ListAllMembersScreen();
};

#endif // !CLSLISTALL_H
