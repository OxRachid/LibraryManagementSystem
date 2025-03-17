#include "../../../../headers/Screens/MemberDashboard/MemberOperations/clsCancelRequest.h"
#include "../../../../headers/Core/clsBook.h"
#include "../../../../headers/Core/clsMember.h"
#include "../../../../headers/Core/clsTransaction.h"
#include "../../../../headers/Core/global.h"
#include "../../../../headers/Lib/clsInputValidate.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// Print targetTrans data
void clsCancelRequest::_PrintTransData(clsTransaction &record) {
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
clsTransaction clsCancelRequest::_GetTargetTrans() {
    // Read BookID
    int BookID = clsInputValidate::ReadNumber<int>("\n * Enter Target Book ID : ");
    // Get Pending list and search for targetTrans within it and return the result of searching
    vector<clsTransaction> vPending = clsTransaction::GetPendingList();
    return clsTransaction::Find(vPending, CurrMember.GetAccountNumber(), BookID);
}

// request denied
void clsCancelRequest::_RequestCanceled(clsTransaction &TargetTrans) {
    // Get TargetBook to update data
    clsBook TargetBook = clsBook::Find(TargetTrans.GetBookID());
    // update TargetMember and TargetBook and targetTrans after the request is canceled
    // update member data
    CurrMember.ReturnBook(1);
    // update book data
    TargetBook.ReturnBook();
    // update Transaction data
    TargetTrans.RequestCanceled();
}

// Cancel Request
void clsCancelRequest::CancelRequestScreen() {
    PrintHeaderScreen("CANCEL REQUEST", "❌", Colors::Magenta);
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

    if (clsInputValidate::AskUser("\n ⊙ are u sure wanna cancel this request")) {
        // cancel the request
        _RequestCanceled(TargetTrans);
        // print trans data after canceled
        _PrintTransData(TargetTrans);
        cout << Colors::GetGreen() << " the request is canceled  " << Colors::RESET() << endl;
    } else {
        cout << Colors::GetRed() << " [ the process is canceled ]" << Colors::RESET() << endl;
    }
}
