#ifndef CLSLISTMEMBERSMENU_H
#define CLSLISTMEMBERSMENU_H

#include "../../../Core/clsMember.h"
#include "../../clsScreen.h"
class clsListMembersMenu : protected clsScreen {
    private:
        enum enListOptions {
            ALL_MEMBERS = 1,
            ONLY_STUDENTS = 2,
            ONLY_TEACHERS = 3,
            EXIT = 4,
        };
        // print list Menu screen
        static void _PrintMenu();
        // handle user choice
        static void _HandleUserChoice(enListOptions option);
        // list All Members
        static void _ListAllMembers();
        // List only students
        static void _ListStudents();
        // List only Teachers
        static void _ListTeachers();

    public:
        // list members screen
        static void ListMembersMenuScreen();
};

#endif // !CLSLISTMEMBERSMENU_H
