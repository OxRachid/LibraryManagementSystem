#include "../../headers/Core/clsTransaction.h"
#include "../../headers/Lib/clsString.h"
#include "../../headers/Lib/clsUtil.h"
#include "../../headers/Lib/constants.h"
#include <complex.h>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

const string TransactionsFile = "data/TransactionsHistory.txt";

// static vector hold all Borrow books Records
vector<clsTransaction> clsTransaction::_vTransactions = {};

// constructor parameter
clsTransaction::clsTransaction(enMode mode, int trans_ID, string checkoutperformer, string checkinperformer, string accountnumber, int book_ID, enRole role, clsDate checkout_date, clsDate due_date, clsDate return_date, enTransStatus status) {
    _Mode = mode;
    _TransactionID = trans_ID;
    _CheckoutPerformer = checkoutperformer;
    _CheckinPerformer = checkinperformer;
    _AccountNumber = accountnumber;
    _BookID = book_ID;
    _Role = role;
    _CheckoutDate = checkout_date;
    _DueDate = due_date;
    _ReturnDate = return_date;
    _Status = status;
}
// Setters
void clsTransaction::SetCheckoutPerformer(string checkoutperformer) {
    _CheckoutPerformer = checkoutperformer;
}

void clsTransaction::SetCheckinPerformer(string checkinperformer) {
    _CheckinPerformer = checkinperformer;
}

void clsTransaction::SetTrans_ID(int trans_ID) {
    _TransactionID = trans_ID;
}
void clsTransaction::SetAccountNumber(string accountnumber) {
    _AccountNumber = accountnumber;
}
void clsTransaction::SetBookID(int book_ID) {
    _BookID = book_ID;
}
void clsTransaction::SetRole(enRole role) {
    _Role = role;
}
void clsTransaction::SetCheckoutDate(clsDate checkout_date) {
    _CheckoutDate = checkout_date;
}
void clsTransaction::SetDueDate(clsDate due_date) {
    _DueDate = due_date;
}
void clsTransaction::SetReturnDate(clsDate return_date) {
    _ReturnDate = return_date;
}
void clsTransaction::SetStatus(enTransStatus status) {
    _Status = status;
}
// getters
string clsTransaction::GetCheckoutPerformer() {
    return _CheckoutPerformer;
}
string clsTransaction::GetCheckinPerformer() {
    return _CheckinPerformer;
}

int clsTransaction::GetTrans_ID() {
    return _TransactionID;
}
string clsTransaction::GetAccountNumber() {
    return _AccountNumber;
}
int clsTransaction::GetBookID() {
    return _BookID;
}
clsTransaction::enRole clsTransaction::GetRole() {
    return _Role;
}
clsDate clsTransaction::GetCheckoutDate() {
    return _CheckoutDate;
}
clsDate clsTransaction::GetDueDate() {
    return _DueDate;
}
clsDate clsTransaction::GetReturnDate() {
    return _ReturnDate;
}
clsTransaction::enTransStatus clsTransaction::GetStatus() {
    return _Status;
}
int clsTransaction::TransList_size() {
    return _vTransactions.size();
}
int clsTransaction::BorrowedList_size() {
    vector<clsTransaction> vBorrowed = GetBorrowedList();
    return vBorrowed.size();
}
int clsTransaction::ReturnedList_size() {
    vector<clsTransaction> vReturned = GetReturnedList();
    return vReturned.size();
}
int clsTransaction::PendingList_size() {
    vector<clsTransaction> vPending = GetPendingList();
    return vPending.size();
}
int clsTransaction::CanceledList_size() {
    vector<clsTransaction> vCanceled = GetCanceledList();
    return vCanceled.size();
}

