#ifndef CLSBORROWRECORD_H
#define CLSBORROWRECORD_H

#include "../Lib/clsDate.h"
#include <string>
#include <vector>

class clsBorrowRecord {
    private:
        // static vector hold all Borrow books Records
        static vector<clsBorrowRecord> _vBorrowRecords;

        // enum foe mode option
        enum enMode {
            EMPTY_MODE = 1,
            UPDATE_MODE = 2,
            ADD_MODE = 3
        };

        // enum for transaction status
        enum enStatus {
            BORROWED = 0,
            RETURNED = 1
        };

        enMode _Mode;
        int _TransactionID;
        string _CheckoutPerformer;
        string _CheckinPerformer;
        string _AccountNumber;
        int _BookID;
        string _Role;
        clsDate _CheckoutDate;
        clsDate _DueDate;
        clsDate _ReturnDate;
        enStatus _Status;

        // get empty obj
        static clsBorrowRecord _GetEmptyRecord();
        // Get Add BorrowRecord obj
        static clsBorrowRecord _GetAddModeRecord(string AccountNumber, int book_ID, string role);
        // convert BorrowRecords to line
        static clsBorrowRecord _LineToRecord(string line, string seperator = "#-#");
        // convert line to BorrowRecord
        string _RecordToLine(string seperator = "#-#");
        // add Borrow Record to vector
        void _AddBorrowRecord();
        // update Borrow Record in vector
        void _updateBorrowRecord();

    public:
        // constructor parameter
        clsBorrowRecord(
            enMode mode,
            int trans_ID,
            string checkoutperformer,
            string checkinperformer,
            string accountnumber,
            int book_ID,
            string role,
            clsDate checkout_date,
            clsDate due_date,
            clsDate return_date,
            enStatus status);

        // Setters
        void SetTrans_ID(int trans_ID);
        void SetCheckoutPerformer(string checkoutperformor);
        void SetCheckinPerformer(string checkinperformor);
        void SetAccountNumber(string AccountNumber);
        void SetBookID(int book_ID);
        void SetRole(string role);
        void SetCheckoutDate(clsDate checkout_date);
        void SetDueDate(clsDate due_date);
        void SetReturnDate(clsDate return_date);
        void SetStatus(enStatus status);
        // getters
        int GetTrans_ID();
        string GetCheckoutPerformer();
        string GetCheckinPerformer();
        string GetAccountNumber();
        int GetBookID();
        string GetRole();
        clsDate GetCheckoutDate();
        clsDate GetDueDate();
        clsDate GetReturnDate();
        enStatus GetStatus();

        // is obj empty
        bool isEmpty();
        // is book returned
        bool isBookReturned();
        // is member exist
        static bool isAccountNumberExist(string accountnumber);
        // is book id exist
        static bool isBookIDExist(int book_ID);
        // is transaction ID exist
        static bool isTransactionExist(int trans_ID);
        // is transaction (accountnumber & book_ID) exist
        static bool isTransactionExist(string accountnumber, int trans_ID);
        // find transaction by only book_ID
        static clsBorrowRecord FindByBookID(int book_ID);
        // find transaction by only accountnumber
        static clsBorrowRecord Find(string accountnumber);
        // find transaction by only trans_ID
        static clsBorrowRecord Find(int trans_ID);
        // find transaction by AccountNumber & book_ID
        static clsBorrowRecord Find(string accountnumber, int book_ID);
        // load BorrowRecords from file
        static void LoadBorrowRecords();
        // save BorrowRecords to file
        static void SaveBorrowRecords();
        // Get BorrowRecords from vector
        static vector<clsBorrowRecord> &GetBorrowRecords();
        // create BorrowRecords register
        static void log_borrowing_transaction(string accountnumber, int book_ID, string role);
        // convert enum book status to string
        string BookStatusToString();
        // return book
        void ReturnBook();
        // enum for saving result
        enum eSaveMode {
            SAVE_FAILED = 1,
            SAVE_SUCCESS = 2
        };
        eSaveMode save();
};

#endif // !CLSBORROWRECORD_H
