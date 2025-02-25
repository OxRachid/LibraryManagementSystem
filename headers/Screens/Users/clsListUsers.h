#ifndef CLSLISTUSERS_H
#define CLSLISTUSERS_H

#include "../../Core/clsUser.h"
#include "../clsScreen.h"
class clsListUsers : protected clsScreen {
    private:
        // display user details
        static void _DisplsyUserDetails(clsUser user);

    public:
        // list all Users
        static void ListUsersScreen();
};

#endif // !CLSLISTUSERS_H
