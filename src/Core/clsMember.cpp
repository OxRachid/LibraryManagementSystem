#include "../../headers/Core/clsMember.h"
#include "../../headers/Lib/clsString.h"
#include "../../headers/Lib/constants.h"
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// Define members stored file
const string MembersFile = "data/Members.txt";

// define static vector
vector<clsMember> clsMember::vMembers = {};

// constructor parameter
clsMember::clsMember(eMemberMode mode, string accountnumber, string password, string firstname, string lastname, string email, string phone, eMemberRole role, short totalborrowedbooks, short violations, clsDate accountcreated_on, eAccountStatus status)
    : clsPerson(firstname, lastname, email, phone) {
    _Mode = mode;
    _AccountNumber = accountnumber;
    _Password = password;
    _Role = role;
    _TotalBorrowedBooks = totalborrowedbooks;
    _Violations = violations;
    _AccountCreated_on = accountcreated_on;
    _AccountStatus = status;
}

// setter
void clsMember::SetPassword(string password) {
    _Password = password;
}
void clsMember::SetRole(short role) {
    _Role = (eMemberRole)role;
}
void clsMember::SetTotalBorrowedBooks(short total) {
    _TotalBorrowedBooks = total;
}
void clsMember::SetViolations(short value) {
    _Violations = value;
}
void clsMember::UpdateLateReturns() {
    ++_Violations;
    _updateMember();
}
void clsMember::SetAccountCreated_on(clsDate accountcreated_on) {
    _AccountCreated_on = accountcreated_on;
}
void clsMember::SetAccountStatus(eAccountStatus status) {
    _AccountStatus = status;
}
// getter
string clsMember::GetAccountNumber() {
    return _AccountNumber;
}
string clsMember::GetPassword() {
    return _Password;
}
clsMember::eMemberRole clsMember::GetRole() {
    return _Role;
}

short clsMember::GetViolations() {
    return _Violations;
}
short clsMember::GetTotalBorrowedBooks() {
    return _TotalBorrowedBooks;
}
clsDate clsMember::GetAccountCreated_on() {
    return _AccountCreated_on;
}
clsMember::eAccountStatus clsMember::GetAccountStatus() {
    return _AccountStatus;
}

int clsMember::TotalMembers_Size() {
    return vMembers.size();
}
int clsMember::Students_Size() {
    vector<clsMember> vStudents = GetSpecificMembersList();
    return vStudents.size();
}
int clsMember::Teachers_Size() {
    vector<clsMember> vTeachers = GetSpecificMembersList(false);
    return vTeachers.size();
}

// is empty
bool clsMember::isEmpty() {
    return (_Mode == eMemberMode::EmptyMode);
}

// Get Empty member obj
clsMember clsMember::_GetEmptyMemberObj() {

    return clsMember(eMemberMode::EmptyMode, // Member mode (empty mode, possibly a placeholder)
        EMPTY_STR,                           // Account number (empty)
        EMPTY_STR,                           // Password (empty)
        EMPTY_STR,                           // First name (empty)
        EMPTY_STR,                           // Last name (empty)
        EMPTY_STR,                           // Email (empty)
        EMPTY_STR,                           // Phone (empty)
        eMemberRole::NON,                    // Member role (none)
        DEFAULT_INT,                         // Total borrowed books (default integer value)
        DEFAULT_INT,                         //  violations (default integer value)
        DEFAULT_DATE,                        // accountcreated_on
        eAccountStatus::BLOCKED              // Account status (blocked)
    );
}
// Get Add new member obj
clsMember clsMember::GetAddNewMemberObj(string accountnumber) {
    return clsMember(eMemberMode::AddNewMode, // Member mode
        accountnumber,                        // Account number
        EMPTY_STR,                            // Password
        EMPTY_STR,                            // First name
        EMPTY_STR,                            // Last name
        EMPTY_STR,                            // Email
        EMPTY_STR,                            // Phone
        eMemberRole::NON,                     // Member role
        DEFAULT_INT,                          // Total borrowed books
        DEFAULT_INT,                          // violations (default integer value)
        clsDate(),                            // accountcreated_on
        eAccountStatus::ACTIVE                // Account status
    );
}

// Convert line to member obj
clsMember clsMember::_LineToMember(string line, string seperator) {
    vector<string> vStr = clsString::Split(line, seperator);

    return clsMember(eMemberMode::UpdateMode, // Member mode (update existing member)
        vStr[0],                              // Account number
        vStr[1],                              // Password
        vStr[2],                              // First name
        vStr[3],                              // Last name
        vStr[4],                              // Email
        vStr[5],                              // Phone
        (eMemberRole)stoi(vStr[6]),           // Member role (converted from string to enum)
        stoi(vStr[7]),                        // Total borrowed books (converted from string to integer)
        stoi(vStr[8]),                        // violations
        clsDate(vStr[9]),                     // accountcreated_on
        (eAccountStatus)stoi(vStr[10])        // Account status (converted from string to enum)
    );
}
// convert member obj to line
string clsMember::_MemberToLine(string seperator) {
    string line = "";
    line += _AccountNumber + seperator;
    line += _Password + seperator;
    line += GetFirstName() + seperator;
    line += GetLastName() + seperator;
    line += GetEmail() + seperator;
    line += GetPhone() + seperator;
    line += to_string((short)_Role) + seperator;
    line += to_string(_TotalBorrowedBooks) + seperator;
    line += to_string(_Violations) + seperator;
    line += _AccountCreated_on.ConvertDateToString() + seperator;
    line += to_string((short)_AccountStatus);

    return line;
}

// is member exist search by accountnumber
bool clsMember::isMemberExist(string accountnumber) {
    clsMember member = Find(accountnumber);
    return (!member.isEmpty());
}

