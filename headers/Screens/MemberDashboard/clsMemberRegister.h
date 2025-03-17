#ifndef CLSMEMBERREGISTER_H
#define CLSMEMBERREGISTER_H

#include "../../Core/clsMember.h"
#include "../clsScreen.h"
class clsMemberRegister : protected clsScreen {
    private:
        // static bool for loading members list one time
        static bool dataleaded;

        // func to lead data from file
        static void _LoadData();
        // Get Unique AccountNumber of member
        static string _GetUniqueAccountNumber();
        // Get member obj to Add
        static clsMember _GetAddObjMode();
        // Read Memeber obj data
        static void _ReadMemberData(clsMember &member);
        // Get Role Choice
        static short _GetRoleChoice();

    public:
        // register
        static void MemberRegisterScreen();
};

#endif // !clsMemberRegister_h
