#ifndef CLSUPDATEMEMBER_H
#define CLSUPDATEMEMBER_H

#include "../../Core/clsMember.h"
#include "../clsScreen.h"
class clsUpdateMember : protected clsScreen {
    private:
        // Print member data
        static void _PrintMemberData(clsMember member);
        // Get Member for Delete
        static clsMember _GetTargetMember();
        // Read AccountNumber for exist member
        static string _ReadAccountNumber();
        // Read new data
        static void _ReadNewData(clsMember &member);
        // Get Role Choice
        static string _UpdateRoleChoice();

    public:
        // Update Target member screen
        static void UpdateMemberScreen();
};

#endif // !CLSUPDATEMEMBER_H
