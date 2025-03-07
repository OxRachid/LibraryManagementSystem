#include "../../../headers/Screens/Members/clsDeleteMember.h"
#include "../../../headers/Core/clsMember.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// Print member data
void clsDeleteMember::_PrintMemberData(clsMember member) {
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
    cout << left << setw(20) << " Violations" << " : " << member.GetViolations() << endl;
    cout << left << setw(20) << " Account Created on" << " : " << clsDate::ConvertDateToString(member.GetAccountCreated_on()) << endl;
    cout << left << setw(20) << " Account Status" << " : " << member.AccountStatusToString() << endl;
    cout << setw(41) << setfill('-') << "" << Colors::RESET() << endl;
}

// Read username for exist member
string clsDeleteMember::_ReadAccountNumber() {
    string AccountNumber;
    bool isExist = false;
    do {
        if (isExist) {
            cout << Colors::GetRed() << " [ This AccountNumber Not Exist ]" << Colors::RESET() << endl;
        }
        AccountNumber = clsInputValidate::ReadString(" * Enter AccountNumber : ");
        isExist = !clsMember::isMemberExist(AccountNumber);
    } while (isExist);
    return AccountNumber;
}

// Get Member for Delete
clsMember clsDeleteMember::_GetTargetMember() {
    string AccountNumber = _ReadAccountNumber();
    return clsMember::Find(AccountNumber);
}

// delete member screen
void clsDeleteMember::DeleteMemberScreen() {
    PrintHeaderScreen("DELETE MEMBER SCREEN", "-👤", Colors::Red);
    cout << "\n\n\n";
    // Get Target member obj
    clsMember TargetMember = _GetTargetMember();
    // Print TargetMember data
    _PrintMemberData(TargetMember);
    if (clsInputValidate::AskUser("\n ⊕ Are u sure u wanna delete " + TargetMember.GetAccountNumber())) {
        if (TargetMember.Delete()) {
            _PrintMemberData(TargetMember);
            cout << Colors::GetGreen() << " [ TargetMember Deleted Succesfully ]" << Colors::RESET() << endl;
        } else {
            cout << Colors::GetRed() << " [ The Process Failed ]" << Colors::RESET() << endl;
        }
    } else {
        cout << Colors::GetRed() << " [ Delete Canceled ]" << Colors::RESET() << endl;
    }
}
