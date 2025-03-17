#ifndef CLSUPDATEMEMBER_H
#define CLSUPDATEMEMBER_H

#include "../../../Core/clsMember.h"
#include "../../clsScreen.h"
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
        static short _UpdateRoleChoice();
        // Get account status
        static clsMember::eAccountStatus _UpdateAccountStatus();

    public:
        // Update Target member screen
        static void UpdateMemberScreen();
};

#endif // !CLSUPDATEMEMBER_H
