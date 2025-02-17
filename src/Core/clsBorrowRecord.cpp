#include "../../headers/Core/clsBorrowRecord.h"
#include "../../headers/Lib/clsString.h"
#include "../../headers/Lib/clsUtil.h"
#include "../../headers/Lib/constants.h"
#include <complex.h>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

const string BorrowRecordsFile = "data/BorrowHistory.txt";

// static vector hold all Borrow books Records
vector<clsBorrowRecord> clsBorrowRecord::_vBorrowRecords = {};

// constructor parameter
clsBorrowRecord::clsBorrowRecord(enMode mode, int trans_ID, string checkoutperformer, string checkinperformer, string accountnumber, int book_ID, string role, clsDate checkout_date, clsDate due_date, clsDate return_date, enStatus status) {
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
void clsBorrowRecord::SetCheckoutPerformer(string checkoutperformer) {
    _CheckoutPerformer = checkoutperformer;
}

void clsBorrowRecord::SetCheckinPerformer(string checkinperformer) {
    _CheckinPerformer = checkinperformer;
}

void clsBorrowRecord::SetTrans_ID(int trans_ID) {
    _TransactionID = trans_ID;
}
void clsBorrowRecord::SetAccountNumber(string accountnumber) {
    _AccountNumber = accountnumber;
}
void clsBorrowRecord::SetBookID(int book_ID) {
    _BookID = book_ID;
}
void clsBorrowRecord::SetRole(string role) {
    _Role = role;
}
void clsBorrowRecord::SetCheckoutDate(clsDate checkout_date) {
    _CheckoutDate = checkout_date;
}
void clsBorrowRecord::SetDueDate(clsDate due_date) {
    _DueDate = due_date;
}
void clsBorrowRecord::SetReturnDate(clsDate return_date) {
    _ReturnDate = return_date;
}
void clsBorrowRecord::SetStatus(enStatus status) {
    _Status = status;
}
// getters
string clsBorrowRecord::GetCheckoutPerformer() {
    return _CheckoutPerformer;
}
string clsBorrowRecord::GetCheckinPerformer() {
    return _CheckinPerformer;
}

int clsBorrowRecord::GetTrans_ID() {
    return _TransactionID;
}
string clsBorrowRecord::GetAccountNumber() {
    return _AccountNumber;
}
int clsBorrowRecord::GetBookID() {
    return _BookID;
}
string clsBorrowRecord::GetRole() {
    return _Role;
}
clsDate clsBorrowRecord::GetCheckoutDate() {
    return _CheckoutDate;
}
clsDate clsBorrowRecord::GetDueDate() {
    return _DueDate;
}
clsDate clsBorrowRecord::GetReturnDate() {
    return _ReturnDate;
}
clsBorrowRecord::enStatus clsBorrowRecord::GetStatus() {
    return _Status;
}

// is obj empty
bool clsBorrowRecord::isEmpty() {
    return (_Mode == enMode::EMPTY_MODE);
}

// is book returned
bool clsBorrowRecord::isBookReturned() {
    return (_Status == enStatus::RETURNED);
}

// is member exist
bool clsBorrowRecord::isAccountNumberExist(string accountnumber) {
    clsBorrowRecord record = Find(accountnumber);
    return (!record.isEmpty());
}
// is book id exist
bool clsBorrowRecord::isBookIDExist(int book_ID) {
    clsBorrowRecord record = FindByBookID(book_ID);
    return (!record.isEmpty());
}

// is transaction ID exist
bool clsBorrowRecord::isTransactionExist(int trans_ID) {
    clsBorrowRecord record = Find(trans_ID);
    return (!record.isEmpty());
}
// is transaction (accountnumber & book_ID) exist
bool clsBorrowRecord::isTransactionExist(string accountnumber, int book_ID) {
    clsBorrowRecord record = Find(accountnumber, book_ID);
    return (!record.isEmpty());
}

// find transaction by only book_ID
clsBorrowRecord clsBorrowRecord::FindByBookID(int book_ID) {
    auto it = find_if(_vBorrowRecords.begin(), _vBorrowRecords.end(), [&](clsBorrowRecord &record) {
        return (record.GetBookID() == book_ID);
    });

    if (it != _vBorrowRecords.end()) {
        return *it;
    }
    // if record not found then return empty record
    return _GetEmptyRecord();
}
// find transaction by only accountnumber
clsBorrowRecord clsBorrowRecord::Find(string accountnumber) {
    auto it = find_if(_vBorrowRecords.begin(), _vBorrowRecords.end(), [&](clsBorrowRecord &record) {
        return (record.GetAccountNumber() == accountnumber);
    });

    if (it != _vBorrowRecords.end()) {
        return *it;
    }
    // if record not found then return empty record
    return _GetEmptyRecord();
}

// find transaction by only trans_ID
clsBorrowRecord clsBorrowRecord::Find(int trans_ID) {
    auto it = find_if(_vBorrowRecords.begin(), _vBorrowRecords.end(), [&](clsBorrowRecord &record) {
        return (record.GetTrans_ID() == trans_ID);
    });

    if (it != _vBorrowRecords.end()) {
        return *it;
    }
    // if record not found then return empty record
    return _GetEmptyRecord();
}
// find transaction by AccountNumber & book_ID
clsBorrowRecord clsBorrowRecord::Find(string accountnumber, int book_ID) {
    auto it = find_if(_vBorrowRecords.begin(), _vBorrowRecords.end(), [&](clsBorrowRecord &record) {
        return (record.GetAccountNumber() == accountnumber && record.GetBookID() == book_ID);
    });

    if (it != _vBorrowRecords.end()) {
        return *it;
    }
    // if record not found then return empty record
    return _GetEmptyRecord();
}

// get empty obj
clsBorrowRecord clsBorrowRecord::_GetEmptyRecord() {

    return clsBorrowRecord(
        enMode::EMPTY_MODE, // _Mode
        DEFAULT_INT,        // _TransactionID
        DEFAULT_STR,        // _CheckoutPerformer
        DEFAULT_STR,        // _CheckinPerformer
        EMPTY_STR,          // _AccountNumber
        DEFAULT_INT,        // _BookID
        EMPTY_STR,          // _Role
        DEFAULT_DATE,       // _CheckoutDate
        DEFAULT_DATE,       // _DueDate
        DEFAULT_DATE,       // _ReturnDate
        enStatus::RETURNED  // _Status
    );
}
// Get Add BorrowRecord obj
clsBorrowRecord clsBorrowRecord::_GetAddModeRecord(string accountnumber, int book_ID, string role) {
    int transID;
    do {
        transID = clsUtil::GenerateNumber(5);
    } while (isTransactionExist(transID));

    return clsBorrowRecord(
        enMode::ADD_MODE,  // _Mode
        transID,           // _TransactionID
        DEFAULT_STR,       // _CheckoutPerformer
        DEFAULT_STR,       // _CheckinPerformer
        accountnumber,     // _AccountNumber
        book_ID,           // _BookID
        role,              // _Role
        clsDate(),         // _CheckoutDate
        clsDate(),         // _DueDate
        DEFAULT_DATE,      // _ReturnDate
        enStatus::BORROWED // _Status
    );
}

// convert line to BorrowRecord
string clsBorrowRecord::_RecordToLine(string seperator) {
    string line = "";
    line += to_string(_TransactionID) + seperator;
    line += _CheckoutPerformer + seperator;
    line += _CheckinPerformer + seperator;
    line += _AccountNumber + seperator;
    line += to_string(_BookID) + seperator;
    line += _Role + seperator;
    line += clsDate::ConvertDateToString(_CheckoutDate) + seperator;
    line += clsDate::ConvertDateToString(_DueDate) + seperator;
    line += clsDate::ConvertDateToString(_ReturnDate) + seperator;
    line += to_string((short)_Status);
    return line;
}

// convert BorrowRecords to line
clsBorrowRecord clsBorrowRecord::_LineToRecord(string line, string seperator) {
    vector<string> vStr = clsString::Split(line, seperator);
    return clsBorrowRecord(
        enMode::UPDATE_MODE,      // _Mode
        stoi(vStr[0]),            // _TransactionID
        vStr[1],                  // _CheckoutPerformer
        vStr[2],                  // _CheckinPerformer
        vStr[3],                  // _AccountNumber
        stoi(vStr[4]),            // _BookID
        vStr[5],                  // _Role
        clsDate(vStr[6]),         // _CheckoutDate
        clsDate(vStr[7]),         // _DueDate
        clsDate(vStr[8]),         // _ReturnDate
        (enStatus)stoi(vStr[9])); // _Status
}

// load BorrowRecords from file
void clsBorrowRecord::LoadBorrowRecords() {
    fstream file;
    file.open(BorrowRecordsFile, ios::in);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            clsBorrowRecord record = _LineToRecord(line);
            _vBorrowRecords.push_back(record);
        }
        file.close();
    }
}
// save BorrowRecords to file
void clsBorrowRecord::SaveBorrowRecords() {
    fstream file;
    file.open(BorrowRecordsFile, ios::out);
    if (file.is_open()) {
        for (clsBorrowRecord &record : _vBorrowRecords) {
            file << record._RecordToLine() << endl;
        }
        file.close();
    }
}

