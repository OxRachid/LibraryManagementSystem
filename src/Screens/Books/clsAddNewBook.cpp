#include "../../../headers/Screens/Books/clsAddNewBook.h"
#include "../../../headers/Core/clsBook.h"
#include "../../../headers/Lib/clsInputValidate.h"
#include <iomanip>
#include <iostream>
#include <regex>
#include <string>
using namespace std;

// Read publication date
clsDate clsAddNewBook::_ReadPublicationDate() {
    clsDate date;
    do {
        date = clsDate(clsInputValidate::ReadString(" ^ Enter Publication Date : "));
    } while (!date.isValid());
    return date;
}

// print new book data
void clsAddNewBook::_PrintBookData(clsBook book) {
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
    cout << setw(36) << setfill('-') << "" << Colors::RESET() << endl;
}

// Read ISBN
string clsAddNewBook::_ReadISBN() {
    PrintHeaderScreen("Read Book Data", "📝", Colors::Magenta, false, 41);
    if (clsInputValidate::AskUser("\n □ Is This book has ISBN")) {
        string ISBN = clsInputValidate::ReadString("\n * Enter Book ISBN : ");
        while (clsBook::isBookExist(ISBN)) {
            cout << Colors::GetRed() << " [ This Book ISBN is already exist ]" << Colors::RESET() << endl;
            ISBN = clsInputValidate::ReadString("\n * Please Enter New Book ISBN : ");
        }
        return ISBN;
    }
    return "";
}

// Read book data
bool clsAddNewBook::_ReadBookData(clsBook &book) {
    book.SetTitle(clsInputValidate::ReadString(" ^ Enter Title : "));
    book.SetAuthor(clsInputValidate::ReadString(" ^ Enter Author : "));
    book.SetEdition(clsInputValidate::ReadNumber<short>(" ^ Enter Edition : "));
    if (book.GetISBN() == "") {
        if (clsBook::isBookExist(book.GetTitle(), book.GetAuthor(), book.GetEdition())) {
            return false;
        }
    }
    book.SetGenre(clsInputValidate::ReadString(" ^ Enter Genre : "));
    clsDate date = _ReadPublicationDate();
    book.SetPublicationDate(date);
    short TotalCopies = clsInputValidate::ReadNumber<short>(" ^ Enter Total Copies : ");
    book.SetTotalCopies(TotalCopies);
    book.SetAvailableCopies(TotalCopies);
    return true;
}

// Add new book screen
void clsAddNewBook::AddNewBookScreen() {
    PrintHeaderScreen("ADD BOOK SCREEN", "+📘", Colors::Blue);
    cout << "\n\n";
    // Read book ISBN
    string ISBN = _ReadISBN();
    // get add new book obj
    clsBook book = clsBook::GetAddNewBookObj(ISBN);
    // Read book data
    if (_ReadBookData(book)) {
        clsBook::enSaveMode Result = book.save();
        switch (Result) {
            case clsBook::enSaveMode::SaveSuccess: {
                // print new book record
                _PrintBookData(book);
                cout << Colors::GetGreen() << " + Book was Add succesfully ✓" << Colors::RESET() << endl;
                break;
            }
            case clsBook::enSaveMode::SaveFailed: {
                cout << Colors::GetRed() << " [ The Process was Failed ]" << Colors::RESET() << endl;
                break;
            }
            default:
                break;
        }

    } else {
        cout << Colors::GetRed() << " [ This Book is already exist, Try Again.. ]" << Colors::RESET() << endl;
    }
}
