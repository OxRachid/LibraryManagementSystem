#ifndef CLSUSER_H
#define CLSUSER_H

#include "../Lib/clsDate.h"
#include "../Lib/clsPerson.h"
#include <algorithm>
#include <string>
#include <vector>
class clsUser : public clsPerson {
    public:
        // create struct for user login register
        struct stUserLogin {
                string _username;
                string _password;
                short _permissions;
                string _loginTime;
                stUserLogin(string username, string password, short permissions, string loginTime);
        };

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
        string _Username = "-";
        string _Password = "";
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

        // ************ stUserLogin ***************
        // define static vector to store users login info list
        static vector<stUserLogin> vUsersLogin;
        // Convert line to UserLogin obj
        static stUserLogin _LineToUserLogin(string line, string seperator = "|");
        // convert UserLogin to line
        static string _UserLoginToLine(stUserLogin log, string seperator = "|");
        // prepare user login info
        stUserLogin _PrepareUserLoginInfo();

    public:
        // construcor parameter
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
        static int UsersList_size();

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

        // Load Users login list from file
        static void LoadUsersLogin();
        // Save Users login list to file
        static void SaveUsersLogin();
        // Get users login list
        static vector<stUserLogin> GetUsersLogin();
        // create user login info
        void LogUserLogin();
};

#endif // !CLSUSER_H
