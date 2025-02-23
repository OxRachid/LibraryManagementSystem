#ifndef CLSUSERSMANAGE_H
#define CLSUSERSMANAGE_H

#include "../clsScreen.h"
class clsUsersManage : protected clsScreen {
    private:
        // enum for member manage menu options
        enum enMenuOptions {
            LIST_USERS = 1,
            ADD_USER = 2,
            DELETE_USER = 3,
            UPDATE_USER = 4,
            FIND_USER = 5,
            EXIT = 6,
        };

        // get user choice
        static enMenuOptions _GetUserChoice();
        // Print User manage menu
        static void _DisplayMenu();
        // perform member manage options
        static void _PerformOption(enMenuOptions option);
        // List members screen
        static void _ListUsers();
        // Add members screen
        static void _AddNewUser();
        // Delete Users screen
        static void _DeleteUser();
        // update members screen
        static void _UpdateUser();
        // Find members screen
        static void _FindUser();

    public:
        // User manage screen
        static void UsersManageScreen();
};

#endif // !CLSUSERSMANAGE_H
