#include "../../../headers/Screens/Books/clsDeleteBook.h"
#include "../../../headers/Core/clsBook.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// print new book data
void clsDeleteBook::_PrintBook(clsBook book) {
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
    cout << setw(36) << setfill('-') << "" << Colors::RESET() << endl;
}

// Read Book ID
int clsDeleteBook::_ReadBookID() {
    int BookID = clsInputValidate::ReadNumber<int>("\n ^ Enter Book ID : ");
    while (!clsBook::isBookExist(BookID)) {
        cout << Colors::GetRed() << " [ This Book ID does't Exist ]" << Colors::RESET() << endl;
        BookID = clsInputValidate::ReadNumber<int>("\n ^ Please Enter a valid Book ID : ");
    }
    return BookID;
}

// Get Book for Delete
clsBook clsDeleteBook::_GetBook() {
    int BookID = _ReadBookID();
    return clsBook::Find(BookID);
}

// Delete Book screen
void clsDeleteBook::DeleteBookScreen() {
    PrintHeaderScreen("DELETE BOOK SCREEN", "-📘", Colors::Red);
    cout << "\n\n";

    // Get book obj for delete
    clsBook book = _GetBook();
    // print book data
    _PrintBook(book);
    if (clsInputValidate::AskUser("\n ⊙ Are u sure wanna Delete this Book")) {
        // perform deletion
        if (book.Delete()) {
            // print book data
            _PrintBook(book);
            cout << Colors::GetGreen() << " □ Book deleted succesfully ✓ " << Colors::RESET() << endl;
        } else {
            cout << Colors::GetRed() << " [ The process was Failed ]" << Colors::RESET() << endl;
        }
    } else {
        cout << Colors::GetRed() << " [ Book Delete is canceled ]" << Colors::RESET() << endl;
    }
}
