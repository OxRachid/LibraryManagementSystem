#include "../../../../headers/Screens/UserDashboard/Transactions/clsBorrowBook.h"
#include "../../../../headers/Core/clsBook.h"
#include "../../../../headers/Core/clsMember.h"
#include "../../../../headers/Core/clsTransaction.h"
#include "../../../../headers/Lib/clsInputValidate.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// Print member data
void clsBorrowBook::_PrintMemberData(clsMember member) {
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
void clsBorrowBook::_PrintBookData(clsBook book) {
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

// Read AccountNumber for exist member
clsMember clsBorrowBook::_GetTargetMember() {
    string AccountNumber;
    bool isExist = false;
    do {
        if (isExist) {
            cout << Colors::GetRed() << " [ This AccountNumber Not Exist ]" << Colors::RESET() << endl;
        }
        AccountNumber = clsInputValidate::ReadString(" * Enter Target Member AccountNumber : ");
        isExist = !clsMember::isMemberExist(AccountNumber);
    } while (isExist);
    return clsMember::Find(AccountNumber);
}

// Get targetbook
clsBook clsBorrowBook::_GetTargetBook() {
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
void clsBorrowBook::BorrowBookScreen() {
    PrintHeaderScreen("BORROW BOOK SCREEN", "📘→👤", Colors::Magenta);
    cout << "\n\n\n";

    // Get Target member
    clsMember TargetMember = _GetTargetMember();
    // print TargetMember data
    _PrintMemberData(TargetMember);

    // check if account is Blocked
    if (TargetMember.GetAccountStatus() == clsMember::eAccountStatus::BLOCKED) {
        cout << Colors::GetRed() << " [ this Account is Blocked , you can't make any transaction ]" << Colors::RESET() << endl;
        return;
    }

    // Check borrowing book limit
    if (TargetMember.isBorrowLimitExceeded(clsTransaction::GetRequestsCounter(TargetMember.GetAccountNumber()))) {
        cout << Colors::GetRed() << " [ You have exceeded the allowed borrowing limit ]" << Colors::RESET() << endl;
        return;
    }

    // Get TargetBook
    clsBook TargetBook = _GetTargetBook();
    _PrintBookData(TargetBook);

    // checks if a member has already borrowed the same book and has not returned it yet
    if (clsTransaction::isBookStillBorrowedByMember(TargetMember.GetAccountNumber(), TargetBook.GetID())) {
        cout << Colors::GetRed() << " [ This book is in Pending or Borrowed mode  ]" << Colors::RESET() << endl;
        return;
    }

    if (clsInputValidate::AskUser("\n ⊕ Are u sure wanna borrow this book to " + TargetMember.GetFullName())) {
        // perform operation
        if (TargetBook.Borrow()) {
            // Increase total of borrowing books of TargetMember
            TargetMember.BorrowBook();
            _PrintMemberData(TargetMember);
            cout << Colors::GetGreen() << " [ Member Info After Operation ]" << Colors::RESET() << endl;
            _PrintBookData(TargetBook);
            cout << Colors::GetGreen() << " [ Book Info After Operation ]" << Colors::RESET() << endl;

            // create log borrowing record
            clsTransaction::log_borrowing_transaction(TargetMember.GetAccountNumber(), TargetBook.GetID(), (clsTransaction::enRole)(short)TargetMember.GetRole());
        } else {
            cout << Colors::GetRed() << " [ Borrowing Failed ]" << Colors::RESET() << endl;
        }
    } else {
        cout << Colors::GetRed() << " [ Borrow Canceled ]" << Colors::RESET() << endl;
    }
}
