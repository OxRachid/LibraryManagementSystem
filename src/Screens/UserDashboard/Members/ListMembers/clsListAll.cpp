#include "../../../../../headers/Screens/UserDashboard/Members/ListMembers/clsListAll.h"
#include "../../../../../headers/Core/clsMember.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Display Member data
void clsListAll::_DisplayMemberData(clsMember member) {
    short width = 14;
    cout << Colors::GetBlue() << setfill(' ') << left << setw(width) << member.GetFullName() << left << setw(width - 5) << member.MemberRoleToString() << left << setw(width - 4) << member.GetAccountNumber() << left << setw(width) << member.GetPassword() << left << setw(width - 3) << member.GetTotalBorrowedBooks() << left << setw(width - 6) << member.AccountStatusToString() << Colors::RESET() << endl;
}

// list All Members
void clsListAll::ListAllMembersScreen() {
    system("clear");
    // get members list from static vector
    const vector<clsMember> &vMembers = clsMember::GetMembersList();
    PrintHeaderScreen("All Members", to_string(vMembers.size()), Colors::Cyan, true);
    short width = 14;
    cout << Colors::GetCyan() << setfill(' ') << left << setw(width) << "Fullname" << left << setw(width - 5) << "Role" << left << setw(width - 4) << "A-Number" << left << setw(width) << "Password" << left << setw(width - 3) << "TB-Books" << left << setw(width - 6) << "Status" << Colors::RESET() << endl;
    cout << Colors::GetCyan() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
    if (vMembers.empty()) {
        cout << Colors::GetRed() << "          No Data Found" << Colors::RESET() << endl;
    } else {
        for (const clsMember &M : vMembers) {
            _DisplayMemberData(M);
        }
    }
    cout << Colors::GetCyan() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
}