// get empty obj
clsTransaction clsTransaction::_GetEmptyRecord() {
    return clsTransaction(enMode::EMPTY_MODE, // _Mode
        DEFAULT_INT,                          // _TransactionID
        DEFAULT_STR,                          // _CheckoutPerformer
        DEFAULT_STR,                          // _CheckinPerformer
        EMPTY_STR,                            // _AccountNumber
        DEFAULT_INT,                          // _BookID
        enRole::NON,                          // _Role
        DEFAULT_DATE,                         // _CheckoutDate
        DEFAULT_DATE,                         // _DueDate
        DEFAULT_DATE,                         // _ReturnDate
        enTransStatus::CANCELED               // _Status
    );
}
// Get Add BorrowRecord obj
clsTransaction clsTransaction::_GetAddModeRecord(string accountnumber, int book_ID, enRole role) {
    int transID;
    do {
        transID = clsUtil::GenerateNumber(5);
    } while (isTransactionExist(transID));

    return clsTransaction(enMode::ADD_MODE, // _Mode
        transID,                            // _TransactionID
        DEFAULT_STR,                        // _CheckoutPerformer
        DEFAULT_STR,                        // _CheckinPerformer
        accountnumber,                      // _AccountNumber
        book_ID,                            // _BookID
        role,                               // _Role
        clsDate(),                          // _CheckoutDate
        clsDate(),                          // _DueDate
        DEFAULT_DATE,                       // _ReturnDate
        enTransStatus::PENDING              // _Status
    );
}

// convert line to BorrowRecord
string clsTransaction::_RecordToLine(string seperator) {
    string line = "";
    line += to_string(_TransactionID) + seperator;
    line += _CheckoutPerformer + seperator;
    line += _CheckinPerformer + seperator;
    line += _AccountNumber + seperator;
    line += to_string(_BookID) + seperator;
    line += to_string((short)_Role) + seperator;
    line += clsDate::ConvertDateAndTimeToString(_CheckoutDate) + seperator;
    line += clsDate::ConvertDateAndTimeToString(_DueDate) + seperator;
    line += clsDate::ConvertDateAndTimeToString(_ReturnDate) + seperator;
    line += to_string((short)_Status);
    return line;
}

// convert BorrowRecords to line
clsTransaction clsTransaction::_LineToRecord(string line, string seperator) {
    vector<string> vStr = clsString::Split(line, seperator);
    return clsTransaction(enMode::UPDATE_MODE, // _Mode
        stoi(vStr[0]),                         // _TransactionID
        vStr[1],                               // _CheckoutPerformer
        vStr[2],                               // _CheckinPerformer
        vStr[3],                               // _AccountNumber
        stoi(vStr[4]),                         // _BookID
        (enRole)stoi(vStr[5]),                 // _Role
        clsDate(vStr[6]),                      // _CheckoutDate
        clsDate(vStr[7]),                      // _DueDate
        clsDate(vStr[8]),                      // _ReturnDate
        (enTransStatus)stoi(vStr[9]));         // _Status
}

// is obj empty
bool clsTransaction::isEmpty() {
    return (_Mode == enMode::EMPTY_MODE);
}

// is book returned
bool clsTransaction::isBookReturned() {
    return (_Status == enTransStatus::RETURNED);
}

// checks if a member has already borrowed the same book and has not returned it yet
bool clsTransaction::isBookStillBorrowedByMember(string accountnumber, int book_ID) {
    clsTransaction trans = Find(accountnumber, book_ID);
    return !(trans.isBookReturned() || trans.isEmpty() || (trans.GetStatus() == enTransStatus::CANCELED));
}

// is member exist
bool clsTransaction::isAccountNumberExist(string accountnumber) {
    clsTransaction record = Find(accountnumber);
    return (!record.isEmpty());
}
// is book id exist
bool clsTransaction::isBookIDExist(int book_ID) {
    clsTransaction record = FindByBookID(book_ID);
    return (!record.isEmpty());
}

// is transaction ID exist
bool clsTransaction::isTransactionExist(int trans_ID) {
    clsTransaction record = Find(trans_ID);
    return (!record.isEmpty());
}
// is transaction (accountnumber & book_ID) exist
bool clsTransaction::isTransactionExist(string accountnumber, int book_ID) {
    clsTransaction record = Find(accountnumber, book_ID);
    return (!record.isEmpty());
}

