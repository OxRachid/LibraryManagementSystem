#ifndef CLSTRANSACTION_H
#define CLSTRANSACTION_H

#include "../Lib/clsDate.h"
#include <string>
#include <vector>

class clsTransaction {
    public:
        // enum for member Role
        enum enRole {
            STUDENT = 0,
            TEACHER = 1,
            NON = 2
        };

    private:
        // static vector hold all Borrow books Records
        static vector<clsTransaction> _vTransactions;

        // enum foe mode option
        enum enMode {
            EMPTY_MODE = 1,
            UPDATE_MODE = 2,
            ADD_MODE = 3
        };

        // enum for transaction status
        enum enTransStatus {
            BORROWED = 0,
            RETURNED = 1
        };

        enMode _Mode;
        int _TransactionID;
        string _CheckoutPerformer;
        string _CheckinPerformer;
        string _AccountNumber;
        int _BookID;
        enRole _Role;
        clsDate _CheckoutDate;
        clsDate _DueDate;
        clsDate _ReturnDate;
        enTransStatus _Status;

        // get empty obj
        static clsTransaction _GetEmptyRecord();
        // Get Add BorrowRecord obj
        static clsTransaction _GetAddModeRecord(string AccountNumber, int book_ID, enRole role);
        // convert BorrowRecords to line
        static clsTransaction _LineToRecord(string line, string seperator = "|");
        // convert line to BorrowRecord
        string _RecordToLine(string seperator = "|");
        // add Borrow Record to vector
        void _AddBorrowRecord();
        // update Borrow Record in vector
        void _updateBorrowRecord();

    public:
        // constructor parameter
        clsTransaction(enMode mode, int trans_ID, string checkoutperformer, string checkinperformer, string accountnumber, int book_ID, enRole role, clsDate checkout_date, clsDate due_date, clsDate return_date, enTransStatus status);

        // Setters
        void SetTrans_ID(int trans_ID);
        void SetCheckoutPerformer(string checkoutperformor);
        void SetCheckinPerformer(string checkinperformor);
        void SetAccountNumber(string AccountNumber);
        void SetBookID(int book_ID);
        void SetRole(enRole role);
        void SetCheckoutDate(clsDate checkout_date);
        void SetDueDate(clsDate due_date);
        void SetReturnDate(clsDate return_date);
        void SetStatus(enTransStatus status);
        // getters
        int GetTrans_ID();
        string GetCheckoutPerformer();
        string GetCheckinPerformer();
        string GetAccountNumber();
        int GetBookID();
        enRole GetRole();
        clsDate GetCheckoutDate();
        clsDate GetDueDate();
        clsDate GetReturnDate();
        enTransStatus GetStatus();

        // is obj empty
        bool isEmpty();
        // is book returned
        bool isBookReturned();
        // checks if a member has already borrowed the same book and has not returned it yet
        static bool isBookStillBorrowedByMember(string accountnumber, int book_ID);
        // is member exist
        static bool isAccountNumberExist(string accountnumber);
        // is book id exist
        static bool isBookIDExist(int book_ID);
        // is transaction ID exist
        static bool isTransactionExist(int trans_ID);
        // is transaction (accountnumber & book_ID) exist
        static bool isTransactionExist(string accountnumber, int trans_ID);
        // find transaction by only book_ID
        static clsTransaction FindByBookID(int book_ID);
        // find transaction by only accountnumber
        static clsTransaction Find(string accountnumber);
        // find transaction by only trans_ID
        static clsTransaction Find(int trans_ID);
        // find transaction by AccountNumber & book_ID
        static clsTransaction Find(string accountnumber, int book_ID);
        // load transactions from file
        static void LoadTransactions();
        // save transactions to file
        static void SaveTransactions();
        // Get transactions list from vector
        static vector<clsTransaction> &GetTransactionsList();
        // Get borrowed GetBorrowedList
        static vector<clsTransaction> GetBorrowedList();
        // Get returned list
        static vector<clsTransaction> GetReturnedList();
        // Get all transactions by specific member
        static vector<clsTransaction> GetTransactionsForMember(string accountnumber);
        // Get all transactions by specific book
        static vector<clsTransaction> GetTransactionsForBook(int book_ID);
        // create BorrowRecords register
        static void log_borrowing_transaction(string accountnumber, int book_ID, enRole role);
        // convert enum book status to string
        string BookStatusToString();
        // convert enum enRole to string
        string RoleToString();
        // return book
        void ReturnBook();
        // enum for saving result
        enum eSaveMode {
            SAVE_FAILED = 1,
            SAVE_SUCCESS = 2
        };
        eSaveMode save();
};

#endif // !CLSTRANSACTION_H
