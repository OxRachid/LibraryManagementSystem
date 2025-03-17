#ifndef CLSADDNEWMEMBER_H
#define CLSADDNEWMEMBER_H

#include "../../../Core/clsMember.h"
#include "../../clsScreen.h"
#include <string>
class clsAddNewMember : protected clsScreen {
    private:
        // print member data
        static void _PrintMemberData(clsMember member);
        // Get Unique AccountNumber of member
        static string _GetUniqueAccountNumber();
        // Read Memeber obj data
        static void _ReadMemberData(clsMember &member);
        // Get member obj to Add
        static clsMember _GetAddObjMode();
        // Get Role Choice
        static short _GetRoleChoice();

    public:
        // Add new Member screen
        static void AddNewMemberScreen();
};

#endif // !CLSADDNEWMEMBER_H
