#include "../../../headers/Screens/Books/clsUpdateBook.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// Read ISBN
string clsUpdateBook::_ReadISBN() {
    string ISBN;
    bool isExist = false;
    do {
        if (isExist) {
            cout << Colors::GetRed() << " [ This Book ISBN is already exist ]" << Colors::RESET() << endl;
        }
        ISBN = clsInputValidate::ReadString("\n * Enter New ISBN : ");
        isExist = clsBook::isBookExist(ISBN);
    } while (isExist);

    return ISBN;
}

clsDate clsUpdateBook::_GetDateFromUser() {
    clsDate date;
    date.SetYear(clsInputValidate::ReadNumber<short>("\n ⊙ Year : "));
    date.SetMonth(clsInputValidate::ReadNumber<short>(" ⊙ Mon : "));
    date.SetDay(clsInputValidate::ReadNumber<short>(" ⊙ Day : "));
    cout << Colors::GetBoldCyan() << "───────────────────────────" << Colors::RESET() << endl;
    return date;
}

// Read publication date
clsDate clsUpdateBook::_ReadPublicationDate() {
    clsDate date;
    do {
        if (!date.isValid()) {
            cout << Colors::GetRed() << " [ Date is invalid ]" << Colors::RESET() << endl;
        }
        date = _GetDateFromUser();
    } while (!date.isValid());
    return date;
}

// print new book data
void clsUpdateBook::_PrintBook(clsBook book) {
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
int clsUpdateBook::_ReadBookID() {
    int BookID = clsInputValidate::ReadNumber<int>("\n ^ Enter Book ID : ");
    while (!clsBook::isBookExist(BookID)) {
        cout << Colors::GetRed() << " [ This Book ID does't Exist ]" << Colors::RESET() << endl;
        BookID = clsInputValidate::ReadNumber<int>("\n ^ Please Enter a valid Book ID : ");
    }
    return BookID;
}

// Get Book for Delete
clsBook clsUpdateBook::_GetBook() {
    int BookID = _ReadBookID();
    return clsBook::Find(BookID);
}

// Read New book data
void clsUpdateBook::_ReadNewBookData(clsBook &book) {
    PrintHeaderScreen("Read New Data", "📍", Colors::Magenta, false, 54);
    if (clsInputValidate::AskUser("\n □ Rename Title")) {
        book.SetTitle(clsInputValidate::ReadString("\n * Enter New Title : "));
        cout << Colors::GetGreen() << " [ Title Renamed Succesfully ]" << endl;
    }
    if (clsInputValidate::AskUser("\n □ Rename Author")) {
        book.SetAuthor(clsInputValidate::ReadString("\n * Enter New Author : "));
        cout << Colors::GetGreen() << " [ Author Renamed Succesfully ]" << endl;
    }
    if (clsInputValidate::AskUser("\n □ Update ISBN")) {
        string ISBN = _ReadISBN();
        book.SetISBN(ISBN);
        cout << Colors::GetGreen() << " [ ISBN Update Succesfully ]" << endl;
    }
    if (clsInputValidate::AskUser("\n □ Update Edition")) {
        book.SetEdition(clsInputValidate::ReadNumber<short>("\n * Enter New Edition : "));
        cout << Colors::GetGreen() << " [ Edition Update Succesfully ]" << endl;
    }
    if (clsInputValidate::AskUser("\n □ Update Genre")) {
        book.SetGenre(clsInputValidate::ReadString("\n * Enter New Genre : "));
        cout << Colors::GetGreen() << " [ Genre Update Succesfully ]" << endl;
    }
    if (clsInputValidate::AskUser("\n □ Update Publication Date")) {
        clsDate date = _ReadPublicationDate();
        book.SetPublicationDate(date);
        cout << Colors::GetGreen() << " [ Publication Date Update Succesfully ]" << endl;
    }
    if (clsInputValidate::AskUser("\n □ Update Total Copies")) {
        book.SetTotalCopies(clsInputValidate::ReadNumber<short>("\n * Enter New Total Copies : "));
        cout << Colors::GetGreen() << " [ Total Copies Update Succesfully ]" << endl;
    }
    if (clsInputValidate::AskUser("\n □ Update Available Copies")) {
        book.SetAvailableCopies(clsInputValidate::ReadNumber<short>("\n * Enter New Available Copies : "));
        cout << Colors::GetGreen() << " [ Available Copies Update Succesfully ]" << endl;
    }
    if (clsInputValidate::AskUser("\n □ Update Borrowed Copies")) {
        book.SetBorrowedCopies(clsInputValidate::ReadNumber<short>("\n * Enter New Borrowed Copies : "));
        cout << Colors::GetGreen() << " [ Borrowed Copies Update Succesfully ]" << endl;
    }
}

// Update book
void clsUpdateBook::UpdateBookScreen() {
    PrintHeaderScreen("UPDATE BOOK SCREEN", "📘🔧", Colors::Magenta);
    cout << "\n\n";

    // Get Book For update
    clsBook book = _GetBook();
    _PrintBook(book);
    if (clsInputValidate::AskUser(" ⊕ Are u sure wanna update [" + book.GetTitle() + "]")) {
        // Read New Data
        _ReadNewBookData(book);
        clsBook::enSaveMode Result = book.save();
        switch (Result) {
            case clsBook::enSaveMode::SaveSuccess: {
                _PrintBook(book);
                cout << Colors::GetGreen() << " [ Book Update Succesfully ]" << Colors::RESET() << endl;
                break;
            }
            case clsBook::enSaveMode::SaveFailed: {
                cout << Colors::GetRed() << " [ Book Update Faild ]" << Colors::RESET() << endl;
                break;
            }
            default:
                break;
        }
    } else {

        cout << Colors::GetRed() << " [ Update Canceled ]" << Colors::RESET() << endl;
    }
}
