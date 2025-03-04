#ifndef CLSMEMBERMANAGE_H
#define CLSMEMBERMANAGE_H

#include "../clsScreen.h"
class clsMemberManage : protected clsScreen {
    private:
        // enum for member manage menu options
        enum enMenuOptions {
            LIST_MEMBERS = 1,
            ADD_MEMBER = 2,
            DELETE_MEMBER = 3,
            UPDATE_MEMBER = 4,
            FIND_MEMBER = 5,
            RESET = 6,
            EXIT = 7,
        };

        // get user choice
        static enMenuOptions _GetUserChoice();
        // Print Member manage menu
        static void _DisplayMenu();
        // perform member manage options
        static void _PerformMenuOption(enMenuOptions option);
        // List members screen
        static void _ListMembers();
        // Add members screen
        static void _AddNewMember();
        // Delete Members screen
        static void _DeleteMember();
        // update members screen
        static void _UpdateMember();
        // Find members screen
        static void _FindMember();
        // Reset
        static void _Reset();

    public:
        // Member manage screen
        static void MemberManageScreen();
};

#endif // !CLSMEMBERMANAGE_H
