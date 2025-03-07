#include "../../../headers/Screens/Transactions/clsTrackBooks.h"
#include "../../../headers/Core/clsBook.h"
#include "../../../headers/Core/clsTransaction.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// display trans detailes
void clsTrackBooks::_DisplayTransDetailes(clsTransaction trans) {
    short width = 24;
    cout << Colors::GetYellow() << setfill(' ') << left << setw(width - 17) << trans.GetTrans_ID() << left << setw(width - 17) << trans.GetAccountNumber() << left << setw(width - 16) << trans.GetBookID() << left << setw(width - 13) << clsDate::ConvertDateToString(trans.GetCheckoutDate()) << left << setw(width - 13) << clsDate::ConvertDateToString(trans.GetDueDate()) << left << setw(width - 13) << clsDate::ConvertDateToString(trans.GetReturnDate()) << left << setw(width - 13) << trans.BookStatusToString() << Colors::RESET() << endl;
}
// print book data
void clsTrackBooks::_PrintBookData(clsBook book) {
    cout << endl;
    PrintHeaderScreen("[Book Data]", "📘", Colors::Blue, false, 41);
    cout << Colors::GetBlue() << left << setw(20) << setfill(' ') << " ID" << " : " << book.GetID() << endl;
    cout << left << setw(20) << " Title" << " : " << book.GetTitle() << endl;
    cout << left << setw(20) << " Author" << " : " << book.GetAuthor() << endl;
    cout << left << setw(20) << " ISBN" << " : " << book.GetISBN() << endl;
    cout << left << setw(20) << " Edition" << " : " << book.GetEdition() << endl;
    cout << left << setw(20) << " Genre" << " : " << book.GetGenre() << endl;
    cout << left << setw(20) << " P-Date" << " : " << clsDate::ConvertDateToString(book.GetPublicationDate()) << endl;
    cout << left << setw(20) << " Total Copies" << " : " << book.GetTotalCopies() << endl;
    cout << left << setw(20) << " Available Copies" << " : " << book.GetAvailableCopies() << endl;
    cout << left << setw(20) << " Borrowed Copies" << " : " << book.GetBorrowedCopies() << endl;
    cout << setw(41) << setfill('-') << "" << Colors::RESET() << endl;
}
// Get targetmember
clsBook clsTrackBooks::_GetTargetBook() {
    int BookID;
    bool isExist = false;
    do {
        if (isExist) {
            cout << Colors::GetRed() << " [ Book not found ]" << Colors::RESET() << endl;
        }
        BookID = clsInputValidate::ReadNumber<int>("\n * Enter Target Book ID : ");
        isExist = !clsBook::isBookExist(BookID);
    } while (isExist);
    return clsBook::Find(BookID);
}
// Print transactions history
void clsTrackBooks::_ShowTransHistory(int bookID) {
    // Get All transactions list from static vector
    const vector<clsTransaction> &vBookTrans = clsTransaction::GetTransactionsForBook(bookID);
    PrintHeaderScreen("BOOK HISTORY", to_string(vBookTrans.size()), Colors::Cyan, false);
    short width = 24;
    cout << Colors::GetCyan() << setfill(' ') << left << setw(width - 17) << "TrsID" << left << setw(width - 17) << "Ac-N" << left << setw(width - 16) << "BookID" << left << setw(width - 13) << "OUT-Date" << left << setw(width - 13) << "Due-Date" << left << setw(width - 13) << "ReturnDate" << left << setw(width - 13) << "Status" << Colors::RESET() << endl;
    cout << Colors::GetCyan() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
    if (vBookTrans.empty()) {
        cout << Colors::GetRed() << "              No Data Found" << Colors::RESET() << endl;
    } else {
        for (const clsTransaction &T : vBookTrans) {
            _DisplayTransDetailes(T);
        }
    }
    cout << Colors::GetCyan() << setw(66) << setfill('-') << "" << Colors::RESET() << endl;
}

// track members screen
void clsTrackBooks::TrackBooksScreen() {
    PrintHeaderScreen("TRACK BOOKS", "👓", Colors::Magenta);
    cout << "\n\n\n";

    // Get targetmember
    clsBook TargetBook = _GetTargetBook();
    // Show member detailes
    cout << "\n [ PROFILE ]" << endl;
    _PrintBookData(TargetBook);

    // Display his Transactions history
    cout << "\n [ HISTORY ]\n" << endl;
    _ShowTransHistory(TargetBook.GetID());
}