// is member exist search by accountnumber and password
bool clsMember::isMemberExist(string accountnumber, string password) {
    clsMember member = Find(accountnumber, password);
    return (!member.isEmpty());
}

// Find member by accountnumber
clsMember clsMember::Find(string accountnumber) {
    auto it = find_if(vMembers.begin(), vMembers.end(), [&](clsMember &member) {
        return (member.GetAccountNumber() == accountnumber);
    });
    if (it != vMembers.end()) {
        return *it;
    }
    // if member taget not found then return empty obj
    return _GetEmptyMemberObj();
}

// Find member by accountnumber and password
clsMember clsMember::Find(string accountnumber, string password) {
    auto it = find_if(vMembers.begin(), vMembers.end(), [&](clsMember &member) {
        return (member.GetAccountNumber() == accountnumber && member.GetPassword() == password);
    });
    if (it != vMembers.end()) {
        return *it;
    }
    // if member taget not found then return empty obj
    return _GetEmptyMemberObj();
}
// Load Memebrs from file
void clsMember::LoadMembersFromFile() {
    // clear vector befor Load data
    vMembers.clear();

    fstream file;
    file.open(MembersFile, ios::in);
    if (file.is_open()) {
        string line = "";
        while (getline(file, line)) {
            clsMember member = _LineToMember(line);
            vMembers.push_back(member);
        }
        file.close();
    }
}
// Save Memebrs to file
void clsMember::SaveMembersToFile() {
    fstream file;
    file.open(MembersFile, ios::out);
    if (file.is_open()) {
        for (clsMember &member : vMembers) {
            file << member._MemberToLine() << endl;
        }
        file.close();
    }
}

// Get Members list from static  vector
vector<clsMember> &clsMember::GetMembersList() {
    return vMembers;
}

// Get Students or Teachers Members list from static  vector
vector<clsMember> clsMember::GetSpecificMembersList(bool ByStudents) {
    vector<clsMember> vSpecificMembers;
    for (clsMember &member : vMembers) {
        if (ByStudents) {
            if (member.GetRole() == eMemberRole::STUDENT) {
                vSpecificMembers.push_back(member);
            }
        } else {
            if (member.GetRole() == eMemberRole::TEACHER) {
                vSpecificMembers.push_back(member);
            }
        }
    }

    return vSpecificMembers;
}

// add member
void clsMember::_addMember() {
    // Add new member to staticvector
    vMembers.push_back(*this);
    // save update vector to file
    SaveMembersToFile();
}
// update member
void clsMember::_updateMember() {
    // sesrch for TargetMember
    auto it = find_if(vMembers.begin(), vMembers.end(), [&](clsMember &member) {
        return (member.GetAccountNumber() == this->GetAccountNumber());
    });
    if (it != vMembers.end()) {
        *it = *this;
        // save update vector to file
        SaveMembersToFile();
    }
}

// Delete Target Members
bool clsMember::_deleteMember() {
    // search for Targetmember by its accountnumber in vector
    auto it = find_if(vMembers.begin(), vMembers.end(), [&](clsMember &member) {
        return (member.GetAccountNumber() == this->GetAccountNumber());
    });
    // if Targetmember found then delete it from vector
    if (it != vMembers.end()) {
        vMembers.erase(it);
        return true;
    }
    // Targetmember not found
    return false;
}

// Delete Target Member
bool clsMember::Delete() {
    // Delete TargetMember
    if (_deleteMember()) {
        // save update vector to file
        SaveMembersToFile();
        // erase data from current TargetMember obj
        *this = _GetEmptyMemberObj();
        return true;
    }
    // failed delete
    return false;
}

// Borrow book
void clsMember::BorrowBook() {
    ++_TotalBorrowedBooks;
    // update in vector and save member record to file
    _updateMember();
}

// Return book
void clsMember::ReturnBook(bool isLate) {
    if (isLate) {
        _Violations++;
    }
    if (_Violations > 10) {
        _AccountStatus = eAccountStatus::BLOCKED;
    }
    // decrease totalborrowedbooks
    --_TotalBorrowedBooks;
    // update in vector and save member record to file
    _updateMember();
}

// convert enum eAccountstatus to string
string clsMember::AccountStatusToString() {
    return (_AccountStatus == eAccountStatus::ACTIVE) ? "ACTIVE" : (_AccountStatus == eAccountStatus::BLOCKED) ? "BLOCKED" : "CLOSED";
}

// convert enum eMemberRole to string
string clsMember::MemberRoleToString() {
    return (_Role == eMemberRole::STUDENT) ? "STUDENT" : (_Role == eMemberRole::TEACHER) ? "TEACHER" : "NON";
}

// check if member exceeded the BorrowBook limit
bool clsMember::isBorrowLimitExceeded() {
    if (_Role == eMemberRole::STUDENT) {
        return (_TotalBorrowedBooks > 2);
    }
    return (_TotalBorrowedBooks > 4);
}

// reset members
bool clsMember::ResetMembers() {
    if (!vMembers.empty()) {
        for (clsMember &member : vMembers) {
            member.SetTotalBorrowedBooks(0);
            member.SetViolations(0);
        }
        // save update vector to file
        SaveMembersToFile();
        return true;
    }
    return false;
}

// save
clsMember::enSaveMode clsMember::save() {
    switch (_Mode) {
        case eMemberMode::EmptyMode: {
            return enSaveMode::SaveFailed;
            break;
        }
        case eMemberMode::AddNewMode: {
            // change _mode befor add it to vector
            _Mode = eMemberMode::UpdateMode;
            _addMember();
            return enSaveMode::SaveSuccess;
            break;
        }
        case eMemberMode::UpdateMode: {
            _updateMember();
            return enSaveMode::SaveSuccess;
            break;
        }
        default:
            break;
    }
}
