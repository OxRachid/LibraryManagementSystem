#ifndef CLSMEMBER_H
#define CLSMEMBER_H

#include "../Lib/clsPerson.h"
#include <string>
#include <vector>

class clsMember : public clsPerson {
    private:
        // define static vector
        static vector<clsMember> vMembers;

        // enum for obj mode
        enum eMemberMode {
            EmptyMode = 1,
            UpdateMode = 2,
            AddNewMode = 3
        };

        // enum for account status
        enum eAccountStatus {
            ACTIVE = 0,
            BLOCKED = 1,
            CLOSED = 2
        };

        eMemberMode _Mode;
        string _AccountNumber;
        string _Password;
        string _Role;
        short _TotalBorrowedBooks;
        short _LateReturns;
        eAccountStatus _AccountStatus;

        // Get Empty member obj
        static clsMember _GetEmptyMemberObj();
        // Convert line to member obj
        static clsMember _LineToMember(string line, string seperator = "#-#");
        // convert member obj to line
        string _MemberToLine(string seperator = "#-#");
        // add member
        void _addMember();
        // update member
        void _updateMember();
        // delete member
        bool _deleteMember();

    public:
        // constructor parameter
        clsMember(
            eMemberMode mode,
            string accountnumber,
            string password,
            string firstname,
            string lastname,
            string email,
            string phone,
            string role,
            short totalborrowedbooks,
            eAccountStatus status);
        // setter
        void SetPassword(string password);
        void SetRole(string role);
        void SetBorrowedBooks(short total);
        void SetAccountStatus(eAccountStatus status);
        // getter
        string GetAccountNumber() const;
        string GetPassword() const;
        string GetRole() const;
        short GetTotalBorrowedBooks() const;
        eAccountStatus GetAccountStatus();
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
};

#endif // !CLSMEMBER_H
