#include "../../../../headers/Screens/Transactions/TransHistory/clsCanceledList.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// display trans details
void clsCanceledList::_DisplayTransDetails(clsTransaction trans) {
    short width = 25;
    cout << setfill(' ') << left << setw(width - 16) << trans.GetTrans_ID() << left << setw(width - 10) << trans.GetCheckoutPerformer() << left << setw(width - 10) << trans.GetCheckinPerformer() << left << setw(width - 14) << trans.GetAccountNumber() << left << setw(width - 15) << trans.GetBookID() << left << setw(width - 14) << trans.RoleToString() << left << setw(width - 12) << clsDate::ConvertDateToString(trans.GetCheckoutDate()) << left << setw(width - 12) << clsDate::ConvertDateToString(trans.GetDueDate()) << left << setw(width - 12) << clsDate::ConvertDateToString(trans.GetReturnDate()) << left << setw(width - 13) << trans.BookStatusToString() << endl;
}
// list all transactions
void clsCanceledList::CanceledListScreen() {
    // Get All transactions list from static vector
    const vector<clsTransaction> &vCanceled = clsTransaction::GetCanceledList();
    PrintHeaderScreen("CANCELED LIST", to_string(vCanceled.size()), Colors::Red, false, 130);
    short width = 25;
    cout << Colors::GetRed() << setfill(' ') << left << setw(width - 16) << "TransID" << left << setw(width - 10) << "OUT-Performer" << left << setw(width - 10) << "IN-Performer" << left << setw(width - 14) << "Ac-Number" << left << setw(width - 15) << "BookID" << left << setw(width - 14) << "Role" << left << setw(width - 12) << "OUT-Date" << left << setw(width - 12) << "Due-Date" << left << setw(width - 12) << "ReturnDate" << left << setw(width - 13) << "Status" << Colors::RESET() << endl;
    cout << Colors::GetRed() << setw(130) << setfill('-') << "" << Colors::RESET() << endl;
    if (vCanceled.empty()) {
        cout << Colors::GetRed() << "              No Data Found" << Colors::RESET() << endl;
    } else {
        for (const clsTransaction &T : vCanceled) {
            _DisplayTransDetails(T);
        }
    }
    cout << Colors::GetRed() << setw(130) << setfill('-') << "" << Colors::RESET() << endl;
}
