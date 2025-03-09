#include "../../../../headers/Screens/Transactions/TransHistory/clsPendingList.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// display trans details
void clsPendingList::_DisplayTransDetails(clsTransaction trans) {
    short width = 25;
    cout << setfill(' ') << left << setw(width - 16) << trans.GetTrans_ID() << left << setw(width - 10) << trans.GetCheckoutPerformer() << left << setw(width - 10) << trans.GetCheckinPerformer() << left << setw(width - 14) << trans.GetAccountNumber() << left << setw(width - 15) << trans.GetBookID() << left << setw(width - 14) << trans.RoleToString() << left << setw(width - 12) << clsDate::ConvertDateToString(trans.GetCheckoutDate()) << left << setw(width - 12) << clsDate::ConvertDateToString(trans.GetDueDate()) << left << setw(width - 12) << clsDate::ConvertDateToString(trans.GetReturnDate()) << left << setw(width - 13) << trans.BookStatusToString() << endl;
}
// list all transactions
void clsPendingList::PendingListScreen() {
    // Get All transactions list from static vector
    const vector<clsTransaction> &vPending = clsTransaction::GetPendingList();
    PrintHeaderScreen("PENDING LIST", to_string(vPending.size()), Colors::Blue, false, 130);
    short width = 25;
    cout << Colors::GetBlue() << setfill(' ') << left << setw(width - 16) << "TransID" << left << setw(width - 10) << "OUT-Performer" << left << setw(width - 10) << "IN-Performer" << left << setw(width - 14) << "Ac-Number" << left << setw(width - 15) << "BookID" << left << setw(width - 14) << "Role" << left << setw(width - 12) << "OUT-Date" << left << setw(width - 12) << "Due-Date" << left << setw(width - 12) << "ReturnDate" << left << setw(width - 13) << "Status" << Colors::RESET() << endl;
    cout << Colors::GetBlue() << setw(130) << setfill('-') << "" << Colors::RESET() << endl;
    if (vPending.empty()) {
        cout << Colors::GetRed() << "              No Data Found" << Colors::RESET() << endl;
    } else {
        for (const clsTransaction &T : vPending) {
            _DisplayTransDetails(T);
        }
    }
    cout << Colors::GetBlue() << setw(130) << setfill('-') << "" << Colors::RESET() << endl;
}
