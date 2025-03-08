#ifndef CLSMEMBER_H
#define CLSMEMBER_H

#include "../Lib/clsDate.h"
#include "../Lib/clsPerson.h"
#include <string>
#include <vector>

class clsMember : public clsPerson {
    public:
        // enum for account status
        enum eAccountStatus {
            ACTIVE = 0,
            BLOCKED = 1,
            CLOSED = 2
        };

    private:
        // define static vector
        static vector<clsMember> vMembers;

        // enum for obj mode
        enum eMemberMode {
            EmptyMode = 0,
            UpdateMode = 1,
            AddNewMode = 2
        };
        // enum for member Role
        enum eMemberRole {
            STUDENT = 0,
            TEACHER = 1,
            NON = 2
        };

        eMemberMode _Mode;
        string _AccountNumber;
        string _Password;
        eMemberRole _Role;
        short _TotalBorrowedBooks;
        short _Violations;
        clsDate _AccountCreated_on;
        eAccountStatus _AccountStatus;

        // Get Empty member obj
        static clsMember _GetEmptyMemberObj();
        // Convert line to member obj
        static clsMember _LineToMember(string line, string seperator = "|");
        // convert member obj to line
        string _MemberToLine(string seperator = "|");
        // add member
        void _addMember();
        // update member
        void _updateMember();
        // delete member
        bool _deleteMember();

    public:
        // constructor parameter
        clsMember(eMemberMode mode,    // mode
            string accountnumber,      // accountnumber
            string password,           // password
            string firstname,          // firstname
            string lastname,           // lastname
            string email,              // email
            string phone,              // phone
            eMemberRole role,          // role
            short totalborrowedbooks,  // totalborrowedbooks
            short violations,          // violations
            clsDate accountcreated_on, // accountcreated_on
            eAccountStatus status);    // status
        // setter
        void SetPassword(string password);
        void SetRole(short role);
        void SetTotalBorrowedBooks(short total);
        void UpdateLateReturns();
        void SetViolations(short value);
        void SetAccountCreated_on(clsDate accountcreated_on);
        void SetAccountStatus(eAccountStatus status);
        // getter
        string GetAccountNumber();
        string GetPassword();
        eMemberRole GetRole();
        short GetTotalBorrowedBooks();
        short GetViolations();
        clsDate GetAccountCreated_on();
        eAccountStatus GetAccountStatus();
        static int TotalMembers_Size();
        static int Students_Size();
        static int Teachers_Size();

        // is empty
        bool isEmpty();

        // Get Add new member obj
        static clsMember GetAddNewMemberObj(string accountnumber);
        // is member exist search by accountnumber
        static bool isMemberExist(string accountnumber);
        // is member exist search by accountnumber and password
        static bool isMemberExist(string accountnumber, string password);
        // Find member by accountnumber
        static clsMember Find(string accountnumber);
        // Find member by accountnumber and password
        static clsMember Find(string accountnumber, string password);
        // Load Memebrs from file
        static void LoadMembersFromFile();
        // Save Memebrs to file
        static void SaveMembersToFile();
        // Get Members list from static  vector
        static vector<clsMember> &GetMembersList();
        // Get Students or Teachers Members list from static  vector
        static vector<clsMember> GetSpecificMembersList(bool ByStudents = true);
        // enum for save result mode
        enum enSaveMode {
            SaveFailed = 1,
            SaveSuccess = 2
        };
        // save
        enSaveMode save();
        // Delete Target Member
        bool Delete();
        // Borrow book
        void BorrowBook();
        // Return book
        void ReturnBook(bool isLate = false);
        // convert enum eAccountstatus to string
        string AccountStatusToString();
        // convert enum eMemberRole to string
        string MemberRoleToString();
        // check if member exceeded the BorrowBook limit
        bool isBorrowLimitExceeded();
        // reset members
        static bool ResetMembers();
};

#endif // !CLSMEMBER_H
