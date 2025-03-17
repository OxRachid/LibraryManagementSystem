#ifndef CLSFINDUSERS_H
#define CLSFINDUSERS_H

#include "../../../Core/clsUser.h"
#include "../../clsScreen.h"
class clsFindUsers : protected clsScreen {
    private:
        // Print user data
        static void _PrintUserData(clsUser &user);
        // Get Target User
        static clsUser _GetTargetUser();

    public:
        // Find Users screen
        static void FindUsersScreen();
};

#endif // !CLSFINDUSERS_H
