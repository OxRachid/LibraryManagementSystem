#include "../../../../headers/Screens/MemberDashboard/MemberOperations/clsProfile.h"
#include "../../../../headers/Core/global.h"
#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

// display member data
void clsProfile::_DisplayMemberData() {
    cout << Colors::GetMagenta() << left << setw(20) << setfill(' ') << " AccountNumber" << " : " << CurrMember.GetAccountNumber() << endl;
    cout << left << setw(20) << " Firstname" << " : " << CurrMember.GetFirstName() << endl;
    cout << left << setw(20) << " Lastname" << " : " << CurrMember.GetLastName() << endl;
    cout << left << setw(20) << " Email" << " : " << CurrMember.GetEmail() << endl;
    cout << left << setw(20) << " Phone" << " : " << CurrMember.GetPhone() << endl;
    cout << left << setw(20) << " Role" << " : " << CurrMember.MemberRoleToString() << endl;
    cout << left << setw(20) << " Password" << " : " << CurrMember.GetPassword() << endl;
    cout << left << setw(20) << " Borrowed Books" << " : " << CurrMember.GetTotalBorrowedBooks() << endl;
    cout << left << setw(20) << " Violations" << " : " << CurrMember.GetViolations() << endl;
    cout << left << setw(20) << " Account Created on" << " : " << clsDate::ConvertDateToString(CurrMember.GetAccountCreated_on()) << endl;
    cout << left << setw(20) << " Account Status" << " : " << CurrMember.AccountStatusToString() << endl;
    cout << setw(41) << setfill('-') << "" << Colors::RESET() << endl;
}
// Print CurrMember.profile data
void clsProfile::ProfileScreen() {
    system("clear");
    PrintHeaderScreen("[PROFILE]", "👤", Colors::Magenta, false, 41);
    // print member data
    _DisplayMemberData();
}