// find transaction by only book_ID
clsTransaction clsTransaction::FindByBookID(int book_ID) {
    auto it = find_if(_vTransactions.begin(), _vTransactions.end(), [&](clsTransaction &record) {
        return (record.GetBookID() == book_ID);
    });

    if (it != _vTransactions.end()) {
        return *it;
    }
    // if record not found then return empty record
    return _GetEmptyRecord();
}
// find transaction by only accountnumber
clsTransaction clsTransaction::Find(string accountnumber) {
    auto it = find_if(_vTransactions.begin(), _vTransactions.end(), [&](clsTransaction &record) {
        return (record.GetAccountNumber() == accountnumber);
    });

    if (it != _vTransactions.end()) {
        return *it;
    }
    // if record not found then return empty record
    return _GetEmptyRecord();
}

// find transaction by only trans_ID
clsTransaction clsTransaction::Find(int trans_ID) {
    auto it = find_if(_vTransactions.begin(), _vTransactions.end(), [&](clsTransaction &record) {
        return (record.GetTrans_ID() == trans_ID);
    });

    if (it != _vTransactions.end()) {
        return *it;
    }
    // if record not found then return empty record
    return _GetEmptyRecord();
}
// find transaction by AccountNumber & book_ID
clsTransaction clsTransaction::Find(string accountnumber, int book_ID) {
    auto it = find_if(_vTransactions.begin(), _vTransactions.end(), [&](clsTransaction &record) {
        return (record.GetAccountNumber() == accountnumber && record.GetBookID() == book_ID);
    });

    if (it != _vTransactions.end()) {
        return *it;
    }
    // if record not found then return empty record
    return _GetEmptyRecord();
}

// find transaction by AccountNumber & book_ID in specific vector
clsTransaction clsTransaction::Find(vector<clsTransaction> &vSpecific, string accountnumber, int book_ID) {
    auto it = find_if(vSpecific.begin(), vSpecific.end(), [&](clsTransaction &record) {
        return (record.GetAccountNumber() == accountnumber && record.GetBookID() == book_ID);
    });

    if (it != vSpecific.end()) {
        return *it;
    }
    // if record not found then return empty record
    return _GetEmptyRecord();
}

// load BorrowRecords from file
void clsTransaction::LoadTransactions() {
    // clear vector befor load data
    _vTransactions.clear();

    fstream file;
    file.open(TransactionsFile, ios::in);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            clsTransaction record = _LineToRecord(line);
            _vTransactions.push_back(record);
        }
        file.close();
    }
}
// save BorrowRecords to file
void clsTransaction::SaveTransactions() {
    fstream file;
    file.open(TransactionsFile, ios::out);
    if (file.is_open()) {
        for (clsTransaction &record : _vTransactions) {
            file << record._RecordToLine() << endl;
        }
        file.close();
    }
}

// Get BorrowRecords from vector
vector<clsTransaction> &clsTransaction::GetTransactionsList() {
    return _vTransactions;
}

// Get borrowed GetBorrowedList
vector<clsTransaction> clsTransaction::GetBorrowedList() {
    vector<clsTransaction> vBorrowed;
    for (clsTransaction &trans : _vTransactions) {
        if (trans.GetStatus() == enTransStatus::BORROWED) {
            vBorrowed.push_back(trans);
        }
    }

    return vBorrowed;
}

// Get returned list
vector<clsTransaction> clsTransaction::GetReturnedList() {
    vector<clsTransaction> vReturned;
    for (clsTransaction &trans : _vTransactions) {
        if (trans.GetStatus() == enTransStatus::RETURNED) {
            vReturned.push_back(trans);
        }
    }

    return vReturned;
}

// Get pending list
vector<clsTransaction> clsTransaction::GetPendingList() {
    vector<clsTransaction> vPending;
    for (clsTransaction &trans : _vTransactions) {
        if (trans.GetStatus() == enTransStatus::PENDING) {
            vPending.push_back(trans);
        }
    }

    return vPending;
}

// Get canceled list
vector<clsTransaction> clsTransaction::GetCanceledList() {
    vector<clsTransaction> vCanceled;
    for (clsTransaction &trans : _vTransactions) {
        if (trans.GetStatus() == enTransStatus::CANCELED) {
            vCanceled.push_back(trans);
        }
    }

    return vCanceled;
}

