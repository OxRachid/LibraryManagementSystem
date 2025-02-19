#include "../../../headers/Screens/Members/clsAddNewMember.h"
#include "../../../headers/Core/clsMember.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// print member data
void clsAddNewMember::_PrintMemberData(clsMember member) {
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

// Get Unique AccountNumber of member
string clsAddNewMember::_GetUniqueAccountNumber() {
    PrintHeaderScreen("Read Member Data", "👤", Colors::Magenta, false, 54);
    string AccountNumber;
    bool isExist = false;
    do {
        if (isExist) {
            cout << Colors::GetRed() << " [ This AccountNumber is already Exist ]" << Colors::RESET() << endl;
        }

        AccountNumber = clsInputValidate::ReadString(" ⊙ Enter AccountNumber : ");
        isExist = clsMember::isMemberExist(AccountNumber);
    } while (isExist);
    return AccountNumber;
}

// Get Role Choice
short clsAddNewMember::_GetRoleChoice() {
    return clsInputValidate::Readnumberbetween(0, 2, " ⊙ What's Your Role [0] Student [1] Teacher [2] NON ? ");
}

// Read Memeber obj data
void clsAddNewMember::_ReadMemberData(clsMember &member) {
    member.SetFirstName(clsInputValidate::ReadString(" ⊙ Enter Firstname : "));
    member.SetLastName(clsInputValidate::ReadString(" ⊙ Enter Lastname : "));
    member.SetEmail(clsInputValidate::ReadString(" ⊙ Enter Email : "));
    member.SetPhone(clsInputValidate::ReadString(" ⊙ Enter Phone : "));
    member.SetRole(_GetRoleChoice());
    member.SetPassword(clsInputValidate::ReadString(" ⊙ Enter Password : "));
}

// Get member obj to Add
clsMember clsAddNewMember::_GetAddObjMode() {
    string AccountNumber = _GetUniqueAccountNumber();
    return clsMember::GetAddNewMemberObj(AccountNumber);
}

// Add new Member screen
void clsAddNewMember::AddNewMemberScreen() {
    PrintHeaderScreen("ADD MEMBER SCREEN", "+👤", Colors::Yellow);
    cout << "\n\n\n";

    // Get Member Obj to Add
    clsMember member = _GetAddObjMode();
    // Read Member obj Data
    _ReadMemberData(member);
    // Save the new member to file
    clsMember::enSaveMode Result = member.save();
    switch (Result) {
        case clsMember::enSaveMode::SaveSuccess: {
            _PrintMemberData(member);
            cout << Colors::GetGreen() << " [ Member Added Succesfully ]" << Colors::RESET() << endl;
            break;
        }
        case clsMember::enSaveMode::SaveFailed: {
            cout << Colors::GetRed() << " [ The Proccess Failed ]" << Colors::RESET() << endl;
            break;
        }
        default:
            break;
    }
}
