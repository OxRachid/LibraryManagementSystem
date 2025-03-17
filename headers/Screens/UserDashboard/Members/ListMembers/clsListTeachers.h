#ifndef CLSLISTTEACHERS_H
#define CLSLISTTEACHERS_H

#include "../../../../Core/clsMember.h"
#include "../../../clsScreen.h"
class clsListTeachers : protected clsScreen {
    private:
        // Display Member data
        static void _DisplayMemberData(clsMember member);

    public:
        // List All members
        static void ListTeachersScreen();
};

#endif // !CLSLISTTEACHERS_H
