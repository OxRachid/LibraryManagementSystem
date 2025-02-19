#include "../../../headers/Screens/Members/clsFindMember.h"
#include "../../../headers/Core/clsMember.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// Print member data
void clsFindMember::_PrintMemberData(clsMember member) {
    cout << endl;
    PrintHeaderScreen("[Member Data]", "👤", Colors::Blue, false, 41);
    cout << Colors::GetBlue() << left << setw(20) << setfill(' ') << " AccountNumber" << " : " << member.GetAccountNumber() << endl;
    cout << left << setw(20) << " Firstname" << " : " << member.GetFirstName() << endl;
    cout << left << setw(20) << " Lastname" << " : " << member.GetLastName() << endl;
    cout << left << setw(20) << " Email" << " : " << member.GetEmail() << endl;
    cout << left << setw(20) << " Phone" << " : " << member.GetPhone() << endl;
    cout << left << setw(20) << " Role" << " : " << member.MemberRoleToString() << endl;
    cout << left << setw(20) << " Password" << " : " << member.GetPassword() << endl;
    cout << left << setw(20) << " Borrowed Books" << " : " << member.GetTotalBorrowedBooks() << endl;
    cout << left << setw(20) << " Late Returns" << " : " << member.GetLateReturns() << endl;
    cout << left << setw(20) << " Account Status" << " : " << member.AccountStatusToString() << endl;
    cout << setw(41) << setfill('-') << "" << Colors::RESET() << endl;
}

// Get Member for Delete
clsMember clsFindMember::_GetTargetMember() {
    string AccountNumber = clsInputValidate::ReadString(" * Enter AccountNumber : ");
    return clsMember::Find(AccountNumber);
}

// Find Member Screen
void clsFindMember::FindMemberScreen() {
    PrintHeaderScreen("FIND MEMBER SCREEN", "🔍👤", Colors::Yellow);
    cout << "\n\n\n";

    // Get member
    clsMember member = _GetTargetMember();
    // check if exist
    if (!member.isEmpty()) {
        _PrintMemberData(member);
        cout << Colors::GetGreen() << " The Member Found" << Colors::RESET() << endl;
    } else {
        cout << Colors::GetRed() << " The Member Not Found" << Colors::RESET() << endl;
    }
}
