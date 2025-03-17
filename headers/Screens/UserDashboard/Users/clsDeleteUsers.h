#ifndef CLSDELETEUSERS_H
#define CLSDELETEUSERS_H

#include "../../../Core/clsUser.h"
#include "../../clsScreen.h"
class clsDeleteUsers : protected clsScreen {
    private:
        // Print user data
        static void _PrintUserData(clsUser &user);
        // Get User for Delete
        static clsUser _GetTargetUser();
        // Read username for target user
        static string _ReadUsername();

    public:
        // delete user screen
        static void DeleteUserScreen();
};

#endif // !CLSDELETEUSERS_H
