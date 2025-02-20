#ifndef CLSTRACKMEMBERS_H
#define CLSTRACKMEMBERS_H

#include "../../Core/clsMember.h"
#include "../../Core/clsTransaction.h"
#include "../clsScreen.h"
class clsTrackMembers : protected clsScreen {
    private:
        // display trans detailes
        static void _DisplayTransDetailes(clsTransaction trans);
        // print member data
        static void _PrintMemberData(clsMember member);
        // Get targetmember
        static clsMember _GetTargetMember();
        // Print transactions history
        static void _ShowTransHistory(string accountnumber);

    public:
        // track members screen
        static void TrackMembersScreen();
};

#endif // !CLSTRACKMEMBERS_H
