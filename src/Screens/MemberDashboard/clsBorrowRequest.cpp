#include "../../../headers/Screens/MemberDashboard/clsBorrowRequest.h"
#include "../../../headers/Core/clsBook.h"
#include "../../../headers/Core/clsMember.h"
#include "../../../headers/Core/clsTransaction.h"
#include "../../../headers/Core/global.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// Print Book data
void clsBorrowRequest::_PrintBookData(clsBook book) {
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

// Print targetTrans data
void clsBorrowRequest::_PrintTransData(clsTransaction &record) {
    cout << endl;
    PrintHeaderScreen("[Transaction Data]", "💡", Colors::Magenta, false, 41);
    cout << Colors::GetMagenta() << left << setw(20) << setfill(' ') << " Transaction ID" << " : " << record.GetTrans_ID() << endl;
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

// Get targetbook
clsBook clsBorrowRequest::_GetTargetBook() {
    int BookID;
    bool isExist = false;
    do {
        if (isExist) {
            cout << Colors::GetRed() << " [ this book isn't available ]" << Colors::RESET() << endl;
        }
        BookID = clsInputValidate::ReadNumber<int>("\n * Enter Target Book ID : ");
        isExist = !clsBook::isBookAvailable(BookID);
    } while (isExist);
    return clsBook::Find(BookID);
}

// Borrow Book Screen
void clsBorrowRequest::BorrowRequestScreen() {
    PrintHeaderScreen("BORROW REQUEST", "📘→👤", Colors::Magenta);
    cout << "\n\n\n";

    // check if account is Blocked
    if (CurrMember.GetAccountStatus() == clsMember::eAccountStatus::BLOCKED) {
        cout << Colors::GetRed() << " [ Your Account is Blocked , you can't make any Request ]" << Colors::RESET() << endl;
        return;
    }

    // Check borrowing book limit
    if (CurrMember.isBorrowLimitExceeded()) {
        cout << Colors::GetRed() << " [ You have exceeded the allowed borrowing limit ]" << Colors::RESET() << endl;
        cout << Colors::GetRed() << " [ You Borrowed " << CurrMember.GetTotalBorrowedBooks() << " Books ]" << Colors::RESET() << endl;
        return;
    }

    // Get TargetBook
    clsBook TargetBook = _GetTargetBook();
    _PrintBookData(TargetBook);

    // checks if a member has already borrowed the same book and has not returned it yet
    if (clsTransaction::isBookStillBorrowedByMember(CurrMember.GetAccountNumber(), TargetBook.GetID())) {
        cout << Colors::GetRed() << " [ This book is in your Pending or Borrowed mode  ]" << Colors::RESET() << endl;
        return;
    }

    if (clsInputValidate::AskUser("\n ⊕ Are u sure wanna borrow this book ")) {
        // perform operation
        if (TargetBook.Borrow()) {
            // Increase total of borrowing books of CurrMember
            CurrMember.BorrowBook();

            // create log borrowing record
            clsTransaction::log_borrowing_transaction(CurrMember.GetAccountNumber(), TargetBook.GetID(), (clsTransaction::enRole)(short)CurrMember.GetRole());
            clsTransaction trans = clsTransaction::Find(CurrMember.GetAccountNumber(), TargetBook.GetID());
            _PrintTransData(trans);
            cout << Colors::GetGreen() << "\n Request sent succesfully  " << Colors::RESET() << endl;
            cout << Colors::GetBoldCyan() << "\n > the expected time to recieve the book is between : \n ( " << clsDate::GetDateAndTimeForPrint(clsDate()) << " - " << clsDate::GetDateAndTimeForPrint(clsDate::AddOneDay(clsDate())) << " )" << Colors::RESET() << endl;
        } else {
            cout << Colors::GetRed() << " [ Borrow Request Failed ]" << Colors::RESET() << endl;
        }
    } else {
        cout << Colors::GetRed() << " [ Borrow Request Canceled ]" << Colors::RESET() << endl;
    }
}
