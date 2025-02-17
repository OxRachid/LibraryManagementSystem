#include "../../../headers/Screens/Transactions/clsReturnBook.h"
#include "../../../headers/Core/clsBook.h"
#include "../../../headers/Core/clsBorrowRecord.h"
#include "../../../headers/Core/clsMember.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include <iomanip>
#include <iostream>
#include <string>
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
    cout << left << setw(20) << " Role" << " : " << member.GetRole() << endl;
    cout << left << setw(20) << " Borrowed Books" << " : " << member.GetTotalBorrowedBooks() << endl;
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
void clsReturnBook::_PrintTransData(clsBorrowRecord record) {
    cout << endl;
    PrintHeaderScreen("[Transaction Data]", "💡", Colors::Blue, false, 41);
    cout << Colors::GetBlue() << left << setw(20) << setfill(' ') << " Transaction ID" << " : " << record.GetTrans_ID() << endl;
    cout << left << setw(20) << " Checkout Performer" << " : " << record.GetCheckoutPerformer() << endl;
    cout << left << setw(20) << " Checkin Performer" << " : " << record.GetCheckinPerformer() << endl;
    cout << left << setw(20) << " AccountNumber" << " : " << record.GetAccountNumber() << endl;
    cout << left << setw(20) << " Book ID" << " : " << record.GetBookID() << endl;
    cout << left << setw(20) << " Checkout Date" << " : " << clsDate::ConvertDateToString(record.GetCheckoutDate()) << endl;
    cout << left << setw(20) << " Due Date" << " : " << clsDate::ConvertDateToString(record.GetDueDate()) << endl;
    cout << left << setw(20) << " Return Date" << " : " << clsDate::ConvertDateToString(record.GetReturnDate()) << endl;
    cout << left << setw(20) << " Status" << " : " << record.BookStatusToString() << endl;
    cout << setw(41) << setfill('-') << "" << Colors::RESET() << endl;
}

// Get target Transaction
clsBorrowRecord clsReturnBook::_GetTargetTransaction(string &accountnumber, int &bookID) {
    bool isExist = false;
    do {
        if (isExist) {
            cout << Colors::GetRed() << " [ Transaction info Not Exist ]" << Colors::RESET() << endl;
        }
        accountnumber = clsInputValidate::ReadString("\n * Enter AccountNumber : ");
        bookID = clsInputValidate::ReadNumber<int>(" * Enter Book ID : ");
        isExist = !clsBorrowRecord::isTransactionExist(accountnumber, bookID);
    } while (isExist);
    return clsBorrowRecord::Find(accountnumber, bookID);
}

// Borrow Book Screen
void clsReturnBook::ReturnBookScreen() {
    PrintHeaderScreen("RETURN BOOK", "🔰", Colors::Cyan);
    cout << "\n\n\n";

    string accountnumber;
    int bookID;
    // Get the Target Transaction
    clsBorrowRecord TargetTrans = _GetTargetTransaction(accountnumber, bookID);
    // print target Transaction
    _PrintTransData(TargetTrans);
    // check if book was already returnd
    if (TargetTrans.isBookReturned()) {
        cout << Colors::GetRed() << " [ This book is already returned ]" << Colors::RESET() << endl;
        return;
    }

    // Get targetbook and TargetMember after the Transaction is found
    clsMember TargetMember = clsMember::Find(accountnumber);
    clsBook TargetBook = clsBook::Find(bookID);

    _PrintMemberData(TargetMember);
    _PrintBookData(TargetBook);

    if (clsInputValidate::AskUser("\n ⊕ Are u sure wanna return this book")) {
        // update Transaction record
        TargetTrans.ReturnBook();
        // Check if the returned time is late
        bool isLate = clsDate::isDate1AfterDate2(TargetTrans.GetReturnDate(), TargetTrans.GetDueDate());
        // update member data
        TargetMember.ReturnBook(isLate);
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
