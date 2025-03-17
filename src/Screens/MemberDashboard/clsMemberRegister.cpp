#include "../../../headers/Screens/MemberDashboard/clsMemberRegister.h"
#include "../../../headers/Core/clsMember.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include <cstdlib>
#include <iostream>
using namespace std;

bool clsMemberRegister::dataleaded = false;

// func to lead data from file
void clsMemberRegister::_LoadData() {
    // load data from files
    if (!dataleaded) {
        // load Members from file
        clsMember::LoadMembersFromFile();
    }
}

// Get Unique AccountNumber of member
string clsMemberRegister::_GetUniqueAccountNumber() {
    string AccountNumber;
    bool isExist = false;
    do {
        if (isExist) {
            cout << Colors::GetRed() << " [ This AccountNumber is already Exist ]" << Colors::RESET() << endl;
        }

        AccountNumber = clsInputValidate::ReadString(" Enter AccountNumber : ");
        isExist = clsMember::isMemberExist(AccountNumber);
    } while (isExist);
    return AccountNumber;
}
// Get member obj to Add
clsMember clsMemberRegister::_GetAddObjMode() {
    string AccountNumber = _GetUniqueAccountNumber();
    return clsMember::GetAddNewMemberObj(AccountNumber);
}

// Get Role Choice
short clsMemberRegister::_GetRoleChoice() {
    return clsInputValidate::Readnumberbetween(1, 2, " Role! [1] Student [2] Teacher : ");
}

// Read Memeber obj data
void clsMemberRegister::_ReadMemberData(clsMember &member) {
    member.SetFirstName(clsInputValidate::ReadString(" Firstname : "));
    member.SetLastName(clsInputValidate::ReadString(" Lastname : "));
    member.SetEmail(clsInputValidate::ReadString(" Email : "));
    member.SetPhone(clsInputValidate::ReadString(" Phone : "));
    member.SetRole(_GetRoleChoice());
    member.SetPassword(clsInputValidate::ReadStringGreaterThan(5, " Password : "));
}

// register
void clsMemberRegister::MemberRegisterScreen() {
    PrintHeaderScreen("REGISTER", "+👤", Colors::Magenta, false);
    cout << Colors::GetGreen() << "                             ϟ\n\n" << Colors::RESET();
    _LoadData();

    // Get Member Obj to Add
    clsMember NewMember = _GetAddObjMode();

    // Read Member obj Data
    _ReadMemberData(NewMember);

    // Save the new member to file
    clsMember::enSaveMode Result = NewMember.save();
    switch (Result) {
        case clsMember::enSaveMode::SAVE_SUCCESS: {
            cout << Colors::GetGreen() << " Your account has been created successfully  \n You can now log in. " << Colors::RESET() << endl;
            break;
        }
        case clsMember::enSaveMode::SAVE_FAILED: {
            cout << Colors::GetRed() << " [ The Process Failed ]" << Colors::RESET() << endl;
            break;
        }
        default:
            break;
    }
}
