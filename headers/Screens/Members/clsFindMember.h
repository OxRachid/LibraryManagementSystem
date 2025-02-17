#ifndef CLSFINDMEMBER_H
#define CLSFINDMEMBER_H

#include "../../Core/clsMember.h"
#include "../clsScreen.h"
class clsFindMember : protected clsScreen {
    private:
        // Print member data
        static void _PrintMemberData(clsMember member);
        // Get Target Member
        static clsMember _GetTargetMember();

    public:
        // Find Member Screen
        static void FindMemberScreen();
};

#endif // !CLSFINDMEMBER_H
