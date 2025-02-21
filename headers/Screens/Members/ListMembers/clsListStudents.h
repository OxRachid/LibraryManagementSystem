#ifndef CLSLISTSTUDENTS_H
#define CLSLISTSTUDENTS_H

#include "../../../Core/clsMember.h"
#include "../../clsScreen.h"
class clsListStudents : protected clsScreen {
    private:
        // Display Member data
        static void _DisplayMemberData(clsMember member);

    public:
        // List All members
        static void ListStudentsScreen();
};

#endif // !CLSLISTSTUDENTS_H
