#include "../../../headers/Screens/Transactions/clsCheckRequests.h"
#include "../../../headers/Core/clsTransaction.h"
#include "../../../headers/Core/global.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Print targetTrans data
void clsCheckRequests::_PrintTransData(clsTransaction &record) {
    cout << endl;
    PrintHeaderScreen("[Transaction Data]", "💡", Colors::Blue, false, 41);
    cout << Colors::GetBlue() << left << setw(20) << setfill(' ') << " Transaction ID" << " : " << record.GetTrans_ID() << endl;
    cout << left << setw(20) << " Checkout Performer" << " : " << record.GetCheckoutPerformer() << endl;
    cout << left << setw(20) << " Checkin Performer" << " : " << record.GetCheckinPerformer() << endl;
    cout << left << setw(20) << " AccountNumber" << " : " << record.GetAccountNumber() << endl;
    cout << left << setw(20) << " Book ID" << " : " << record.GetBookID() << endl;
    cout << left << setw(20) << " Role" << " : " << record.RoleToString() << endl;
    cout << left << setw(20) << " Checkout Date" << " : " << clsDate::ConvertDateToString(record.GetCheckoutDate()) << endl;
    cout << left << setw(20) << " Due Date" << " : " << clsDate::ConvertDateToString(record.GetDueDate()) << endl;
    cout << left << setw(20) << " Return Date" << " : " << clsDate::ConvertDateToString(record.GetReturnDate()) << endl;
    cout << left << setw(20) << " Status" << " : " << record.BookStatusToString() << endl;
    cout << setw(41) << setfill('-') << "" << Colors::RESET() << endl;
}

// get target trans
clsTransaction clsCheckRequests::_GetTargetTrans() {
    // Read AccountNumber and BookID
    string AccountNumber = clsInputValidate::ReadString(" * Enter Target Member AccountNumber : ");
    int BookID = clsInputValidate::ReadNumber<int>("\n * Enter Target Book ID : ");
    // Get Pending list and search for targetTrans within it and return the result of searching
    vector<clsTransaction> vPending = clsTransaction::GetPendingList();
    return clsTransaction::Find(vPending, AccountNumber, BookID);
}

// request denied
void clsCheckRequests::_RequestDenied(clsTransaction &TargetTrans) {
    // Get TargetMember and TargetBook to update thier data
    clsMember TargetMember = clsMember::Find(TargetTrans.GetAccountNumber());
    clsBook TargetBook = clsBook::Find(TargetTrans.GetBookID());
    // update TargetMember and TargetBook and targetTrans after the request is canceled
    // update member data
    TargetMember.ReturnBook(true);
    // update book data
    TargetBook.ReturnBook();
    // update Transaction data
    TargetTrans.RequestCanceled();

    cout << Colors::GetRed() << "\n [ the request is canceled, the ticket date is expired ]" << Colors::RESET() << endl;
    cout << Colors::GetRed() << " > the expected time to recieve the book is between : \n ( " << clsDate::GetDateAndTimeForPrint(TargetTrans.GetCheckoutDate()) << " - " << clsDate::GetDateAndTimeForPrint(TargetTrans.ExpectedDateToRecieveBook()) << " )" << Colors::RESET() << endl;
    _PrintTransData(TargetTrans);
}

// check requests
void clsCheckRequests::CheckRequestsScreen() {
    PrintHeaderScreen("CHECK REQUESTS", "📥", Colors::Yellow);
    cout << "\n\n";

    // Get TargetTrans
    clsTransaction TargetTrans = _GetTargetTrans();

    // check if targetTrans is empty
    if (TargetTrans.isEmpty()) {
        cout << Colors::GetRed() << " [ There is no Pending request ]" << Colors::RESET() << endl;
        return;
    }

    //  if targetTrans is exist then  print TargetTrans data
    _PrintTransData(TargetTrans);

    // check if pick up on time
    if (!TargetTrans.isPickupOnTime()) {
        _RequestDenied(TargetTrans);
        return;
    }

    // perform the action
    if (clsInputValidate::AskUser("\n ⊕ are you sure wanna confirm this request")) {
        // confirm request
        TargetTrans.ConfirmRequest(CurrUser.GetUsername());
        // print trans after updating data
        _PrintTransData(TargetTrans);
        cout << Colors::GetGreen() << " [  the request is confirmed  ]" << Colors::RESET() << endl;
    } else {
        cout << Colors::GetRed() << " [ the process is canceled ]" << Colors::RESET() << endl;
    }
}
