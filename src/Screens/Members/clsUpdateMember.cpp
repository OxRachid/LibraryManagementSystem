#include "../../../headers/Screens/Members/clsUpdateMember.h"
#include "../../../headers/Core/clsMember.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// Print member data
void clsUpdateMember::_PrintMemberData(clsMember member) {
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
    cout << left << setw(20) << " Account Status" << " : " << member.AccountStatusToString() << endl;
    cout << setw(41) << setfill('-') << "" << Colors::RESET() << endl;
}

// Read AccountNumber for exist member
string clsUpdateMember::_ReadAccountNumber() {
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
clsMember clsUpdateMember::_GetTargetMember() {
    string AccountNumber = _ReadAccountNumber();
    return clsMember::Find(AccountNumber);
}

// Get Role Choice
short clsUpdateMember::_UpdateRoleChoice() {
    return clsInputValidate::Readnumberbetween(0, 2, " ⊙ What's Role [0] Student [1] Teacher [2] NON ? ");
}

// Read new data
void clsUpdateMember::_ReadNewData(clsMember &member) {
    PrintHeaderScreen("Read New Data", "👤", Colors::Magenta, false, 54);
    if (clsInputValidate::AskUser("\n □ Rename firstname ")) {
        member.SetFirstName(clsInputValidate::ReadString("\n * Enter New firstname : "));
        cout << Colors::GetGreen() << " [ firstname Renamed Succesfully ]" << endl;
    }
    if (clsInputValidate::AskUser("\n □ Rename lastname ")) {
        member.SetLastName(clsInputValidate::ReadString("\n * Enter New lastname : "));
        cout << Colors::GetGreen() << " [ firstname Renamed Succesfully ]" << endl;
    }
    if (clsInputValidate::AskUser("\n □ Update Email ")) {
        member.SetEmail(clsInputValidate::ReadString("\n * Enter New Email : "));
        cout << Colors::GetGreen() << " [ Email Updated Succesfully ]" << endl;
    }
    if (clsInputValidate::AskUser("\n □ Update Phone ")) {
        member.SetPhone(clsInputValidate::ReadString("\n * Enter New Phone : "));
        cout << Colors::GetGreen() << " [ Phone updated Succesfully ]" << endl;
    }
    if (clsInputValidate::AskUser("\n □ Update Role ")) {
        member.SetRole(_UpdateRoleChoice());
        cout << Colors::GetGreen() << " [ Role updated Succesfully ]" << endl;
    }
    if (clsInputValidate::AskUser("\n □ Update Password ")) {
        member.SetPassword(clsInputValidate::ReadString("\n * Enter New Password : "));
        cout << Colors::GetGreen() << " [ Password updated Succesfully ]" << endl;
    }
    if (clsInputValidate::AskUser("\n □ Update TotalBorrowedBooks ")) {
        member.SetPhone(clsInputValidate::ReadString("\n * Enter New TotalBorrowedBooks : "));
        cout << Colors::GetGreen() << " [ TotalBorrowedBooks updated Succesfully ]" << endl;
    }
}

// Update Target member screen
void clsUpdateMember::UpdateMemberScreen() {
    PrintHeaderScreen("UPDATE MEMBER SCREEN", "🔧", Colors::Magenta);
    cout << "\n\n\n";
    // Get TargetMember
    clsMember TargetMember = _GetTargetMember();
    // Print TargetMember data
    _PrintMemberData(TargetMember);
    if (clsInputValidate::AskUser(" ⊕ Are u sure you wanna update " + TargetMember.GetAccountNumber())) {
        // Read New Data
        _ReadNewData(TargetMember);
        // Save updated member
        clsMember::enSaveMode Result = TargetMember.save();
        switch (Result) {
            case clsMember::enSaveMode::SaveSuccess: {
                _PrintMemberData(TargetMember);
                cout << Colors::GetGreen() << " [ Member Data Updated Succesfully ]" << Colors::RESET() << endl;
                break;
            }
            case clsMember::enSaveMode::SaveFailed: {
                cout << Colors::GetRed() << " [ Update Failed ]" << Colors::RESET() << endl;
                break;
            }
            default:
                break;
        }

    } else {
        cout << Colors::GetRed() << " [ Update Canceled ]" << Colors::RESET() << endl;
    }
}
