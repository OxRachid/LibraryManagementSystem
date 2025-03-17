#ifndef CLSPROFILE_H
#define CLSPROFILE_H

#include "../../clsScreen.h"
class clsProfile : protected clsScreen {
    private:
        // display member data
        static void _DisplayMemberData();

    public:
        // Print member profile data
        static void ProfileScreen();
};

#endif // !CLSPROFILE_H
