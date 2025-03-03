#include "../../../headers/Screens/Transactions/clsTrackMembers.h"
#include "../../../headers/Core/clsMember.h"
#include "../../../headers/Core/clsTransaction.h"
#include "../../../headers/Core/global.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// display trans detailes
void clsTrackMembers::_DisplayTransDetailes(clsTransaction trans) {
    short width = 24;
    cout << Colors::GetYellow() << setfill(' ') << left << setw(width - 17) << trans.GetTrans_ID() << left << setw(width - 17) << trans.GetAccountNumber() << left << setw(width - 16) << trans.GetBookID() << left << setw(width - 13) << clsDate::ConvertDateToString(trans.GetCheckoutDate()) << left << setw(width - 13) << clsDate::ConvertDateToString(trans.GetDueDate()) << left << setw(width - 13) << clsDate::ConvertDateToString(trans.GetReturnDate()) << left << setw(width - 13) << trans.BookStatusToString() << Colors::RESET() << endl;
}

// Print transactions history
void clsTrackMembers::_ShowTransHistory(string AccountNumber) {
    // Get All transactions list from static vector
    const vector<clsTransaction> &vMemberTrans = clsTransaction::GetTransactionsForMember(AccountNumber);
    PrintHeaderScreen("MEMBER HISTORY", to_string(vMemberTrans.size()), Colors::Cyan, false);
    short width = 24;
    cout << Colors::GetCyan() << setfill(' ') << left << setw(width - 17) << "TrsID" << left << setw(width - 17) << "Ac-N" << left << setw(width - 16) << "BookID" << left << setw(width - 13) << "OUT-Date" << left << setw(width - 13) << "Due-Date" << left << setw(width - 13) << "ReturnDate" << left << setw(width - 13) << "Status" << Colors::RESET() << endl;
    cout << Colors::GetCyan() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
    if (vMemberTrans.empty()) {
        cout << Colors::GetRed() << "              No Data Found" << Colors::RESET() << endl;
    } else {
        for (const clsTransaction &T : vMemberTrans) {
            _DisplayTransDetailes(T);
        }
    }
    cout << Colors::GetCyan() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
}

// print member data
void clsTrackMembers::_PrintMemberData(clsMember member) {
    cout << endl;
    PrintHeaderScreen("[Member Data]", "👤", Colors::Blue, false, 41);
    cout << Colors::GetBlue() << left << setw(20) << setfill(' ') << " AccountNumber" << " : " << member.GetAccountNumber() << endl;
    cout << left << setw(20) << " Firstname" << " : " << member.GetFirstName() << endl;
    cout << left << setw(20) << " Lastname" << " : " << member.GetLastName() << endl;
    cout << left << setw(20) << " Email" << " : " << member.GetEmail() << endl;
    cout << left << setw(20) << " Phone" << " : " << member.GetPhone() << endl;
    cout << left << setw(20) << " Role" << " : " << member.MemberRoleToString() << endl;
    cout << left << setw(20) << " Borrowed Books" << " : " << member.GetTotalBorrowedBooks() << endl;
    cout << left << setw(20) << " Late Returns" << " : " << member.GetLateReturns() << endl;
    cout << left << setw(20) << " Account Created on" << " : " << clsDate::ConvertDateToString(member.GetAccountCreated_on()) << endl;
    cout << left << setw(20) << " Account Status" << " : " << member.AccountStatusToString() << endl;
    cout << setw(41) << setfill('-') << "" << Colors::RESET() << endl;
}

// Get targetmember
clsMember clsTrackMembers::_GetTargetMember() {
    string AccountNumber;
    bool isExist = false;
    do {
        if (isExist) {
            cout << Colors::GetRed() << " [ This AccountNumber Not Exist ]" << Colors::RESET() << endl;
        }
        AccountNumber = clsInputValidate::ReadString(" * Enter Target Member AccountNumber : ");
        isExist = !clsMember::isMemberExist(AccountNumber);
    } while (isExist);
    return clsMember::Find(AccountNumber);
}

// track members screen
void clsTrackMembers::TrackMembersScreen() {
    PrintHeaderScreen("TRACK MEMBER", "👓", Colors::Magenta);
    cout << "\n\n\n";

    // Get targetmember
    clsMember TargetMember = CurrMember;
    if (CurrMember.isEmpty()) {
        TargetMember = _GetTargetMember();
        // Show member detailes
        cout << "\n [ PROFILE ]" << endl;
        _PrintMemberData(TargetMember);
    }

    // Display his Transactions history
    cout << "\n [ HISTORY ]\n" << endl;
    _ShowTransHistory(TargetMember.GetAccountNumber());
}
