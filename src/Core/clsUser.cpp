#include "../../headers/Core/clsUser.h"
#include "../../headers/Lib/clsString.h"
#include "../../headers/Lib/constants.h"
#include <__config>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// define path of users file
const string USERSFILE = "data/Users.txt";

// define static vector for users list
vector<clsUser> clsUser::vUsers = {};

clsUser::clsUser(enMode mode, string username, string password, string firstname, string lastname, string email, string phone, clsDate accountCreated_on, short totalTransMade)
    : clsPerson(firstname, lastname, email, phone) {
    _Mode = mode;
    _Username = username;
    _Password = password;
    _AccountCreated_on = accountCreated_on;
    _TotalTransMade = totalTransMade;
}

// setter
void clsUser::SetPassword(string password) {
    _Password = password;
}
void clsUser::SetAccountCreated_on(clsDate accountcreated_on) {
    _AccountCreated_on = accountcreated_on;
}
void clsUser::UpdateTotalTransMade() {
    ++_TotalTransMade;
}
// getters

string clsUser::GetUsername() {
    return _Username;
}
string clsUser::GetPassword() {
    return _Password;
}
clsDate clsUser::GetAccountCreated_on() {
    return _AccountCreated_on;
}
short clsUser::GetTotalTransMade() {
    return _TotalTransMade;
}

// Get EMPTY obj
clsUser clsUser::_GetEmptyObj() {
    return clsUser(enMode::EMPTY, // mode
        EMPTY_STR,                // username
        EMPTY_STR,                // password
        EMPTY_STR,                // firstname
        EMPTY_STR,                // lastname
        EMPTY_STR,                // email
        EMPTY_STR,                // phone
        DEFAULT_DATE,             // accountcreated_on
        DEFAULT_INT);             // totalTransMade
}

// get add new user obj mode
clsUser clsUser::GetAddUserObjMode(string username) {
    return clsUser(enMode::ADD, // mode
        username,               // username
        EMPTY_STR,              // password
        EMPTY_STR,              // firstname
        EMPTY_STR,              // lastname
        EMPTY_STR,              // email
        EMPTY_STR,              // phone
        clsDate(),              // accountcreated_on
        DEFAULT_INT);           // totalTransMade
}

// convert line to user obj
clsUser clsUser::LineToUser(string line, string seperator) {
    vector<string> vStr = clsString::Split(line, seperator);
    return clsUser(enMode::UPDATE, // mode
        vStr[0],                   // username
        vStr[1],                   // password
        vStr[2],                   // firstname
        vStr[3],                   // lastname
        vStr[4],                   // email
        vStr[5],                   // phone
        clsDate(vStr[6]),          // accountcreated_on
        stoi(vStr[7]));            // totalTransMade
}

// convert user obj to line
string clsUser::UserToLine(string seperator) {
    string line = "";
    line += _Username + seperator;
    line += _Password + seperator;
    line += GetFirstName() + seperator;
    line += GetLastName() + seperator;
    line += GetEmail() + seperator;
    line += GetPhone() + seperator;
    line += _AccountCreated_on.ConvertDateToString() + seperator;
    line += to_string(_TotalTransMade);
    return line;
}
// is EMPTY
bool clsUser::isEmpty() {
    return (_Mode == enMode::EMPTY);
}

// is user exist (username)
bool clsUser::isUserExist(string username) {
    clsUser user = Find(username);
    return (!user.isEmpty());
}
// is user exist (username & password)
bool clsUser::isUserExist(string username, string password) {
    clsUser user = Find(username, password);
    return (!user.isEmpty());
}
// Find by username
clsUser clsUser::Find(string username) {
    auto it = find_if(vUsers.begin(), vUsers.end(), [&](clsUser &user) {
        return (user.GetUsername() == username);
    });

    if (it != vUsers.end()) {
        return *it;
    }

    return _GetEmptyObj();
}
// Find by username and password
clsUser clsUser::Find(string username, string password) {
    auto it = find_if(vUsers.begin(), vUsers.end(), [&](clsUser &user) {
        return (user.GetUsername() == username && user.GetPassword() == password);
    });

    if (it != vUsers.end()) {
        return *it;
    }

    return _GetEmptyObj();
}
// Load users list from file
void clsUser::LoadUsersFromFile() {
    fstream file;
    file.open(USERSFILE, ios::in);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            clsUser user = LineToUser(line);
            vUsers.push_back(user);
        }
        file.close();
    }
}
// save users to file
void clsUser::SaveUsersToFile() {
    fstream file;
    file.open(USERSFILE, ios::out);
    if (file.is_open()) {
        for (clsUser &user : vUsers) {
            file << user.UserToLine() << endl;
        }
        file.close();
    }
}
// Get Users list
vector<clsUser> &clsUser::GetUsersList() {
    return vUsers;
}

// add user
void clsUser::_addUser() {
    // add user to vector
    vUsers.push_back(*this);
    // save to file
    SaveUsersToFile();
}
// update user
void clsUser::_updateUser() {
    auto it = find_if(vUsers.begin(), vUsers.end(), [&](clsUser &user) {
        return user.GetUsername() == this->GetUsername();
    });
    if (it != vUsers.end()) {
        // replace old version with new update one
        *it = *this;
        // save thr update vector to file
        SaveUsersToFile();
    }
}

// save func
clsUser::eSaveResult clsUser::save() {
    switch (_Mode) {
        case enMode::EMPTY: {
            return eSaveResult::SAVE_FAILED;
            break;
        }
        case enMode::ADD: {
            _Mode = enMode::UPDATE;
            _addUser();
            return eSaveResult::SAVE_SUCCESS;
            break;
        }
        case enMode::UPDATE: {
            _updateUser();
            return eSaveResult::SAVE_SUCCESS;
            break;
        }
    }
}
