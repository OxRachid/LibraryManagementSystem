#include "../../../../headers/Screens/UserDashboard/System/clsStatistics.h"
#include "../../../../headers/Core/clsBook.h"
#include "../../../../headers/Core/clsMember.h"
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
using namespace std;

// print line percentage
void clsStatistics::_PrintLinePercentage(int Total, float length) {
    cout << "(" << length << ") ";
    for (short i = 0; i < length; i++) {
        cout << Colors::GetGreen() << "─";
    }
    cout << " " << fixed << setprecision(1) << static_cast<float>((length / Total)) * 100 << "%" << Colors::RESET();
    cout << fixed << setprecision(0) << endl;
}

// books report
void clsStatistics::_BooksReport() {
    cout << Colors::GetBlue() << " [ Books Report ]" << Colors::RESET() << endl;
    int TotalBooks = clsBook::TotalBooks_Size();
    cout << "   • Total books ";
    _PrintLinePercentage(TotalBooks, TotalBooks);
    cout << "   • Available books ";
    _PrintLinePercentage(TotalBooks, clsBook::AvailableBooks_Size());
}
// members report
void clsStatistics::_MembersReport() {
    cout << Colors::GetBlue() << "\n [ Members Report ]" << Colors::RESET() << endl;
    int TotalMembers = clsMember::TotalMembers_Size();
    cout << "   • Total Members ";
    _PrintLinePercentage(TotalMembers, TotalMembers);
    cout << "   • Students ";
    _PrintLinePercentage(TotalMembers, clsMember::Students_Size());
    cout << "   • Teachers ";
    _PrintLinePercentage(TotalMembers, clsMember::Teachers_Size());
}
// Transactions report
void clsStatistics::_TransactionsReport() {
    cout << Colors::GetBlue() << "\n [ Transactions Report ]" << Colors::RESET() << endl;
    int TotalTrans = clsTransaction::TransList_size();
    cout << "   • Total Transactions ";
    _PrintLinePercentage(TotalTrans, TotalTrans);
    cout << "   • Pending ";
    _PrintLinePercentage(TotalTrans, clsTransaction::PendingList_size());
    cout << "   • Borrowed ";
    _PrintLinePercentage(TotalTrans, clsTransaction::BorrowedList_size());
    cout << "   • Returned ";
    _PrintLinePercentage(TotalTrans, clsTransaction::ReturnedList_size());
    cout << "   • Canceled ";
    _PrintLinePercentage(TotalTrans, clsTransaction::CanceledList_size());
}
//  users report
void clsStatistics::_UsersReport() {
    cout << Colors::GetBlue() << "\n [ Users Report ]" << Colors::RESET() << endl;
    int TotalUsers = clsUser::UsersList_size();
    cout << "   • Total Users ";
    _PrintLinePercentage(TotalUsers, TotalUsers);
}

// update system
void clsStatistics::StatisticsScreen() {
    PrintHeaderScreen("STATISTICS", "📊", Colors::Yellow);
    cout << "\n\n";

    // books report
    _BooksReport();
    // members report
    _MembersReport();
    // Transactions report
    _TransactionsReport();
    // users report
    _UsersReport();
}
