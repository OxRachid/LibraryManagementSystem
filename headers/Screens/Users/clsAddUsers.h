#ifndef CLSADDUSERS_H
#define CLSADDUSERS_H

#include "../../Core/clsUser.h"
#include "../clsScreen.h"
#include <string>
class clsAddUser : protected clsScreen {
    private:
        // print user data
        static void _PrintUserData(clsUser &user);
        // Get Unique username of user
        static string _GetUniqueUsername();
        // Read user obj data
        static void _ReadUserData(clsUser &user);
        // Get user obj to Add
        static clsUser _GetAddObjMode();

    public:
        // Add new User screen
        static void AddUserScreen();
};

#endif // !CLSADDUSERS_H