// Get BorrowRecords from vector
vector<clsBorrowRecord> &clsBorrowRecord::GetBorrowRecords() {
    return _vBorrowRecords;
}

// add Borrow Record to vector
void clsBorrowRecord::_AddBorrowRecord() {
    // add record to vector
    _vBorrowRecords.push_back(*this);
    // save vector to file
    SaveBorrowRecords();
}
// update Borrow Record in vector
void clsBorrowRecord::_updateBorrowRecord() {
    auto it = find_if(_vBorrowRecords.begin(), _vBorrowRecords.end(), [&](clsBorrowRecord &record) {
        return (record.GetTrans_ID() == _TransactionID);
    });
    if (it != _vBorrowRecords.end()) {
        *it = *this;
        // save update vector to file
        SaveBorrowRecords();
    }
}

// create BorrowRecords register
void clsBorrowRecord::log_borrowing_transaction(string accountnumber, int book_ID, string role) {
    clsBorrowRecord record = _GetAddModeRecord(accountnumber, book_ID, role);
    if (role == "student") {
        record._DueDate.AddxDays(15);
    } else {
        record._DueDate.AddxDays(25);
    }
    // save record
    record.save();
}

// convert enum book status to string
string clsBorrowRecord::BookStatusToString() {
    return (_Status == enStatus::RETURNED) ? "RETURNED" : "BORROWED";
}

// return book
void clsBorrowRecord::ReturnBook() {
    // Initialize when the time book is returned
    _ReturnDate = clsDate();
    // change status to returned mode
    _Status = enStatus::RETURNED;
    // update in vector and save to file
    _updateBorrowRecord();
}

clsBorrowRecord::eSaveMode clsBorrowRecord::save() {
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
            _updateBorrowRecord();
            return eSaveMode::SAVE_SUCCESS;
            break;
        }
        default:

            break;
    }
}
