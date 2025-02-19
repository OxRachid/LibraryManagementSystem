#include "../../../../headers/Screens/Transactions/TransHistory/clsListAllTrans.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// display trans details
void clsListAllTrans::_DisplayTransDetails(clsTransaction trans) {
    short width = 25;
    cout << Colors::GetCyan() << setfill(' ') << left << setw(width - 16) << trans.GetTrans_ID() << left << setw(width - 10) << trans.GetCheckoutPerformer() << left << setw(width - 10) << trans.GetCheckinPerformer() << left << setw(width - 14) << trans.GetAccountNumber() << left << setw(width - 15) << trans.GetBookID() << left << setw(width - 14) << trans.RoleToString() << left << setw(width - 12) << clsDate::ConvertDateToString(trans.GetCheckoutDate()) << left << setw(width - 12) << clsDate::ConvertDateToString(trans.GetDueDate()) << left << setw(width - 12) << clsDate::ConvertDateToString(trans.GetReturnDate()) << left << setw(width - 13) << trans.BookStatusToString() << Colors::RESET() << endl;
}
// list all transactions
void clsListAllTrans::ListAllTransScreen() {
    // Get All transactions list from static vector
    const vector<clsTransaction> &vTrans = clsTransaction::GetTransactionsList();
    PrintHeaderScreen("ALL TRANS LIST", to_string(vTrans.size()), Colors::Blue, false, 130);
    short width = 25;
    cout << Colors::GetBlue() << setfill(' ') << left << setw(width - 16) << "TransID" << left << setw(width - 10) << "OUT-Performer" << left << setw(width - 10) << "IN-Performer" << left << setw(width - 14) << "Ac-Number" << left << setw(width - 15) << "BookID" << left << setw(width - 14) << "Role" << left << setw(width - 12) << "OUT-Date" << left << setw(width - 12) << "Due-Date" << left << setw(width - 12) << "ReturnDate" << left << setw(width - 13) << "Status" << Colors::RESET() << endl;
    cout << Colors::GetBlue() << setw(130) << setfill('-') << "" << Colors::RESET() << endl;
    if (vTrans.empty()) {
        cout << Colors::GetRed() << "               No Data Found" << Colors::RESET() << endl;
    } else {
        for (const clsTransaction &T : vTrans) {
            _DisplayTransDetails(T);
        }
    }
    cout << Colors::GetBlue() << setw(130) << setfill('-') << "" << Colors::RESET() << endl;
}