// Get all transactions by specific member
vector<clsTransaction> clsTransaction::GetTransactionsForMember(string accountnumber) {
    vector<clsTransaction> vTrans;
    for (clsTransaction &trans : _vTransactions) {
        if (trans.GetAccountNumber() == accountnumber) {
            vTrans.push_back(trans);
        }
    }
    return vTrans;
}

// Get all transactions by specific book
vector<clsTransaction> clsTransaction::GetTransactionsForBook(int book_ID) {
    vector<clsTransaction> vTrans;
    for (clsTransaction &Trans : _vTransactions) {
        if (Trans.GetBookID() == book_ID) {
            vTrans.push_back(Trans);
        }
    }
    return vTrans;
}

// Get requests counter for specific member
short clsTransaction::GetRequestsCounter(string accountnumber) {
    short counter = 0;
    vector<clsTransaction> vPending = GetPendingList();
    for (clsTransaction &trans : _vTransactions) {
        if (trans.GetAccountNumber() == accountnumber) {
            ++counter;
        }
    }
    return counter;
}

// add Borrow Record to vector
void clsTransaction::_AddBorrowRecord() {
    // add record to vector
    _vTransactions.push_back(*this);
    // save vector to file
    SaveTransactions();
}
// update Borrow Record in vector
void clsTransaction::_updateTransaction() {
    auto it = find_if(_vTransactions.begin(), _vTransactions.end(), [&](clsTransaction &record) {
        return (record.GetTrans_ID() == _TransactionID);
    });
    if (it != _vTransactions.end()) {
        *it = *this;
        // save update vector to file
        SaveTransactions();
    }
}

// create BorrowRecords register
void clsTransaction::log_borrowing_transaction(string accountnumber, int book_ID, enRole role) {
    clsTransaction record = _GetAddModeRecord(accountnumber, book_ID, role);
    if (role == enRole::STUDENT) {
        record._DueDate.AddxDays(15);
    } else if (role == enRole::TEACHER) {
        record._DueDate.AddxDays(25);
    }

    // save record
    record.save();
}

// convert enum book status to string
string clsTransaction::BookStatusToString() {
    return (_Status == enTransStatus::RETURNED) ? "RETURNED" : (_Status == enTransStatus::BORROWED) ? "BORROWED" : (_Status == enTransStatus::PENDING) ? "PENDING" : "CANCELED";
}

// convert enum eMemberRole to string
string clsTransaction::RoleToString() {
    return (_Role == enRole::STUDENT) ? "STUDENT" : (_Role == enRole::TEACHER) ? "TEACHER" : "NON";
}

// return book
void clsTransaction::ReturnBook(string checkinperformer) {
    // Assign the check-in performer
    _CheckinPerformer = checkinperformer;
    // Assign the time book is returned
    _ReturnDate = clsDate();
    // change status to returned mode
    _Status = enTransStatus::RETURNED;
    // update in vector and save to file
    _updateTransaction();
}

// is pick up book on time
bool clsTransaction::isPickupOnTime() {
    return (clsDate::DifferenceInSeconds(_CheckoutDate, clsDate()) < clsDate::HoursToSec(24));
}

// accept requests
void clsTransaction::ConfirmRequest(string performer) {
    _Status = enTransStatus::BORROWED;
    _CheckoutPerformer = performer;
    _updateTransaction();
}

// cancel the trans requests
void clsTransaction::RequestCanceled() {
    _Status = enTransStatus::CANCELED;
    _updateTransaction();
}

// expected date to recieve book
clsDate clsTransaction::ExpectedDateToRecieveBook() {
    return clsDate::AddOneDay(_CheckoutDate);
}
clsTransaction::eSaveMode clsTransaction::save() {
    switch (_Mode) {
        case enMode::EMPTY_MODE: {
            return eSaveMode::SAVE_FAILED;
            break;
        }
        case enMode::ADD_MODE: {
            _Mode = enMode::UPDATE_MODE;
            _AddBorrowRecord();
            return eSaveMode::SAVE_SUCCESS;
            break;
        }
        case enMode::UPDATE_MODE: {
            _updateTransaction();
            return eSaveMode::SAVE_SUCCESS;
            break;
        }
        default:

            break;
    }
}
