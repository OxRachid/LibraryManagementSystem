#ifndef CLSUPDATEUSERS_H
#define CLSUPDATEUSERS_H

#include "../../../Core/clsUser.h"
#include "../../clsScreen.h"
class clsUpdateUsers : protected clsScreen {
    private:
        // Print user data
        static void _PrintUserData(clsUser &user);
        // Get User for Delete
        static clsUser _GetTargetUser();
        // Read username for target user
        static string _ReadUsername();
        // Read new data
        static void _ReadNewData(clsUser &user);
        // Read permissions
        static short _GetPermissions();

    public:
        // update user
        static void UpdateUsersScreen();
};

#endif // !CLSUPDATEUSERS_H
