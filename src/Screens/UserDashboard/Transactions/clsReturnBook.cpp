#include "../../../../headers/Screens/UserDashboard/Transactions/clsReturnBook.h"
#include "../../../../headers/Core/clsBook.h"
#include "../../../../headers/Core/clsMember.h"
#include "../../../../headers/Core/clsTransaction.h"
#include "../../../../headers/Core/global.h"
#include "../../../../headers/Lib/clsInputValidate.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Print member data
void clsReturnBook::_PrintMemberData(clsMember member) {
    cout << endl;
    PrintHeaderScreen("[Member Data]", "👤", Colors::Blue, false, 41);
    cout << Colors::GetBlue() << left << setw(20) << setfill(' ') << " AccountNumber" << " : " << member.GetAccountNumber() << endl;
    cout << left << setw(20) << " Firstname" << " : " << member.GetFirstName() << endl;
    cout << left << setw(20) << " Lastname" << " : " << member.GetLastName() << endl;
    cout << left << setw(20) << " Email" << " : " << member.GetEmail() << endl;
    cout << left << setw(20) << " Phone" << " : " << member.GetPhone() << endl;
    cout << left << setw(20) << " Role" << " : " << member.MemberRoleToString() << endl;
    cout << left << setw(20) << " Borrowed Books" << " : " << member.GetTotalBorrowedBooks() << endl;
    cout << left << setw(20) << " Violations" << " : " << member.GetViolations() << endl;
    cout << left << setw(20) << " Account Created on" << " : " << clsDate::ConvertDateToString(member.GetAccountCreated_on()) << endl;
    cout << left << setw(20) << " Account Status" << " : " << member.AccountStatusToString() << endl;
    cout << setw(41) << setfill('-') << "" << Colors::RESET() << endl;
}

// Print Book data
void clsReturnBook::_PrintBookData(clsBook book) {
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

// Print Transaction data
void clsReturnBook::_PrintTransData(clsTransaction record) {
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

// Get target Transaction
clsTransaction clsReturnBook::_GetTargetTransaction(string &accountnumber, int &bookID) {
    accountnumber = clsInputValidate::ReadString("\n * Enter AccountNumber : ");
    bookID = clsInputValidate::ReadNumber<int>(" * Enter Book ID : ");
    // Search in vector of Borrowed books
    vector<clsTransaction> vBorrowed = clsTransaction::GetBorrowedList();
    return clsTransaction::Find(vBorrowed, accountnumber, bookID);
}

// Borrow Book Screen
void clsReturnBook::ReturnBookScreen() {
    PrintHeaderScreen("RETURN BOOK", "🔰", Colors::Cyan);
    cout << "\n\n\n";

    string accountnumber;
    int bookID;
    // Get the Target Transaction
    clsTransaction TargetTrans = _GetTargetTransaction(accountnumber, bookID);
    if (TargetTrans.isEmpty()) {
        cout << Colors::GetRed() << " [ Transaction info Not Exist ]" << Colors::RESET() << endl;
        return;
    }

    // Get targetbook and TargetMember after the Transaction is found
    clsMember TargetMember = clsMember::Find(accountnumber);
    clsBook TargetBook = clsBook::Find(bookID);

    // print target Transaction and member and book detailes
    _PrintTransData(TargetTrans);
    _PrintMemberData(TargetMember);
    _PrintBookData(TargetBook);

    if (clsInputValidate::AskUser("\n ⊕ Are u sure wanna return this book")) {
        // update Transaction record
        TargetTrans.ReturnBook(CurrUser.GetUsername());
        // Check if the returned date is late
        short deffDays = 0;
        if (clsDate::isDate1AfterDate2(TargetTrans.GetReturnDate(), TargetTrans.GetDueDate())) {
            deffDays = clsDate::DifferenceInDays(TargetTrans.GetDueDate(), TargetTrans.GetReturnDate(), true);
        }
        // update member data
        TargetMember.ReturnBook(deffDays);
        // update book data
        TargetBook.ReturnBook();

        _PrintTransData(TargetTrans);
        _PrintMemberData(TargetMember);
        _PrintBookData(TargetBook);

        cout << Colors::GetGreen() << " [ Book Returned Succesfully ]" << Colors::RESET() << endl;
    } else {
        cout << Colors::GetRed() << " [ Return canceled ]" << Colors::RESET() << endl;
    }
}
