#ifndef CLSUSER_H
#define CLSUSER_H

#include "../Lib/clsDate.h"
#include "../Lib/clsPerson.h"
#include <algorithm>
#include <string>
#include <vector>
class clsUser : public clsPerson {
    private:
        // define static vector for users list
        static vector<clsUser> vUsers;

        // enum for Obj mode
        enum enMode {
            EMPTY = 1,
            UPDATE,
            ADD
        };
        enMode _Mode;
        string _Username;
        string _Password;
        clsDate _AccountCreated_on;
        short _TotalTransMade;
        short _Permissions;

        // Get EMPTY obj
        static clsUser _GetEmptyObj();
        // convert line to user obj
        static clsUser LineToUser(string line, string seperator = "|");
        // convert user obj to line
        string UserToLine(string seperator = "|");
        // add user
        void _addUser();
        // update user
        void _updateUser();
        // Delete user
        bool _deleteUser();

    public:
        clsUser(enMode mode,           // Mode
            string username,           // Username
            string password,           // password
            string firstname,          // firstname
            string lastname,           // lastname
            string email,              // email
            string phone,              // phone
            clsDate accountCreated_on, // accountcreated_on
            short totalTransMade,      // totalTransMade
            short permissions);        // permissions

        // enum for permissions
        enum ePermissionFunc {
            ALL = -1,
            BOOK_MANAGE = 1,
            MEMBER_MANAGE = 2,
            TRANSACTIONS = 4,
            USERS_MANAGE = 8
        };

        // setter
        void SetPassword(string password);
        void SetAccountCreated_on(clsDate accountcreated_on);
        void UpdateTotalTransMade();
        void SetPermissions(short permissions);

        // getters
        string GetUsername();
        string GetPassword();
        clsDate GetAccountCreated_on();
        short GetTotalTransMade();
        short GetPermissions();

        // is EMPTY
        bool isEmpty();
        // is user exist (username)
        static bool isUserExist(string username);
        // is user exist (username & password)
        static bool isUserExist(string username, string password);
        // Find by username
        static clsUser Find(string username);
        // Find by username and password
        static clsUser Find(string username, string password);
        // get add new user obj mode
        static clsUser GetAddUserObjMode(string username);
        // Load users list from file
        static void LoadUsersFromFile();
        // save users to file
        static void SaveUsersToFile();
        // Get Users list
        static vector<clsUser> &GetUsersList();
        // enum for saving rsult
        enum eSaveResult {
            SAVE_FAILED = 1,
            SAVE_SUCCESS
        };
        // save func
        eSaveResult save();
        // Delete user
        bool Delete();
        // is user has access
        bool isUserHasAccess(ePermissionFunc funcCode);
};

#endif // !CLSUSER_H
