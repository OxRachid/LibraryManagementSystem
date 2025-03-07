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
// define path of users login file
const string USERSLOGINFILE = "data/UsersLogin.txt";

// define static vector for users list
vector<clsUser> clsUser::vUsers = {};
// define static vector for users login info list
vector<clsUser::stUserLogin> clsUser::vUsersLogin = {};

clsUser::clsUser(enMode mode, string username, string password, string firstname, string lastname, string email, string phone, clsDate accountCreated_on, short totalTransMade, short permissions)
    : clsPerson(firstname, lastname, email, phone) {
    _Mode = mode;
    _Username = username;
    _Password = password;
    _AccountCreated_on = accountCreated_on;
    _TotalTransMade = totalTransMade;
    _Permissions = permissions;
}

clsUser::stUserLogin::stUserLogin(string username, string password, short permissions, string loginTime) {
    _username = username;
    _password = password;
    _permissions = permissions;
    _loginTime = loginTime;
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
    _updateUser();
}
void clsUser::SetPermissions(short permissions) {
    _Permissions = permissions;
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
short clsUser::GetPermissions() {
    return _Permissions;
}
// Get EMPTY obj
clsUser clsUser::_GetEmptyObj() {
    return clsUser(enMode::EMPTY, // mode
        DEFAULT_STR,              // username
        EMPTY_STR,                // password
        EMPTY_STR,                // firstname
        EMPTY_STR,                // lastname
        EMPTY_STR,                // email
        EMPTY_STR,                // phone
        DEFAULT_DATE,             // accountcreated_on
        DEFAULT_INT,              // totalTransMade
        DEFAULT_INT);             // permissions
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
        DEFAULT_INT,            // totalTransMade
        DEFAULT_INT);           // permissions
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
        stoi(vStr[7]),             // totalTransMade
        stoi(vStr[8]));            // permissions
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
    line += to_string(_TotalTransMade) + seperator;
    line += to_string(_Permissions);
    return line;
}

// prepare user login info
clsUser::stUserLogin clsUser::_PrepareUserLoginInfo() {
    return stUserLogin(GetUsername(),     // username
        GetPassword(),                    // password
        GetPermissions(),                 // permissions
        clsDate::GetSystemDateAndTime()); // loginTime
}

// Convert line to UserLogin obj
clsUser::stUserLogin clsUser::_LineToUserLogin(string line, string seperator) {
    vector<string> vStr = clsString::Split(line, seperator);
    return stUserLogin(vStr[0], vStr[1], stoi(vStr[2]), vStr[3]);
}

// convert UserLogin to line
string clsUser::_UserLoginToLine(stUserLogin log, string seperator) {
    string dataline = "";
    dataline += log._username + seperator;
    dataline += log._password + seperator;
    dataline += to_string(log._permissions) + seperator;
    dataline += log._loginTime;
    return dataline;
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
    // clear static vector befor loading data
    vUsers.clear();

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

// Delete user
bool clsUser::_deleteUser() {
    auto it = find_if(vUsers.begin(), vUsers.end(), [&](clsUser &user) {
        return (user.GetUsername() == this->GetUsername());
    });

    if (it != vUsers.end()) {
        vUsers.erase(it);
        return true;
    }

    return false;
}

// Delete user
bool clsUser::Delete() {
    if (_deleteUser()) {
        // save update vector to file
        SaveUsersToFile();
        // erase the curr user obj
        *this = _GetEmptyObj();
        return true;
    }
    return false;
}

// is user has access
bool clsUser::isUserHasAccess(ePermissionFunc permission) {
    return (_Permissions == static_cast<short>(ePermissionFunc::ALL)) ? true : ((_Permissions & static_cast<short>(permission)) != 0) ? true : false;
}

// Load Users login list from file
void clsUser::LoadUsersLogin() {
    // clear static vector befor loading data
    vUsersLogin.clear();

    fstream file;
    file.open(USERSLOGINFILE, ios::in);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stUserLogin UserLog = _LineToUserLogin(line);
            vUsersLogin.push_back(UserLog);
        }
        file.close();
    }
}
// Save Users login list to file
void clsUser::SaveUsersLogin() {
    fstream file;
    file.open(USERSLOGINFILE, ios::out);
    if (file.is_open()) {
        string line = "";
        for (stUserLogin &log : vUsersLogin) {
            line = _UserLoginToLine(log);
            file << line << "\n";
        }
        file.close();
    }
}

// Get users login list
vector<clsUser::stUserLogin> clsUser::GetUsersLogin() {
    return vUsersLogin;
}

// create user login info
void clsUser::LogUserLogin() {
    // prepare user login info
    stUserLogin log = _PrepareUserLoginInfo();
    // add the log to vector
    vUsersLogin.push_back(log);
    // save the update vector to file
    SaveUsersLogin();
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
