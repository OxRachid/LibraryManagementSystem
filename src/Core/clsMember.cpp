#include "../../headers/Core/clsMember.h"
#include "../../headers/Lib/clsString.h"
#include "../../headers/Lib/constants.h"
#include <cctype>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
using namespace std;

// Define members stored file
const string MembersFile = "data/Members.txt";

// define static vector
vector<clsMember> clsMember::vMembers = {};

// constructor parameter
clsMember::clsMember(eMemberMode mode, string accountnumber, string password, string firstname, string lastname, string email, string phone, string role, short totalborrowedbooks, eAccountStatus status)
    : clsPerson(firstname, lastname, email, phone) {
    _Mode = mode;
    _AccountNumber = accountnumber;
    _Password = password;
    _Role = role;
    _TotalBorrowedBooks = totalborrowedbooks;
    _AccountStatus = status;
}

// setter
void clsMember::SetPassword(string password) {
    _Password = password;
}
void clsMember::SetRole(string role) {
    _Role = role;
}
void clsMember::SetBorrowedBooks(short total) {
    _TotalBorrowedBooks = total;
}

void clsMember::SetAccountStatus(eAccountStatus status) {
    _AccountStatus = status;
}
// getter
string clsMember::GetAccountNumber() const {
    return _AccountNumber;
}
string clsMember::GetPassword() const {
    return _Password;
}
string clsMember::GetRole() const {
    return _Role;
}
short clsMember::GetTotalBorrowedBooks() const {
    return _TotalBorrowedBooks;
}
clsMember::eAccountStatus clsMember::GetAccountStatus() {
    return _AccountStatus;
}
// is empty
bool clsMember::isEmpty() {
    return (_Mode == eMemberMode::EmptyMode);
}

// Get Empty member obj
clsMember clsMember::_GetEmptyMemberObj() {
    return clsMember(
        eMemberMode::EmptyMode,
        EMPTY_STR,
        EMPTY_STR,
        EMPTY_STR,
        EMPTY_STR,
        EMPTY_STR,
        EMPTY_STR,
        EMPTY_STR,
        0,
        eAccountStatus::BLOCKED);
}
// Get Add new member obj
clsMember clsMember::GetAddNewMemberObj(string accountnumber) {
    return clsMember(
        eMemberMode::AddNewMode,
        accountnumber,
        EMPTY_STR,
        EMPTY_STR,
        EMPTY_STR,
        EMPTY_STR,
        EMPTY_STR,
        EMPTY_STR,
        0,
        eAccountStatus::ACTIVE);
}

// Convert line to member obj
clsMember clsMember::_LineToMember(string line, string seperator) {
    vector<string> vStr = clsString::Split(line, seperator);
    return clsMember(
        eMemberMode::UpdateMode,
        vStr[0],
        vStr[1],
        vStr[2],
        vStr[3],
        vStr[4],
        vStr[5],
        vStr[6],
        stoi(vStr[7]),
        (eAccountStatus)stoi(vStr[8]));
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
    line += _Role + seperator;
    line += to_string(_TotalBorrowedBooks);
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
    auto it = find_if(vMembers.begin(), vMembers.end(), [&](const clsMember &member) {
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
    auto it = find_if(vMembers.begin(), vMembers.end(), [&](const clsMember &member) {
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
    for (const clsMember &member : vMembers) {
        if (ByStudents) {
            if (member.GetRole() == "student") {
                vSpecificMembers.push_back(member);
            }
        } else {
            if (member.GetRole() == "teacher") {
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
    auto it = find_if(vMembers.begin(), vMembers.end(), [&](const clsMember &member) {
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
    auto it = find_if(vMembers.begin(), vMembers.end(), [&](const clsMember &member) {
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
        _LateReturns++;
    }
    if (_LateReturns > 10) {
        _AccountStatus = eAccountStatus::BLOCKED;
    }
    // decrease totalborrowedbooks
    --_TotalBorrowedBooks;
    // update in vector and save member record to file
    _updateMember();
}

// convert enum eAccountstatus to string
string clsMember::AccountStatusToString() {
    return (_AccountStatus == eAccountStatus::ACTIVE) ? "ACTIVE" : (_AccountStatus == eAccountStatus::BLOCKED) ? "BLOCKED"
                                                                                                               : "CLOSED";
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
